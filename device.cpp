#include "device.h"
#include <Qstring>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QtSql/QtSql>


/* Default constructor anticipates the following format:
  deviceID, name, type, room, value, status */
Device::Device(QString devID, QString devName, QString devType, int parentRoom, int devValue, int devStatus, QDateTime updateTime)
{
    deviceID = devID;
    name = devName;
    type = devType;
    room = parentRoom;
    value = devValue;
    status = devStatus;
    lastUpdated = updateTime;

}
Device::Device(){

}

void Device::setDeviceID(QString devID){
    deviceID = devID;
}

QString Device::get_PLM_ID(QList<Device *> * deviceList){
    int num = deviceList->size();
    QString devID;
    for (int i = 0; i < num; ++i){
        if(deviceList->at(i)->type == "PLM")
           devID = deviceList->at(i)->deviceID;
    }
    return devID;
}

QString Device::getDeviceID(){
    return deviceID;
}


void Device::processTimeout()
{
    response.clear();
}
void Device::send(QByteArray &data, bool *status, int *devStatus){
    *status = true;
    if (serial.portName() != "COM3") {
        serial.close();
        serial.setPort("COM3");

        if (!serial.open(QIODevice::ReadWrite)) {
            processError(QObject::tr("Can't open %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            *status = false;
            return;
        }

        if (!serial.setBaudRate(QSerialPort::Baud19200)) {
            processError(QObject::tr("Can't set rate 19200 baud to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
            processError(QObject::tr("Can't set 8 data bits to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
            processError(QObject::tr("Can't set no patity to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
            processError(QObject::tr("Can't set 1 stop bit to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
            processError(QObject::tr("Can't set no flow control to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }
    }
    if(*status == true){
        int success = 0;
        int timeout = 0;
        QString serialStatus;
        serialStatus = QObject::tr("Status: Running, connected to port %1.")
                .arg("COM3");
        qDebug() << serialStatus;

        qDebug() << "Size of Data to write: " << data.length();

        /* Do not quit trying to send message until you receive success
         * acknowledgement. Success ACK = 0x06
         * if the message is not sent successfully in 6 tries, quit */
        while(success==0 && timeout <= 6){
            response.clear();
            qDebug() << "Trying to write: " << data.toHex();
            serial.write(data);
            serial.flush();
            serial.waitForReadyRead(450);
            response = serial.readAll();
            if( response.endsWith(0x15)){ //Negative Acknowledgement
                qDebug() << "Error - NACK: " <<response.toHex();
                timeout++;
            }
            else if( (response.endsWith(0x06)) ){ //Positive ACK received
                qDebug() << "Successful Send: " << response.toHex();
                success=1;
                qDebug() << "Found 21 @ " << response.indexOf(0x21);
                if( (response[response.indexOf(0x21)+2]==0xFF) && (response.indexOf(0x21)!=-1) ){
                    *devStatus = 1;
                    qDebug() << "Light is currently ON";
                }
                else if( (response[response.indexOf(0x21)+2]==0x00) && (response.indexOf(0x21)!=-1) ){
                    *devStatus = 0;
                    qDebug() << "Light is currently OFF";
                }
            }else{
                qDebug() << "Error - Received: " <<response.toHex();
                timeout++;
            }
        }

        if(success==0){
            *status = false;
        }
        response.clear();

    }
}

void Device::send(QByteArray &data, bool *status)
{
    *status = true;
    if (serial.portName() != "COM3") {
        serial.close();
        serial.setPort("COM3");

        if (!serial.open(QIODevice::ReadWrite)) {
            processError(QObject::tr("Can't open %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            *status = false;
            return;
        }

        if (!serial.setBaudRate(QSerialPort::Baud19200)) {
            processError(QObject::tr("Can't set rate 19200 baud to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setDataBits(QSerialPort::Data8)) {
            processError(QObject::tr("Can't set 8 data bits to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setParity(QSerialPort::NoParity)) {
            processError(QObject::tr("Can't set no patity to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setStopBits(QSerialPort::OneStop)) {
            processError(QObject::tr("Can't set 1 stop bit to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }

        if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
            processError(QObject::tr("Can't set no flow control to port %1, error code %2")
                         .arg(serial.portName()).arg(serial.error()));
            return;
        }
    }
    if(*status == true){
        int success = 0;
        int timeout = 0;
        QString serialStatus;
        serialStatus = QObject::tr("Status: Running, connected to port %1.")
                .arg("COM3");
        qDebug() << serialStatus;

        qDebug() << "Size of Data to write: " << data.length();

        /* Do not quit trying to send message until you receive success
         * acknowledgement. Success ACK = 0x06
         * if the message is not sent successfully in 6 tries, quit */
        while(success==0 && timeout <= 6){
            response.clear();
            qDebug() << "Trying to write: " << data.toHex();
            serial.write(data);
            serial.flush();
            serial.waitForReadyRead(400);
            response = serial.readAll();
            if( (response.endsWith(0x06)) || (response[9]==data[0] && response[10]==data[1])){ //Positive ACK received
                qDebug() << "Successful Send: " << response.toHex();
                success=1;
            }else{
                qDebug() << "Error - Received: " <<response.toHex();
                timeout++;
            }
        }

        if(success==0){
            *status = false;
        }
        response.clear();

    }
}

void Device::read()
{
    //response.append(serial.readLine());
    //qDebug() << response.toHex();
    //response.clear();
}

void Device::processError(const QString &error)
{
    QString status = QObject::tr("Status: Not running, %1.").arg(error);
    qDebug() << status;
    QMessageBox msg;
    msg.setWindowTitle("Error Opening COM Port");
    msg.setInformativeText(status);
    msg.exec();
}

void Device::readWait(){
    serial.waitForReadyRead(400);
}


QDateTime Device::getUpdatedTime(QString devID){
    QSqlQuery query;
    QDateTime returnedTime;
    QString qryString = "SELECT stamp FROM tbl_device WHERE device_id='"+devID+"'";
    query.exec(qryString);
    while(query.next()){
        returnedTime.setTime(query.value(0).toTime());
        returnedTime.setDate(query.value(0).toDate());
        qDebug() << "Time result: " << returnedTime.time();
        qDebug() << "Date result: " << returnedTime.date();
    }
    return returnedTime;
}

void Device::check_updated(QList<Device *> * deviceList)
{
    QString deviceId, updatedQry;
    QSqlQuery query;
    QDateTime date;
    qDebug() << "Polling for changes...";
    for (int i=0; i<deviceList->size(); i++)
    {
        deviceId = deviceList->at(i)->deviceID;
        updatedQry = "SELECT stamp FROM tbl_device WHERE device_id='"+deviceId+"'";
        query.exec(updatedQry);
        while(query.next()){
            date.setTime(query.value(0).toTime());
            date.setDate(query.value(0).toDate());
            if(date > deviceList->at(i)->lastUpdated){
                qDebug() << deviceId << "has been modified";
                statusChanged(deviceList,i);
                deviceList->at(i)->lastUpdated = date;
            }
        }
        //qDebug() << deviceList->at(i)->deviceID << deviceList->at(i)->name << deviceList->at(i)->lastUpdated;
    }
}

void Device::currentStatus(QList<Device *> * deviceList){
    QString devID, updateQry;
    int devStatus, updateStatus;
    updateStatus=0;
    QSqlQuery query;
    for(int i=0; i<deviceList->size(); i++){
        if(deviceList->at(i)->type == "Light"){
            devStatus = deviceList->at(i)->status;
            devID = deviceList->at(i)->deviceID;
            QByteArray msg;
            bool msgStatus;
            msg.resize(8);

            msg[0] = 0x02;
            msg[1] = 0x62;
            msg[2] = 0x00;
            msg[3] = 0x00;
            msg[4] = 0x00;
            msg[5] = 0x05;
            msg[6] = 0x19;
            msg[7] = 0x00;
            msg.replace(2, 3, QByteArray::fromHex( devID.toLocal8Bit() ) );
            qDebug() << "Has device " << deviceList->at(i)->name << "Changed? Send: " << msg.toHex();
            send(msg,&msgStatus, &updateStatus);
            if(devStatus!=updateStatus){
                qDebug() << "Light Status is now: " << updateStatus;
            }
        }
    }
}

void Device::statusChanged(QList<Device *> * deviceList, int index){
    //qDebug() << "\nIt was observed that device: " << deviceList->at(index)->deviceID << " has been modified!";
    QSqlQuery query;
    int devStatus = deviceList->at(index)->status;
    int devValue = deviceList->at(index)->value;
    QString devType;
    QString devID;

    devID = deviceList->at(index)->deviceID;

    QString queryStr = "SELECT device_type, status, device_value FROM tbl_device WHERE device_id='"+devID+"'";
    bool dbStatus = query.exec(queryStr);
    if(dbStatus){
        while(query.next()){
            devType=query.value(0).toString();
            devStatus=query.value(1).toInt();
            devValue=query.value(2).toInt();
        }


        /* Determine Action to take */
        if( devType == "Light"){
            qDebug() << "Light Switch should be modified";
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    qDebug() << "Turn Light on";
                    light_on(deviceList,index);
                    break;
                case 0:
                    qDebug() << "Turn light off";
                    light_off(deviceList,index);
                    break;
                default:
                    qDebug() << "Error: unknown action to be taken!";
                    break;
                }
            }
        } else if( devType == "Door Lock" ){
            //qDebug() << "Door lock action";
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    //qDebug() << "Lock the door";
                    door_lock(deviceList,index);
                    break;
                case 0:
                    //qDebug() << "Unlock the door";
                    door_unlock(deviceList,index);
                    break;
                default:
                    qDebug() << "Error: unknown action to be taken!";
                    break;
                }
            }
        } else if( devType == "Thermostat"){
            //qDebug() << "Thermostat action";
            /* Determine if the device should be turned on or off */
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    //qDebug() << "Turn thermostat on";
                    thermostat_on(deviceList,index);
                    break;
                case 0:
                    //qDebug() << "Turn thermostat off";
                    thermostat_off(deviceList,index);
                    break;
                default:
                    qDebug() << "Error: unknown action to be taken!";
                    break;
                }
            }

            /*Determine if the device value should be modified */
            if(devValue != deviceList->at(index)->value){
                thermostat_value(deviceList,index,devValue);
            }
        } else{
            qDebug() << "No action to be taken";
        }
    }else{
        qDebug() << "There was an error in the status Query in Device::StatusChanged";
    }
}

/* Function to handle cases when serial action to update device fails */
void Device::serialFailed(QString devID, int status){
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


/* Functions for device action */
void Device::light_on(QList<Device *> * deviceList, int index){
    //Turn light on

    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
    bool msgStatus;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x00;
    msg[3] = 0x00;
    msg[4] = 0x00;
    msg[5] = 0x15;
    msg[6] = 0x11;
    msg[7] = 0xFF;
    msg.replace(2, 3, QByteArray::fromHex( devID.toLocal8Bit() ) );
    qDebug() << "Send: " << msg.toHex();
    send(msg,&msgStatus);
    if(msgStatus==true){
        deviceList->at(index)->status=1;
    } else{
        serialFailed(devID,0);
        deviceList->at(index)->status=0;
    }

}

void Device::light_off(QList<Device *> * deviceList, int index){
    //turn light off

    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
    bool msgStatus;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x00;
    msg[3] = 0x00;
    msg[4] = 0x00;
    msg[5] = 0x15;
    msg[6] = 0x13;
    msg[7] = 0x00;
    msg.replace(2, 3, QByteArray::fromHex( devID.toLocal8Bit() ) );
    qDebug() << "Send: " << msg.toHex();
    send(msg,&msgStatus);
    if(msgStatus==true){
        deviceList->at(index)->status=0;
    } else{
        serialFailed(devID,1);
        deviceList->at(index)->status=1;
    }
}

void Device::door_lock(QList<Device *> * deviceList, int index){
    //Lock Door
    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
    bool msgStatus;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x00;
    msg[3] = 0x00;
    msg[4] = 0x00;
    msg[5] = 0x0F;
    msg[6] = 0x11;
    msg[7] = 0x00;
    msg.replace(2, 3, QByteArray::fromHex( devID.toLocal8Bit() ) );
    qDebug() << "Send: " << msg.toHex();
    send(msg,&msgStatus);

    if(msgStatus==true){
        deviceList->at(index)->status=1;
    } else{
        serialFailed(devID,0);
        deviceList->at(index)->status=0;
    }

}

void Device::door_unlock(QList<Device *> * deviceList, int index){
    //Unlock Door
    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
    bool msgStatus;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x00;
    msg[3] = 0x00;
    msg[4] = 0x00;
    msg[5] = 0x0F;
    msg[6] = 0x11;
    msg[7] = 0xFF;
    msg.replace(2, 3, QByteArray::fromHex( devID.toLocal8Bit() ) );
    qDebug() << "Send: " << msg.toHex();
    send(msg,&msgStatus);
    if(msgStatus==true){
        deviceList->at(index)->status=0;
    } else{
        serialFailed(devID,0);
        deviceList->at(index)->status=1;
    }
}

void Device::thermostat_on(QList<Device *> * deviceList, int index){
    qDebug() << "Turn Thermostat on";

    //turn thermostat on
    deviceList->at(index)->status=1;
}

void Device::thermostat_off(QList<Device *> * deviceList, int index){
    qDebug() << "Turn Thermostat off";
        //turn thermostat off
    deviceList->at(index)->status=0;
}

void Device::thermostat_value(QList<Device *> * deviceList, int index, int newValue){
    qDebug() << "Adjust thermostat value to: " << newValue;
        //adjust thermostat value
    deviceList->at(index)->value=newValue;
}

