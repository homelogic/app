#ifndef SERIALCOMM_H
#define SERIALCOMM_H

#include <QObject>
#include <QtSerialPort/qserialport.h>
#include <QTimer>

class SerialComm : public QObject
{
    Q_OBJECT

public:
    SerialComm();
    void serialFailed(QString devID, int status);
    void writeNextQueue();
    void processSerialError(const QString &error);

signals:
    void devstatusResponse(const QByteArray &msg);
    void statusUpdate(const QString update);

public slots:
    void processTimeout();
    void handleResponse();
    void writeSerial(const QByteArray &msg);

private:
    QByteArray response;
    QByteArray msgRequest;
    QByteArray msgQueue;
    QSerialPort serial;
    QTimer serialTimer;
    bool no_data;
    
};

#endif // SERIALCOMM_H
