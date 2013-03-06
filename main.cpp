#include <QApplication>
#include "mainwindow.h"
#include "device.h"
#include <QDebug>
#include <QString>
#include <QObject>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.addLibraryPath( a.applicationDirPath() + "/plugins");
    w.load_device_defaults();
    w.load_device_list();
    w.timer_start();    
    w.show();

    QByteArray x;
    x.resize(2);
    x[0] = 0x01;
    x[1] = 0x2A;

    int num = 0;
    num |= x[0];
    num << 8;
    num |= x[1];
    num << 8;
    qDebug() << "num = " << num;

    return a.exec();
}
