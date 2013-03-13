#include "room.h"
#include <QtSql/QtSql>
#include <QDebug>

//Room characteristics
int roomID;
QString roomName;
int occupancy;

//Room Actions
int actionID;
int Lon_UserL_Loff; //If Light On and Room Empty - Turn Light off?
int Loff_UserE_Lon; //If Light off and Room has occupancy - Turn light on?
int UserL_Loff; //If all users leave - Lights off?
int UserL_Lock; //If all users leave - Lock doors?

Room::Room(int room_id, QString room_name, int num, int action, int action1, int action2, int action3, int action4){
    roomID = room_id;
    roomName = room_name;
    occupancy = num;
    actionID = action;
    Lon_UserL_Loff = action1;
    Loff_UserE_Lon = action2;
    UserL_Loff = action3;
    UserL_Lock = action4;

}

Room::Room(int room_id, QString room_name, int num){
    roomID = room_id;
    roomName = room_name;
    occupancy = num;
}

Room::Room(){
    roomID = 0;
    roomName = "";
    occupancy = 0;
    occupied = false;
}

void Room::load_room_list(){
    QSqlQuery query, query2;
    QString qryString, qryString2;
    QString room_name;
    int room_id, num, action, action1, action2, action3, action4;
    bool qryResult;

    qryString = "SELECT room_id, room_name, occupancy FROM tbl_rooms";
    qryResult = query.exec(qryString);
    if(!qryResult){
        qDebug() << "MySQL query error in MainWindow::load_room_list - Loading rooms";
    } else{
        while(query.next()){
            room_id = query.value(0).toInt();
            room_name = query.value(1).toString();
            num = query.value(2).toInt();
            if(num>0){
                occupied = true;
            }
            qryString2 = tr("SELECT action_id, Lon_UserL_Loff, Loff_UserE_Lon, UserL_Loff, UserL_Lock FROM tbl_actions WHERE room_id=%1").arg(room_id);
            qryResult = query2.exec(qryString2);
            if(!qryResult){
                qDebug() << "MySQL query error in MainWindow::load_room_list - Loading actions";
            } else{
                while(query2.next()){
                    action = query2.value(0).toInt();
                    action1 = query2.value(1).toInt();
                    action2 = query2.value(2).toInt();
                    action3 = query2.value(3).toInt();
                    action4 = query2.value(4).toInt();
                    rooms.append(new Room(room_id,room_name,num,action,action1,action2,action3,action4));
                }
            }
        }
    }
    for(int i=0; i<rooms.size();i++){
        qDebug() << tr("Room: %1 - %2:%3").arg(rooms.at(i)->roomName).arg(rooms.at(i)->roomID).arg(rooms.at(i)->occupancy);
    }
}

void Room::check_location(){
    QSqlQuery query;
    QString queryStr;
    int cnt=0, totalCnt=0;
    bool qryResult;
    for(int i=0; i< rooms.size(); i++){
        queryStr = tr("SELECT occupancy FROM tbl_rooms WHERE room_id=%1").arg(rooms.at(i)->roomID);
        qryResult = query.exec(queryStr);
        if(qryResult){
            while(query.next()){
                cnt = query.value(0).toInt();
                totalCnt+=cnt;
                /* Determine State */
                if( (cnt > 0) && (rooms.at(i)->occupancy < 1) ){ //People have entered the room
                    occupied = true;
                    rooms.at(i)->occupancy = cnt;
                    update_room_populated(i);
                } else if( (cnt < 1) && (rooms.at(i)->occupancy > 0) ){
                    rooms.at(i)->occupancy = cnt;
                    update_room_vacant(i);
                }
            }
        }
    }
    if( (totalCnt == 0) && (occupied == true) ){
        /* House is now empty */

    }
}

void Room::update_room_populated(int index){
    int roomID;
    if(rooms.at(index)->Loff_UserE_Lon == 1){
        roomID = rooms.at(index)->roomID;
        emit lightsOn(roomID); //Turn on all lights in room
    }

}

void Room::update_room_vacant(int index){
    int roomID;
    if(rooms.at(index)->Lon_UserL_Loff == 1){
        roomID = rooms.at(index)->roomID;
        emit lightsOff(roomID); //Turn off all lights in room
    }
}

void Room::update_house_empty(){
    qDebug() << "House is now empty";
}
