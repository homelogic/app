#include <QApplication>
#include "mainwindow.h"
#include "device.h"
#include <QDebug>
#include <QString>
#include <QObject>
#include <QtSerialPort/qserialport.h>
#include <QtSerialPort/qserialportinfo.h>




QT_USE_NAMESPACE_SERIALPORT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.load_device_defaults();
    w.load_device_list();
    w.device_timer_start();
    w.show();


    return a.exec();
}
