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
    Device(QString, QString, QString, int, int, int, QDateTime);
    Device();

    QDateTime getUpdatedTime(QString devID);
    void setupList (QList<Device *> * devices);
    void check_updated();
    void currentStatus();
    void statusChanged(int index);


    /* Functions for device action */
    void light_on(int index);
    void light_off(int index);
    void door_lock(int index);
    void door_unlock(int index);
    void thermostat_on(int index);
    void thermostat_off(int index);
    void thermostat_value(int index, int newValue);

private slots:
    void handleDeviceStatus(const QByteArray &response);

signals:
    void writeRequest(const QByteArray &msg);

private:
    QString name;   //name of device
    QString type;   //Type of device
    QString deviceID;   //Device ID
    int room;       //Parent room ID
    int value;      //Setting value (Thermostat = 71 Degrees)
    int status;     //1:On 0:Off
    QDateTime lastUpdated; //Time from MySQL DB

    QList<Device *> * deviceList;
    SerialComm serial;

};

#endif // DEVICE_H
