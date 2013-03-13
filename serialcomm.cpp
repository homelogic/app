#include "serialcomm.h"
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/qserialport.h>
#include <QMessageBox>
#include <QtSql/QtSql>

QT_USE_NAMESPACE

SerialComm::SerialComm(){
    no_data = true;
    timeoutCnt = 0;
    serialTimer.setSingleShot(true);

    QObject::connect(&serial, SIGNAL(readyRead()),
                     this, SLOT(handleResponse()));
    QObject::connect(&serialTimer, SIGNAL(timeout()),
                     this, SLOT(processTimeout()));

}

void SerialComm::writeSerial(const QByteArray &msg){
    if (serial.portName() != "COM3") {
        serial.close();
        serial.setPortName("COM3");
        serial.open(QIODevice::ReadWrite);

        if (!serial.isOpen()) {
            processSerialError(tr("Can't open %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setBaudRate(QSerialPort::Baud19200)) {
            processSerialError(tr("Can't set rate 19200 baud to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
            processSerialError(tr("Can't set 8 data bits to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
            processSerialError(tr("Can't set no patity to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
            processSerialError(tr("Can't set 1 stop bit to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
            processSerialError(tr("Can't set no flow control to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }
    }

    if(!no_data){
        msgQueue.append(msg);
    }
    else{
        serial.write(msg);
        qDebug() << "Write: " << msg.toHex();
        no_data=false;
    }
}


void SerialComm::writeNextQueue(){
    int size = msgQueue.length();
    msgRequest = msgQueue.left(8);
    msgQueue = msgQueue.mid(8,(size-8));
    serial.write(msgRequest);
    qDebug() << "Write: " << msgRequest.toHex();
    no_data=false;
}


void SerialComm::handleResponse(){
    QString updateMsg;
    response.append(serial.readAll());
    static int state = 0;
    int msgSize = response.length();
    if(msgSize<9)
        state = 0; //not ready
    else if(response.at(8)==0x15 || response.endsWith(0x15))
        state = 1;
    else if( (response.endsWith(0xFF) || response.endsWith(QByteArray(0x00))) && response.contains(0x21))
        state = 4;
    else if(response.at(8)==(0x06) && response.at(6)==0x19)
        state = 3;
    else if(response.at(8)==(0x06))
        state = 2;
    else
        state = 0;

    switch(state){
    case 0:
        serialTimer.start(500);
        //Not ready - do nothing, wait for more bytes.
        break;

    case 1: //NACK
        serialTimer.stop();
        updateMsg = tr("NACK: %1").arg(QString(response.toHex()));
        emit statusUpdate(updateMsg);
        //qDebug() << "NACK: " << response.toHex();
        response.clear();
        serial.write(msgRequest); //write again
        break;

    case 2: //ACK
        serialTimer.stop();
        updateMsg = tr("Read: %1").arg(QString(response.toHex()));
        emit statusUpdate(updateMsg);
        //qDebug() << "Read: " << response.toHex();
        response.clear();
        if(msgQueue.length() > 0)
            writeNextQueue();
        else
            no_data=true;
        break;

    case 3: //ACK of Dev Status
        serialTimer.start(500);
        //Wait for the rest of Device Status
        break;

    case 4: //Status
        serialTimer.stop();
        //qDebug() << "Device Status Read: " << response.toHex();
        if(msgQueue.length() > 0)
            this->writeNextQueue();
        else
            no_data=true;

        emit devstatusResponse(response);
        response.clear();
        break;

    default:
        //Do Nothing
        break;
    }

}

void SerialComm::processTimeout(){
    qDebug() << "Timeout";
    timeoutCnt++;
    if(timeoutCnt > 1){
        response.clear();
        if(msgQueue.length() > 0)
            this->writeNextQueue();
        else
            no_data=true;
        timeoutCnt = 0;
    } else{
        serial.write(msgRequest);
    }
}


void SerialComm::processSerialError(const QString &error)
{
    QString status = QObject::tr("Status: Not running, %1.").arg(error);
    qDebug() << status;
    QMessageBox msg;
    msg.setWindowTitle("Error Opening COM Port");
    msg.setInformativeText(status);
    msg.exec();
    exit(1);
}


/* Function to handle cases when serial action to update device fails */
void SerialComm::serialFailed(QString devID, int status){
    QMessageBox msg;
    QSqlQuery query;
    QString updateStr = QString("UPDATE tbl_device SET status=%1 WHERE device_id='%2'").arg(status).arg(devID);
    qDebug() << "Failed update string: " << updateStr;
    bool dbStatus = query.exec(updateStr);
    if(dbStatus!=true){
        msg.setInformativeText("The device failed to update status & db update operation failed. You should reboot the system");
    }
    else{
        msg.setInformativeText("The device failed to update, the status has been reverted in the database!");
    }
    msg.exec();
}
