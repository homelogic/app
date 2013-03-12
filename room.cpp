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
}


void Room::load_room_list(){
    QSqlQuery query;
    QString qryString;
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

            qryString = tr("SELECT action_id, Lon_UserL_Loff, Loff_UserE_Lon, UserL_Loff, UserL_Lock FROM tbl_actions WHERE room_id=%1").arg(room_id);
            qryResult = query.exec(qryString);
            if(!qryResult){
                qDebug() << "MySQL query error in MainWindow::load_room_list - Loading actions";
            } else{
                while(query.next()){
                    action = query.value(0).toInt();
                    action1 = query.value(1).toInt();
                    action2 = query.value(2).toInt();
                    action3 = query.value(3).toInt();
                    action4 = query.value(4).toInt();
                    rooms.append(new Room(room_id,room_name,num,action,action1,action2,action3,action4));
                }
            }
        }
    }
    for(int i=0; i<rooms.size();i++){
        qDebug() << tr("Room: %1 - %2:%3").arg(rooms.at(i)->roomName).arg(rooms.at(i)->roomID).arg(rooms.at(i)->occupancy);
    }
}
