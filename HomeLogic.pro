#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T19:54:01
#
#-------------------------------------------------

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}
QT += core gui sql


TARGET = HomeLogic
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    device.cpp

HEADERS  += mainwindow.h \
    device.h \
    defaults.h

FORMS    += mainwindow.ui
