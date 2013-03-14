#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include "device.h"

class Room : public QObject
{
    Q_OBJECT
public:
    Room(int, QString, int, int, int, int, int, int);
    Room(int, QString, int);
    Room();

    void load_room_list();
    void update_room_populated(int index);
    void update_room_vacant(int index);
    void update_house_empty();

private slots:
    void check_location();

signals:
    void lightsOff(int roomID);
    void lightsOn(int roomID);
    void doorLock(int roomID);

private:
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

    QList<Room *> rooms;
    bool occupied; //flag to determine current state of house
    
};

#endif // ROOM_H
