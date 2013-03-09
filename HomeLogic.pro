QT       += widgets serialport core gui sql



TARGET = HomeLogic
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    device.cpp \
    serialcomm.cpp

HEADERS  += mainwindow.h \
    device.h \
    defaults.h \
    serialcomm.h

FORMS    += mainwindow.ui
