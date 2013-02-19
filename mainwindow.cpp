
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <stdio.h>
#include <QtDebug>
#include <QMessageBox>
#include "device.h"
#include <QList>
#include "defaults.h"
#include <QtSql/QtSql>
#include <QtSerialPort/qserialport.h>
#include <QDateTime>



QT_USE_NAMESPACE_SERIALPORT

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("Home Logic Control Panel[*]"));
    db = QSqlDatabase::addDatabase(DB_DRIVER);
    db.setDatabaseName(DB_DBNAME);
    db.setHostName(DB_HOST);
    db.setUserName(DB_USER);
    db.setPassword(DB_PASSWD);
    dbSuccess = db.open();
    /* Handle errors when database does not open */
    if (dbSuccess == false){
        QMessageBox msg;
        msg.setText("Error openning database");
        QSqlError err = db.lastError ();
        QString s_err("The database reported an error: ");
        s_err.append(err.databaseText());
        msg.setInformativeText(s_err);
     int ret = msg.exec();
     if (!ret){
         qDebug() << "Datbase connect error message not displayed.";
     }
    }

}
MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::device_timer_start(){
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(device_timer_timeout()));
    timer->start(DEVICE_QUERY_WAIT);
}

void MainWindow::device_timer_timeout(){
    //qDebug() << "\nTimeout Received";
    myDevice.check_updated(&devices);
}

void MainWindow::load_device_defaults(){

    QString deviceName, deviceIdentifier, roomName;
    int roomID;
    bool dbResult;
    if(dbSuccess){
        QSqlQuery query;
        //qWarning("We made it into the DB");
        dbResult = query.exec("SELECT device_name, device_id FROM tbl_device");
        while (query.next() && dbResult ){
            deviceName = query.value(0).toString();
            deviceIdentifier = query.value(1).toString();
            ui->deviceSelect->addItem(deviceName,deviceIdentifier);
            //qDebug() << "Insert: " << deviceIdentifier; //Display device ID added to comboBox
        }
        dbResult = query.exec("SELECT room_name, room_id FROM tbl_rooms");
        while (query.next() && dbResult ){
            roomName = query.value(0).toString();
            roomID = query.value(1).toInt();
            ui->deviceRoomSelect->addItem(roomName,roomID);
            ui->roomSelect->addItem(roomName,roomID);
            //qDebug() << "Insert: " << roomID; //Display room ID added to comboBox
        }

    }
    else if(dbSuccess == false){
        qWarning("Database failed to load!");
    }

    /* Configure the device status combobox */
    ui->deviceStatusSelect->addItem("Off", 0);
    ui->deviceStatusSelect->addItem("On", 1);
    /* Configure the device type combobox */
    ui->deviceTypeSelect->addItem("Light");
    ui->deviceTypeSelect->addItem("Door Lock");
    ui->deviceTypeSelect->addItem("Thermostat");
    ui->deviceTypeSelect->addItem("PLM");
    ui->deviceTypeSelect->addItem("Controller");

    ui->deviceSelect->setCurrentIndex(-1);
    ui->roomSelect->setCurrentIndex(-1);

}

/* Create list of all devices */
void MainWindow::load_device_list(){

    //myDevice.setDeviceID(arg1);
    QSqlQuery query;
    QString qryString;

    QString devID, devName, devType;
    int parentRoom, devValue, devStatus;
    QDateTime updated;
    bool qryResult;

    qryString = "SELECT device_id, room, device_name, device_type, status, device_value, stamp FROM tbl_device";
    qryResult = query.exec(qryString);
    if(qryResult == false){
        qDebug() << "SELECT Qry Failed - MainWindow::load_device_list\n";
    }
    while(query.next()){
        devID = query.value(0).toString();
        parentRoom = query.value(1).toInt();
        devName = query.value(2).toString();
        devType = query.value(3).toString();
        devStatus = query.value(4).toInt();
        devValue = query.value(5).toInt();
        updated.setTime(query.value(6).toTime());
        updated.setDate(query.value(6).toDate());

        devices.append(new Device(devID,devName,devType,parentRoom,devValue,devStatus,updated));
    }
}


/* Occurs when the user selects a different device name from the combo box
    this function should update all of the fields to reflect the new device. */
void MainWindow::on_deviceSelect_currentIndexChanged(int index)
{


    QString   currentDevice, deviceName, deviceType, queryString, roomName, deviceValue;
    int roomID =0, deviceStatus = -1;
    QSqlQuery query;

    /* To perform select query we need the device's ID. The current deviceID
     * is stored as the UserData for the combo box index. Get the userData for index 0
     * (currently selected device name). */
    currentDevice = ui->deviceSelect->itemData(index).toString();
    //qDebug() << "User Data: "<< currentDevice; //Outputs the deviceID of current index
    queryString = "SELECT device_name, room, device_type, status, device_value FROM tbl_device WHERE device_id='"+currentDevice+"'";
    bool result = query.exec(queryString); //Execute query
    while(query.next() && result ){
        deviceName = query.value(0).toString();
        roomID     = query.value(1).toInt();
        deviceType = query.value(2).toString();
        deviceStatus = query.value(3).toInt();
        deviceValue = query.value(4).toString();
    }
    if(result){ //execute if query was successful
        /* Use Room ID to get the actual name of the room */
        queryString = "SELECT room_name FROM tbl_rooms WHERE room_id=";
        queryString.append(QString("%1").arg(roomID));
        result = query.exec(queryString);
        while(query.next() && result){
            roomName = query.value(0).toString();
        }
        /* Populate the Form with device detail variables */
        ui->deviceID->setText(currentDevice);
        ui->deviceName->setText(deviceName);
        ui->deviceValue->setText(deviceValue);

        /* Using Device type name, set combobox */
         index = -1; //Initialize to -1, if no result the combobox will be set to blank
        index = ui->deviceTypeSelect->findText(deviceType);
        ui->deviceTypeSelect->setCurrentIndex(index);
        // qDebug() << "Find Text Index: " << index;
        /* Using the Room ID returned from the query we need to set the
         * room select combobox for the device. Find the index for the room
         * name and then set the combobox to the index. */
        //index = -1;
        index = ui->deviceRoomSelect->findData(roomID,int(Qt::UserRole));
        ui->deviceRoomSelect->setCurrentIndex(index);


        /* Set the device Status */
        if(deviceStatus == 1){
            index = ui->deviceStatusSelect->findData(deviceStatus,int(Qt::UserRole));
            ui->deviceStatusSelect->setCurrentIndex(index);
        } else if(deviceStatus == 0){
            index = ui->deviceStatusSelect->findData(deviceStatus,int(Qt::UserRole));
            ui->deviceStatusSelect->setCurrentIndex(index);
        } else{
            //qDebug() << "Unknown Device Status: " << deviceStatus;
        }
    } //End If(Result True) Block
    else{
        QMessageBox msg;
        msg.setText("Unsuccessful query in device Status change!");
    }
}

/*User clicked Add Device - Clear all fields for new Device */
void MainWindow::on_newDevice_clicked()
{
    ui->deviceID->setText("");
    ui->deviceRoomSelect->setCurrentIndex(-1);
    ui->deviceSelect->setCurrentIndex(-1);
    ui->deviceTypeSelect->setCurrentIndex(-1);
    ui->deviceStatusSelect->setCurrentIndex(-1);
    ui->deviceValue->setText("");
    ui->deviceName->setText("");
}

/*User clicked to remove the device from the database */
void MainWindow::on_deviceRemoveButton_clicked()
{
    QString currentDevice = ui->deviceID->text(); //Remove device from combobox

    int index = ui->deviceSelect->findData(currentDevice,int(Qt::UserRole));
    ui->deviceSelect->removeItem(index);

    QString qryStr = "DELETE FROM tbl_device WHERE device_id='"+currentDevice+"'"; //execute delete query
    qDebug() << qryStr;
    QSqlQuery query;
    query.exec(qryStr);

    ui->deviceSelect->setCurrentIndex(-1); //Refresh GUI by setting device combobox to blank
}

/* User has clicked the save button. Save the device settings */
void MainWindow::on_deviceSaveButton_clicked()
{
    /* Get Current Device Setting Values*/
    QString currentDevice="", deviceValue="", deviceType="", deviceName="", deviceStatus="", deviceRoom="";
    int index;
    currentDevice = ui->deviceID->text(); //Get Device ID
    //qDebug() << "ID: " << currentDevice;
    deviceValue = ui->deviceValue->text();
    //qDebug() << "Value: " << deviceValue;
    deviceType = ui->deviceTypeSelect->currentText();
    //qDebug() << "Type: " << deviceType;
    deviceName = ui->deviceName->text();
    //qDebug() << "Name: " << deviceName;
    index= ui->deviceRoomSelect->currentIndex();
    deviceRoom = ui->deviceRoomSelect->itemData(index).toString();
    //qDebug() << "Room ID: " << deviceRoom;
    index= ui->deviceStatusSelect->currentIndex();
    deviceStatus = ui->deviceStatusSelect->itemData(index).toString();
    //qDebug() << "Status: " << deviceStatus;

    QSqlQuery query;
    bool result, updateFlag=FALSE;
    QString updateQry = "UPDATE tbl_device SET room="+deviceRoom+", device_name='"+deviceName+"', device_type='"+deviceType+"', status="+deviceStatus+", device_value="+deviceValue+" WHERE device_id='"+currentDevice+"'";
    QString insertQry = "INSERT INTO tbl_device(device_id, room, device_name, device_type, status, device_value) VALUES('"+currentDevice+"', "+deviceRoom+", '"+deviceName+"', '"+deviceType+"', "+deviceStatus+", "+deviceValue+")";
    qDebug() << updateQry;
    /* Check if the device already exists in the database. If it does, perform update
     * else perform insert */
    QString existQry = "SELECT device_name FROM tbl_device WHERE device_id='"+currentDevice+"'";
    //qDebug() << existQry;
    result = query.exec(existQry);
    if (result && query.next()){
        //qDebug() << "Device Exists (Name): " << query.value(0).toString();
        updateFlag = TRUE;
    }
    else{
        //qDebug() << "Device Exists Query Failed";
        updateFlag = FALSE;
    }
    qDebug() << "Update Flag: " << updateFlag;

    /* Run Update Query */
    if(updateFlag){
        QMessageBox msg;
        msg.setText("You are about to run an update Query");
        msg.exec();
        result = query.exec(updateQry);
        /*Refresh device combobox */
        if(result){
            int index = ui->deviceSelect->currentIndex();
            ui->deviceSelect->removeItem(index);
            ui->deviceSelect->addItem(deviceName,currentDevice);
            ui->deviceSelect->setCurrentIndex(-1);
            //qDebug() << "update result " << result;
        } else{
            qDebug() << "Update Error!";
        }

    } else{ //Run Insert Query
        if( (currentDevice=="") || (deviceName=="") || (deviceRoom=="") || (deviceStatus=="") || (deviceType=="") || (deviceValue=="") ){
            QMessageBox msg;
            msg.setText("Missing data");
            msg.exec();
        }
        else{
            result = query.exec(insertQry);
            if(result){
                ui->deviceSelect->setCurrentIndex(-1);
                ui->deviceSelect->addItem(deviceName,currentDevice);
                //qDebug() << "insert result " << result;

                /*Add device to Device list*/
                QDateTime updated;
                bool dbStatus;
                QString stampQry = "SELECT stamp FROM tbl_device WHERE device_id='"+currentDevice+"'";
                dbStatus = query.exec(stampQry);
                if(dbStatus){
                    while(query.next()){
                        updated.setDate(query.value(0).toDate());
                        updated.setTime(query.value(0).toTime());
                    }
                    devices.append(new Device(currentDevice,deviceName,deviceType,deviceRoom.toInt(),deviceValue.toInt(),deviceStatus.toInt(),updated));
                    //myDevice.print_list(&devices);
                }
            } else{
                qDebug() << "insert error!";
            }
        }

    }
}

/*Room Selection Modified */
void MainWindow::on_roomSelect_currentIndexChanged()
{
    QString roomName = ui->roomSelect->currentText();
    ui->roomName->setText(roomName);
}

void MainWindow::on_saveRoom_clicked()
{
    QString currentRoom = ui->roomSelect->currentText();
    int index = ui->roomSelect->currentIndex();
    QString roomId = ui->roomSelect->itemData(index).toString();
    currentRoom = ui->roomName->text();

    QString updateQry = "UPDATE tbl_rooms SET room_name='"+currentRoom+"' WHERE room_id="+roomId;
    QString insertQry = "INSERT tbl_rooms (room_name) VALUES('"+currentRoom+"')";
    QString existQry = "SELECT room_name FROM tbl_rooms WHERE room_id="+roomId;

    QSqlQuery query;
    bool result = query.exec(existQry);
    /* If there is a record, result will be true */
    if(result){
        /* Record for roomID exists, perform update */
        result = query.exec(updateQry);
        /* Must update combobox for both device room select and just room selection*/

        /* Handle device room select sync */
        int device_index = ui->deviceRoomSelect->findData(roomId,int(Qt::UserRole));
        int device_curr_index = ui->deviceRoomSelect->currentIndex();
        ui->deviceRoomSelect->removeItem(device_index);
        ui->deviceRoomSelect->addItem(currentRoom,roomId);
        if(device_index == device_curr_index){
            device_index = ui->deviceRoomSelect->findData(roomId,int(Qt::UserRole));
            ui->deviceRoomSelect->setCurrentIndex(device_index);
        }
        /* Handle room sync */
        ui->roomSelect->removeItem(index);
        ui->roomSelect->addItem(currentRoom,roomId);
        index = ui->roomSelect->findText(currentRoom);
        ui->roomSelect->setCurrentIndex(index);
    } else{
        /* Record for roomID does not exist, perform insert */
        result = query.exec(insertQry);
        /* need to add new device to combobox, must have its device id*/
        if(result){
            int newRoomId = 0;
            QString maxIdQry = "SELECT max(room_id) FROM tbl_rooms";
            query.exec(maxIdQry);
            while( query.next()){
                newRoomId  = query.value(0).toInt();
                ui->roomSelect->addItem(currentRoom,newRoomId);
                ui->deviceRoomSelect->addItem(currentRoom,newRoomId);
                index = ui->roomSelect->findData(newRoomId,int(Qt::UserRole));
                ui->roomSelect->setCurrentIndex(index);
            }
            /* Once Room is created, we need to add an entry to the Actions table */
            if(newRoomId != 0){
                QString actionEntryQry = tr( "INSERT INTO tbl_actions(room_id) VALUES(%1)").arg(newRoomId);
                query.exec(actionEntryQry);
            }
        }
    }
    //qDebug() << result;
}

/* Remove room from database */
void MainWindow::on_removeRoom_clicked()
{
    int index = ui->roomSelect->currentIndex(); //Get current index in combobox
    QString roomId = ui->roomSelect->itemData(index).toString();
    QString deleteQry = "DELETE FROM tbl_rooms WHERE room_id="+roomId;
    QSqlQuery query;

    /* You cannot delete a room if there are still devices assigned to the room
     * this violates the foreign key relationship established by the sql database */
    QString fkCheck = "SELECT device_id FROM tbl_device WHERE room ="+roomId; //fkCheck = Foreign Key Check
    query.exec(fkCheck);
    if(query.next()){
        /* Room still has devices assigned to it */
        QMessageBox msg;
        msg.setText("Cannot remove this room, there are device dependancies.");
        msg.exec();
    } else{
        query.exec(deleteQry);
        ui->roomSelect->removeItem(index); //remove from combobox
        ui->roomSelect->setCurrentIndex(0); //Change combobox position
    }
}

/* User Selected to add new device */
void MainWindow::on_newRoomButton_clicked()
{
    ui->roomSelect->setCurrentIndex(-1);
    ui->roomName->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    QByteArray msg;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x20;
    msg[3] = 0xCB;
    msg[4] = 0xCF;
    msg[5] = 0x15;
    msg[6] = 0x11;
    msg[7] = 0xFF;
    bool msgStatus;
    myDevice.send(msg,&msgStatus);
    myDevice.readWait();
    myDevice.read();
}

void MainWindow::change_updated(QString msg){
    ui->updatedWindow->setText(msg);
}

void MainWindow::on_pushButton_2_clicked()
{
    QByteArray msg;
    msg.resize(8);

    msg[0] = 0x02;
    msg[1] = 0x62;
    msg[2] = 0x20;
    msg[3] = 0xCB;
    msg[4] = 0xCF;
    msg[5] = 0x15;
    msg[6] = 0x13;
    msg[7] = 0x00;
    bool msgStatus;
    myDevice.send(msg,&msgStatus);
}
