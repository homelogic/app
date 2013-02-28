#ifndef DEVICE_H
#define DEVICE_H

#include <QString>
#include <QDateTime>
#include <QtSerialPort/qserialport.h>

class Device
{
public:
    /* Default constructor anticipates the following format:
      deviceID, name, type, room, value, status */
    Device(QString, QString, QString, int, int, int, QDateTime);
    Device();

    QString getDeviceID();
    QString get_PLM_ID(QList<Device *> * deviceList);
    void setDeviceID(QString devID);
    void readWait();
    QDateTime getUpdatedTime(QString devID);
    void check_updated(QList<Device *> * deviceList);
    void currentStatus(QList<Device *> * deviceList);
    void statusChanged(QList<Device *> * deviceList, int index);
    void serialFailed(QString devID, int status);
    void open_port();


    /* Functions for device action */
    void light_on(QList<Device *> * deviceList, int index);
    void light_off(QList<Device *> * deviceList, int index);
    void door_lock(QList<Device *> * deviceList, int index);
    void door_unlock(QList<Device *> * deviceList, int index);
    void thermostat_on(QList<Device *> * deviceList, int index);
    void thermostat_off(QList<Device *> * deviceList, int index);
    void thermostat_value(QList<Device *> * deviceList, int index, int newValue);

public slots:

    void send(QByteArray &data, bool *status);
    void send(QByteArray &data, bool *status, int *devStatus);
    void read();
    void processTimeout();
    void processError(const QString &error);


private:
    QString name;   //name of device
    QString type;   //Type of device
    QString deviceID;   //Device ID
    int room;       //Parent room ID
    int value;      //Setting value (Thermostat = 71 Degrees)
    int status;     //1:On 0:Off
    QDateTime lastUpdated; //Time from MySQL DB

    QByteArray response;
    QSerialPort serial;

};

#endif // DEVICE_H
