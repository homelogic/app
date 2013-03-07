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

    return a.exec();
}
