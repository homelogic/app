#ifndef DEVICE_H
#define DEVICE_H


#include <QDateTime>
#include <Qtimer>
#include <QThread>
#include <QtSerialPort/qserialport.h>

#include "serialthread.h"


class Device : public QThread
{
    Q_OBJECT

public:
    /* Default constructor anticipates the following format:
      deviceID, name, type, room, value, status */
    Device(QString, QString, QString, int, int, int, QDateTime);
    Device();

    QDateTime getUpdatedTime(QString devID);
    void check_updated(QList<Device *> * deviceList);
    void currentStatus(QList<Device *> * deviceList);
    void statusChanged(QList<Device *> * deviceList, int index);
    void serialFailed(QString devID, int status);
    void open_port();
    void writeNextQueue();


    /* Functions for device action */
    void light_on(QList<Device *> * deviceList, int index);
    void light_off(QList<Device *> * deviceList, int index);
    void door_lock(QList<Device *> * deviceList, int index);
    void door_unlock(QList<Device *> * deviceList, int index);
    void thermostat_on(QList<Device *> * deviceList, int index);
    void thermostat_off(QList<Device *> * deviceList, int index);
    void thermostat_value(QList<Device *> * deviceList, int index, int newValue);
    void send(QByteArray &data, bool *status);
    void send(QByteArray &data, bool *status, int *devStatus);

private slots:
    void processTimeout();
    void processError(const QString &error);
    void handleResponse();
    void writeSerial(const QByteArray &msg);

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

    QByteArray response;
    QByteArray msgRequest;
    QByteArray msgQueue;
    QSerialPort serial;
    QTimer serialTimer;

    bool no_data;

};

#endif // DEVICE_H
