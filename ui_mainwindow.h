/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Feb 16 00:54:01 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSetup;
    QAction *actionMonitor;
    QWidget *centralWidget;
    QTabWidget *setupMonitorTabs;
    QWidget *setupTab;
    QWidget *layoutWidget;
    QHBoxLayout *setupLayout;
    QWidget *roomsWidget;
    QLabel *roomsLabel;
    QComboBox *roomSelect;
    QPushButton *newRoomButton;
    QWidget *layoutWidget1;
    QHBoxLayout *roomButton;
    QPushButton *saveRoom;
    QPushButton *removeRoom;
    QWidget *layoutWidget2;
    QVBoxLayout *roomNameLayout;
    QLabel *roomNameLabel;
    QLineEdit *roomName;
    QLabel *roomSelectLabel;
    QPushButton *pushButton;
    QWidget *deviceWidget;
    QLabel *deviceLabel;
    QLabel *deviceSelectLabel;
    QComboBox *deviceSelect;
    QPushButton *newDevice;
    QWidget *layoutWidget3;
    QHBoxLayout *DeviceSaveRemoveLayout;
    QPushButton *deviceSaveButton;
    QPushButton *deviceRemoveButton;
    QLineEdit *deviceName;
    QLabel *deviceNameLabel;
    QLabel *deviceTypeLabel;
    QLabel *deviceIDLabel;
    QLineEdit *deviceID;
    QLabel *roomLabel;
    QComboBox *deviceRoomSelect;
    QLabel *statusLabel;
    QComboBox *deviceStatusSelect;
    QLabel *valueLabel;
    QLineEdit *deviceValue;
    QComboBox *deviceTypeSelect;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(607, 345);
        actionSetup = new QAction(MainWindow);
        actionSetup->setObjectName(QString::fromUtf8("actionSetup"));
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName(QString::fromUtf8("actionMonitor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        setupMonitorTabs = new QTabWidget(centralWidget);
        setupMonitorTabs->setObjectName(QString::fromUtf8("setupMonitorTabs"));
        setupMonitorTabs->setEnabled(true);
        setupMonitorTabs->setGeometry(QRect(10, 20, 581, 311));
        setupTab = new QWidget();
        setupTab->setObjectName(QString::fromUtf8("setupTab"));
        layoutWidget = new QWidget(setupTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 271, 314));
        setupLayout = new QHBoxLayout(layoutWidget);
        setupLayout->setSpacing(6);
        setupLayout->setContentsMargins(11, 11, 11, 11);
        setupLayout->setObjectName(QString::fromUtf8("setupLayout"));
        setupLayout->setContentsMargins(0, 0, 0, 0);
        roomsWidget = new QWidget(layoutWidget);
        roomsWidget->setObjectName(QString::fromUtf8("roomsWidget"));
        roomsLabel = new QLabel(roomsWidget);
        roomsLabel->setObjectName(QString::fromUtf8("roomsLabel"));
        roomsLabel->setGeometry(QRect(0, 0, 271, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Calligraphy"));
        font.setPointSize(13);
        roomsLabel->setFont(font);
        roomsLabel->setAlignment(Qt::AlignCenter);
        roomSelect = new QComboBox(roomsWidget);
        roomSelect->setObjectName(QString::fromUtf8("roomSelect"));
        roomSelect->setGeometry(QRect(10, 35, 251, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Gisha"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        roomSelect->setFont(font1);
        roomSelect->setLayoutDirection(Qt::LeftToRight);
        roomSelect->setEditable(false);
        roomSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
        roomSelect->setIconSize(QSize(16, 16));
        newRoomButton = new QPushButton(roomsWidget);
        newRoomButton->setObjectName(QString::fromUtf8("newRoomButton"));
        newRoomButton->setGeometry(QRect(80, 240, 114, 32));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Gisha"));
        font2.setPointSize(10);
        newRoomButton->setFont(font2);
        layoutWidget1 = new QWidget(roomsWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 140, 251, 32));
        roomButton = new QHBoxLayout(layoutWidget1);
        roomButton->setSpacing(6);
        roomButton->setContentsMargins(11, 11, 11, 11);
        roomButton->setObjectName(QString::fromUtf8("roomButton"));
        roomButton->setContentsMargins(0, 0, 0, 0);
        saveRoom = new QPushButton(layoutWidget1);
        saveRoom->setObjectName(QString::fromUtf8("saveRoom"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Gisha"));
        font3.setPointSize(9);
        saveRoom->setFont(font3);

        roomButton->addWidget(saveRoom);

        removeRoom = new QPushButton(layoutWidget1);
        removeRoom->setObjectName(QString::fromUtf8("removeRoom"));
        removeRoom->setFont(font3);

        roomButton->addWidget(removeRoom);

        layoutWidget2 = new QWidget(roomsWidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 70, 191, 48));
        roomNameLayout = new QVBoxLayout(layoutWidget2);
        roomNameLayout->setSpacing(6);
        roomNameLayout->setContentsMargins(11, 11, 11, 11);
        roomNameLayout->setObjectName(QString::fromUtf8("roomNameLayout"));
        roomNameLayout->setContentsMargins(0, 0, 0, 0);
        roomNameLabel = new QLabel(layoutWidget2);
        roomNameLabel->setObjectName(QString::fromUtf8("roomNameLabel"));
        roomNameLabel->setFont(font3);
        roomNameLabel->setAlignment(Qt::AlignCenter);

        roomNameLayout->addWidget(roomNameLabel);

        roomName = new QLineEdit(layoutWidget2);
        roomName->setObjectName(QString::fromUtf8("roomName"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Gisha"));
        roomName->setFont(font4);

        roomNameLayout->addWidget(roomName);

        roomSelectLabel = new QLabel(roomsWidget);
        roomSelectLabel->setObjectName(QString::fromUtf8("roomSelectLabel"));
        roomSelectLabel->setGeometry(QRect(0, 11, 271, 31));
        roomSelectLabel->setFont(font2);
        roomSelectLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(roomsWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 180, 75, 23));

        setupLayout->addWidget(roomsWidget);

        deviceWidget = new QWidget(setupTab);
        deviceWidget->setObjectName(QString::fromUtf8("deviceWidget"));
        deviceWidget->setGeometry(QRect(290, 1, 280, 311));
        deviceLabel = new QLabel(deviceWidget);
        deviceLabel->setObjectName(QString::fromUtf8("deviceLabel"));
        deviceLabel->setGeometry(QRect(0, 0, 271, 16));
        deviceLabel->setFont(font);
        deviceLabel->setAlignment(Qt::AlignCenter);
        deviceSelectLabel = new QLabel(deviceWidget);
        deviceSelectLabel->setObjectName(QString::fromUtf8("deviceSelectLabel"));
        deviceSelectLabel->setGeometry(QRect(0, 11, 271, 31));
        deviceSelectLabel->setFont(font2);
        deviceSelectLabel->setAlignment(Qt::AlignCenter);
        deviceSelect = new QComboBox(deviceWidget);
        deviceSelect->setObjectName(QString::fromUtf8("deviceSelect"));
        deviceSelect->setGeometry(QRect(10, 35, 251, 20));
        deviceSelect->setFont(font4);
        deviceSelect->setFocusPolicy(Qt::WheelFocus);
        deviceSelect->setEditable(false);
        deviceSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
        newDevice = new QPushButton(deviceWidget);
        newDevice->setObjectName(QString::fromUtf8("newDevice"));
        newDevice->setGeometry(QRect(83, 240, 114, 32));
        newDevice->setFont(font2);
        layoutWidget3 = new QWidget(deviceWidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(35, 210, 211, 31));
        DeviceSaveRemoveLayout = new QHBoxLayout(layoutWidget3);
        DeviceSaveRemoveLayout->setSpacing(6);
        DeviceSaveRemoveLayout->setContentsMargins(11, 11, 11, 11);
        DeviceSaveRemoveLayout->setObjectName(QString::fromUtf8("DeviceSaveRemoveLayout"));
        DeviceSaveRemoveLayout->setContentsMargins(0, 0, 0, 0);
        deviceSaveButton = new QPushButton(layoutWidget3);
        deviceSaveButton->setObjectName(QString::fromUtf8("deviceSaveButton"));
        deviceSaveButton->setFont(font3);

        DeviceSaveRemoveLayout->addWidget(deviceSaveButton);

        deviceRemoveButton = new QPushButton(layoutWidget3);
        deviceRemoveButton->setObjectName(QString::fromUtf8("deviceRemoveButton"));
        deviceRemoveButton->setFont(font3);

        DeviceSaveRemoveLayout->addWidget(deviceRemoveButton);

        deviceName = new QLineEdit(deviceWidget);
        deviceName->setObjectName(QString::fromUtf8("deviceName"));
        deviceName->setGeometry(QRect(100, 65, 116, 20));
        deviceName->setFont(font4);
        deviceName->setMaxLength(32760);
        deviceNameLabel = new QLabel(deviceWidget);
        deviceNameLabel->setObjectName(QString::fromUtf8("deviceNameLabel"));
        deviceNameLabel->setGeometry(QRect(41, 65, 34, 20));
        deviceNameLabel->setFont(font3);
        deviceTypeLabel = new QLabel(deviceWidget);
        deviceTypeLabel->setObjectName(QString::fromUtf8("deviceTypeLabel"));
        deviceTypeLabel->setGeometry(QRect(41, 140, 34, 20));
        deviceTypeLabel->setFont(font3);
        deviceIDLabel = new QLabel(deviceWidget);
        deviceIDLabel->setObjectName(QString::fromUtf8("deviceIDLabel"));
        deviceIDLabel->setGeometry(QRect(41, 90, 52, 20));
        deviceIDLabel->setFont(font3);
        deviceID = new QLineEdit(deviceWidget);
        deviceID->setObjectName(QString::fromUtf8("deviceID"));
        deviceID->setGeometry(QRect(100, 90, 116, 20));
        deviceID->setFont(font4);
        roomLabel = new QLabel(deviceWidget);
        roomLabel->setObjectName(QString::fromUtf8("roomLabel"));
        roomLabel->setGeometry(QRect(41, 115, 34, 20));
        roomLabel->setFont(font3);
        deviceRoomSelect = new QComboBox(deviceWidget);
        deviceRoomSelect->setObjectName(QString::fromUtf8("deviceRoomSelect"));
        deviceRoomSelect->setEnabled(true);
        deviceRoomSelect->setGeometry(QRect(100, 115, 85, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deviceRoomSelect->sizePolicy().hasHeightForWidth());
        deviceRoomSelect->setSizePolicy(sizePolicy);
        deviceRoomSelect->setMinimumSize(QSize(69, 0));
        deviceRoomSelect->setFont(font4);
        statusLabel = new QLabel(deviceWidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(41, 165, 35, 20));
        statusLabel->setFont(font3);
        deviceStatusSelect = new QComboBox(deviceWidget);
        deviceStatusSelect->setObjectName(QString::fromUtf8("deviceStatusSelect"));
        deviceStatusSelect->setGeometry(QRect(100, 165, 60, 20));
        deviceStatusSelect->setFont(font4);
        valueLabel = new QLabel(deviceWidget);
        valueLabel->setObjectName(QString::fromUtf8("valueLabel"));
        valueLabel->setGeometry(QRect(41, 190, 50, 20));
        valueLabel->setFont(font3);
        deviceValue = new QLineEdit(deviceWidget);
        deviceValue->setObjectName(QString::fromUtf8("deviceValue"));
        deviceValue->setGeometry(QRect(100, 190, 69, 20));
        deviceIDLabel->raise();
        deviceID->raise();
        roomLabel->raise();
        deviceRoomSelect->raise();
        statusLabel->raise();
        deviceStatusSelect->raise();
        valueLabel->raise();
        deviceValue->raise();
        deviceName->raise();
        deviceNameLabel->raise();
        layoutWidget->raise();
        deviceLabel->raise();
        deviceSelectLabel->raise();
        deviceSelect->raise();
        newDevice->raise();
        deviceTypeLabel->raise();
        deviceTypeSelect = new QComboBox(setupTab);
        deviceTypeSelect->setObjectName(QString::fromUtf8("deviceTypeSelect"));
        deviceTypeSelect->setEnabled(true);
        deviceTypeSelect->setGeometry(QRect(390, 140, 85, 20));
        sizePolicy.setHeightForWidth(deviceTypeSelect->sizePolicy().hasHeightForWidth());
        deviceTypeSelect->setSizePolicy(sizePolicy);
        deviceTypeSelect->setMinimumSize(QSize(69, 0));
        deviceTypeSelect->setFont(font4);
        setupMonitorTabs->addTab(setupTab, QString());
        MainWindow->setCentralWidget(centralWidget);
#ifndef QT_NO_SHORTCUT
        deviceNameLabel->setBuddy(deviceName);
        deviceTypeLabel->setBuddy(deviceRoomSelect);
        deviceIDLabel->setBuddy(deviceID);
        roomLabel->setBuddy(deviceRoomSelect);
        statusLabel->setBuddy(deviceStatusSelect);
        valueLabel->setBuddy(deviceValue);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        setupMonitorTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSetup->setText(QApplication::translate("MainWindow", "Setup", 0, QApplication::UnicodeUTF8));
        actionMonitor->setText(QApplication::translate("MainWindow", "Monitor", 0, QApplication::UnicodeUTF8));
        roomsLabel->setText(QApplication::translate("MainWindow", "Rooms", 0, QApplication::UnicodeUTF8));
        newRoomButton->setText(QApplication::translate("MainWindow", "New Room", 0, QApplication::UnicodeUTF8));
        saveRoom->setText(QApplication::translate("MainWindow", "Save Room", 0, QApplication::UnicodeUTF8));
        removeRoom->setText(QApplication::translate("MainWindow", "Remove Room", 0, QApplication::UnicodeUTF8));
        roomNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        roomSelectLabel->setText(QApplication::translate("MainWindow", "Room Select", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        deviceLabel->setText(QApplication::translate("MainWindow", "Devices", 0, QApplication::UnicodeUTF8));
        deviceSelectLabel->setText(QApplication::translate("MainWindow", "Device Select", 0, QApplication::UnicodeUTF8));
        newDevice->setText(QApplication::translate("MainWindow", "New Device", 0, QApplication::UnicodeUTF8));
        deviceSaveButton->setText(QApplication::translate("MainWindow", "Save Device", 0, QApplication::UnicodeUTF8));
        deviceRemoveButton->setText(QApplication::translate("MainWindow", "Remove Device", 0, QApplication::UnicodeUTF8));
        deviceNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        deviceTypeLabel->setText(QApplication::translate("MainWindow", "Type:", 0, QApplication::UnicodeUTF8));
        deviceIDLabel->setText(QApplication::translate("MainWindow", "Device ID:", 0, QApplication::UnicodeUTF8));
        roomLabel->setText(QApplication::translate("MainWindow", "Room:", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("MainWindow", "Status:", 0, QApplication::UnicodeUTF8));
        valueLabel->setText(QApplication::translate("MainWindow", "Set Value:", 0, QApplication::UnicodeUTF8));
        setupMonitorTabs->setTabText(setupMonitorTabs->indexOf(setupTab), QApplication::translate("MainWindow", "Setup", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
