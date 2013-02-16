CONFIG += serialport
#-------------------------------------------------
#
# Project created by QtCreator 2013-01-14T19:54:01
#
#-------------------------------------------------

#QT += core gui webkit sql
QT += core gui sql serialport

QTPLUGIN += qsqlmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HomeLogic
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    device.cpp

HEADERS  += mainwindow.h \
    device.h \
    defaults.h

FORMS    += mainwindow.ui
