#ifndef ROOM_H
#define ROOM_H

#include <QObject>

class Room : public QObject
{
    Q_OBJECT
public:
    Room(int, QString, int, int, int, int, int, int);
    Room(int, QString, int);
    Room();

    void load_room_list();

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

    
};

#endif // ROOM_H
