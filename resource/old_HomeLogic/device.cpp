#include "device.h"
#include <Qstring>
#include <QDebug>
#include <QList>
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


void Device::read()
{
    response.append(serial.readLine());
    qDebug() << response.toHex();
    response.clear();
}

void Device::processTimeout()
{
    response.clear();
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
        QString serialStatus;
        serialStatus = QObject::tr("Status: Running, connected to port %1.")
                .arg("COM3");
        qDebug() << serialStatus;
        serial.write(data);
    }
}

void Device::processError(const QString &error)
{
    QString status = QObject::tr("Status: Not running, %1.").arg(error);
    qDebug() << status;
    qDebug() << "No Traffic";
}

void Device::readWait(){
    serial.waitForReadyRead(500);
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
    qDebug() << "Current Device List:";
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
        qDebug() << deviceList->at(i)->deviceID << deviceList->at(i)->name << deviceList->at(i)->lastUpdated;
    }
}

void Device::statusChanged(QList<Device *> * deviceList, int index){
    qDebug() << "\nIt was observed that device: " << deviceList->at(index)->deviceID << " has been modified!";
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
            //qDebug() << "Light Switch should be modified";
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    //qDebug() << "Turn Light on";
                    light_on(deviceList,index);
                    break;
                case 0:
                    //qDebug() << "Turn light off";
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


/* Functions for device action */
void Device::light_on(QList<Device *> * deviceList, int index){
    qDebug() << "Turn light on";
    QString plmID = get_PLM_ID(deviceList);
    qDebug() << "PLM ID: " << plmID;


    QByteArray msg;
    bool msgStatus;
    msg.resize(2);
    msg[0] = 0x02;
    msg[1] = 0x60;
    send(msg,&msgStatus);
    readWait();
    read();
    deviceList->at(index)->status=1;
}

void Device::light_off(QList<Device *> * deviceList, int index){
    qDebug() << "Turn light off";

        //turn light off
    deviceList->at(index)->status=0;
}

void Device::door_lock(QList<Device *> * deviceList, int index){
    qDebug() << "Lock Door";
        //lock door
    deviceList->at(index)->status=1;
}

void Device::door_unlock(QList<Device *> * deviceList, int index){
    qDebug() << "Unlock the Door";
        //unlock door
    deviceList->at(index)->status=0;
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

