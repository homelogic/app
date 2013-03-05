#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class serialThread : public QThread
{
    Q_OBJECT
public:
    serialThread(QObject *parent = 0);
    ~serialThread();

    void setupPort(const QString &portName, int waitTimeout, const QByteArray &msg);
    void run();
    
signals:
    void sendResponse(const QByteArray &response);
    void error(const QString &error);
    void timeout(const QString &timeout);

private:
    QString portName;
    QByteArray msg;
    int waitTimeout;
    QMutex mutex;
    QWaitCondition cond;
    bool quit;
};

#endif // SERIALTHREAD_H
