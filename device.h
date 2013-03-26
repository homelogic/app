#ifndef DEVICE_H
#define DEVICE_H


#include <QDateTime>
#include <QObject>
#include "serialcomm.h"


class Device : public QObject
{
    Q_OBJECT

public:
    /* Default constructor anticipates the following format:
      deviceID, name, type, room, value, status */
    Device(QString, QString, QString, int, int, int, int, QDateTime);
    Device();

    QDateTime getUpdatedTime(QString devID);
    void setupList (QList<Device *> * devices);
    void statusChanged(int index);


    /* Functions for device action */
    void light_on(int index);
    void light_off(int index);
    void door_lock(int index);
    void door_unlock(int index);
    void thermostat_on(int index);
    void thermostat_off(int index);
    void thermostat_value(int index, int newValue);

public slots:
    void currentTemperature();
    void check_updated();
    void currentStatus();

private slots:
    void handleDeviceStatus(const QByteArray &response);
    void handleTemperatureStatus(const QByteArray &response);
    void room_Lights_Off(int roomID);
    void room_Lights_On(int roomID);
    void room_Door_Lock(int roomID);


signals:
    void writeRequest(const QByteArray &msg);
    void statusUpdate(const QString update);

private:
    QString name;   //name of device
    QString type;   //Type of device
    QString deviceID;   //Device ID
    int room;       //Parent room ID
    int value;      //Setting value (Thermostat = 71 Degrees)
    int currTemp;   //Ambient Value
    int status;     //1:On 0:Off
    QDateTime lastUpdated; //Time from MySQL DB

    QList<Device *> * deviceList;
    SerialComm serial;

};

#endif // DEVICE_H
