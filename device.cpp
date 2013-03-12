#include "device.h"

#include <Qstring>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QtSql/QtSql>




QT_USE_NAMESPACE

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

    QObject::connect(this, SIGNAL(writeRequest(QByteArray)),
                     &serial, SLOT(writeSerial(QByteArray)));
    QObject::connect(&serial, SIGNAL(devstatusResponse(QByteArray)),
                     this, SLOT(handleDeviceStatus(QByteArray)));
}


void Device::setupList (QList<Device *> * devices){
    deviceList = devices;
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

void Device::check_updated()
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
                statusChanged(i);
                deviceList->at(i)->lastUpdated = date;
            }
        }
    }
}

void Device::currentStatus(){
    QString devID;
    for(int i=0; i<deviceList->size(); i++){
        if(deviceList->at(i)->type == "Light"){
            devID = deviceList->at(i)->deviceID;
            QByteArray msg;
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
            emit writeRequest(msg);
            }
        }
}

void Device::handleDeviceStatus(const QByteArray &response){
    int status;
    if(response.endsWith(0xFF)) //ON
        status = 1;
    else if(response.endsWith(QByteArray(0x00))) //OFF
        status = 0;
    else //Unknown
        status = -1;

    QString devID;
    devID = response.mid(2,3).toHex();
    devID = devID.toUpper();

    QString updateMsg;
    updateMsg = tr("Device %1 - Status: %2").arg(devID).arg(status);
    emit statusUpdate(updateMsg);

    for(int i=0;i<deviceList->size();i++){
        if(deviceList->at(i)->deviceID==devID){
            if(deviceList->at(i)->status==status){
                //Do Nothing
            } else{
                deviceList->at(i)->status=status;
                QSqlQuery query;
                QString updateStr = "UPDATE tbl_device SET status='"+QString::number(status)+"' WHERE device_id='"+devID+"'";
                deviceList->at(i)->status = status;
                //qDebug() << updateStr;
                bool dbStatus = query.exec(updateStr);
                if (dbStatus==false){
                    qDebug() << "Query error in device status update.";
                }
            }
        }

    }

}


void Device::statusChanged(int index){
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
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    light_on(index);
                    break;
                case 0:
                    light_off(index);
                    break;
                default:
                    qDebug() << "Error: unknown action to be taken!";
                    break;
                }
            }
        } else if( devType == "Door Lock" ){
            if(devStatus != deviceList->at(index)->status){
                switch(devStatus){
                case 1:
                    door_lock(index);
                    break;
                case 0:
                    door_unlock(index);
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
                    thermostat_on(index);
                    break;
                case 0:
                    //qDebug() << "Turn thermostat off";
                    thermostat_off(index);
                    break;
                default:
                    qDebug() << "Error: unknown action to be taken!";
                    break;
                }
            }

            /*Determine if the device value should be modified */
            if(devValue != deviceList->at(index)->value){
                thermostat_value(index,devValue);
            }
        } else{
            qDebug() << "No action to be taken";
        }
    }else{
        qDebug() << "There was an error in the status Query in Device::StatusChanged";
    }
}


/* Functions for device action */
void Device::light_on(int index){
    //Turn light on

    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
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
    emit writeRequest(msg);

}

void Device::light_off(int index){
    //turn light off

    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
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
    emit writeRequest(msg);
}

void Device::door_lock(int index){
    //Lock Door
    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
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
    emit writeRequest(msg);

}

void Device::door_unlock(int index){
    //Unlock Door
    QString devID = deviceList->at(index)->deviceID;

    QByteArray msg;
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
    emit writeRequest(msg);
}

void Device::thermostat_on(int index){
    qDebug() << "Turn Thermostat on";

    //turn thermostat on
    deviceList->at(index)->status=1;
}

void Device::thermostat_off(int index){
    qDebug() << "Turn Thermostat off";
        //turn thermostat off
    deviceList->at(index)->status=0;
}

void Device::thermostat_value(int index, int newValue){
    qDebug() << "Adjust thermostat value to: " << newValue;
        //adjust thermostat value
    deviceList->at(index)->value=newValue;
}

