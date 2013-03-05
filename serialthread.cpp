
#include <QtSerialPort/QSerialPort>
#include <QDebug>
#include <QTime>

#include "serialthread.h"

QT_USE_NAMESPACE

serialThread::serialThread(QObject *parent)
    : QThread(parent), waitTimeout(0), quit(false){
}

serialThread::~serialThread(){
    mutex.lock();
    quit=true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}

void serialThread::setupPort(const QString &portName, int waitTimeout, const QByteArray &msg){
    qDebug() << "Send Message " << msg.toHex();
    QMutexLocker locker(&mutex);
    this->portName = portName;
    this->waitTimeout = waitTimeout;
    this->msg = msg;
    if(!isRunning())
        start();
    else
        cond.wakeOne();
}

void serialThread::run(){
    bool currentPortNameChanged = false;
    qDebug() << "Thread executed";
    mutex.lock();
    QString currentPortName;
    if(currentPortName != portName){
        currentPortName = portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = waitTimeout;
    QByteArray sendMsg = msg;
    mutex.unlock();
    QSerialPort serial;

    while(!quit){
        if(currentPortNameChanged){
            serial.close();
            serial.setPortName("COM3");

            if (!serial.open(QIODevice::ReadWrite)) {
                emit error(tr("Can't open %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }

            if (!serial.setBaudRate(QSerialPort::Baud19200)) {
                emit error(tr("Can't set baud rate 9600 baud to port %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }

            if (!serial.setDataBits(QSerialPort::Data8)) {
                emit error(tr("Can't set 8 data bits to port %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }

            if (!serial.setParity(QSerialPort::NoParity)) {
                emit error(tr("Can't set no patity to port %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }

            if (!serial.setStopBits(QSerialPort::OneStop)) {
                emit error(tr("Can't set 1 stop bit to port %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }

            if (!serial.setFlowControl(QSerialPort::NoFlowControl)) {
                emit error(tr("Can't set no flow control to port %1, error code %2")
                           .arg(portName).arg(serial.error()));
                return;
            }
        }

        //write request
        serial.write(msg);
        if (serial.waitForBytesWritten(waitTimeout)) {
            //! [8] //! [10]
            // read response
            if (serial.waitForReadyRead(currentWaitTimeout)) {
                QByteArray responseData = serial.readAll();
                while (serial.waitForReadyRead(10)){
                    responseData += serial.readAll();
                }

                QByteArray response = responseData;
                //! [12]
                emit this->sendResponse(response);
                //! [10] //! [11] //! [12]
            } else {
                emit this->timeout(tr("Wait read response timeout %1")
                             .arg(QTime::currentTime().toString()));
            }
            //! [9] //! [11]
        } else {
            emit timeout(tr("Wait write request timeout %1")
                         .arg(QTime::currentTime().toString()));
        }
        mutex.lock();
        cond.wait(&mutex);
        if (currentPortName != portName) {
            currentPortName = portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = waitTimeout;
        sendMsg = msg;
        mutex.unlock();
    }
    serial.close();
}
