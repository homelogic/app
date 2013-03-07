/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QWidget *monitorTab;
    QTextBrowser *updatedWindow;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(607, 362);
        actionSetup = new QAction(MainWindow);
        actionSetup->setObjectName(QStringLiteral("actionSetup"));
        actionMonitor = new QAction(MainWindow);
        actionMonitor->setObjectName(QStringLiteral("actionMonitor"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(false);
        setupMonitorTabs = new QTabWidget(centralWidget);
        setupMonitorTabs->setObjectName(QStringLiteral("setupMonitorTabs"));
        setupMonitorTabs->setEnabled(true);
        setupMonitorTabs->setGeometry(QRect(10, 20, 581, 341));
        setupTab = new QWidget();
        setupTab->setObjectName(QStringLiteral("setupTab"));
        layoutWidget = new QWidget(setupTab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 271, 314));
        setupLayout = new QHBoxLayout(layoutWidget);
        setupLayout->setSpacing(6);
        setupLayout->setContentsMargins(11, 11, 11, 11);
        setupLayout->setObjectName(QStringLiteral("setupLayout"));
        setupLayout->setContentsMargins(0, 0, 0, 0);
        roomsWidget = new QWidget(layoutWidget);
        roomsWidget->setObjectName(QStringLiteral("roomsWidget"));
        roomsLabel = new QLabel(roomsWidget);
        roomsLabel->setObjectName(QStringLiteral("roomsLabel"));
        roomsLabel->setGeometry(QRect(0, 0, 271, 16));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Calligraphy"));
        font.setPointSize(13);
        roomsLabel->setFont(font);
        roomsLabel->setAlignment(Qt::AlignCenter);
        roomSelect = new QComboBox(roomsWidget);
        roomSelect->setObjectName(QStringLiteral("roomSelect"));
        roomSelect->setGeometry(QRect(10, 35, 251, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Gisha"));
        font1.setStyleStrategy(QFont::PreferAntialias);
        roomSelect->setFont(font1);
        roomSelect->setLayoutDirection(Qt::LeftToRight);
        roomSelect->setEditable(false);
        roomSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
        roomSelect->setIconSize(QSize(16, 16));
        newRoomButton = new QPushButton(roomsWidget);
        newRoomButton->setObjectName(QStringLiteral("newRoomButton"));
        newRoomButton->setGeometry(QRect(80, 240, 114, 32));
        QFont font2;
        font2.setFamily(QStringLiteral("Gisha"));
        font2.setPointSize(10);
        newRoomButton->setFont(font2);
        layoutWidget1 = new QWidget(roomsWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 140, 251, 32));
        roomButton = new QHBoxLayout(layoutWidget1);
        roomButton->setSpacing(6);
        roomButton->setContentsMargins(11, 11, 11, 11);
        roomButton->setObjectName(QStringLiteral("roomButton"));
        roomButton->setContentsMargins(0, 0, 0, 0);
        saveRoom = new QPushButton(layoutWidget1);
        saveRoom->setObjectName(QStringLiteral("saveRoom"));
        QFont font3;
        font3.setFamily(QStringLiteral("Gisha"));
        font3.setPointSize(9);
        saveRoom->setFont(font3);

        roomButton->addWidget(saveRoom);

        removeRoom = new QPushButton(layoutWidget1);
        removeRoom->setObjectName(QStringLiteral("removeRoom"));
        removeRoom->setFont(font3);

        roomButton->addWidget(removeRoom);

        layoutWidget2 = new QWidget(roomsWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(40, 70, 191, 48));
        roomNameLayout = new QVBoxLayout(layoutWidget2);
        roomNameLayout->setSpacing(6);
        roomNameLayout->setContentsMargins(11, 11, 11, 11);
        roomNameLayout->setObjectName(QStringLiteral("roomNameLayout"));
        roomNameLayout->setContentsMargins(0, 0, 0, 0);
        roomNameLabel = new QLabel(layoutWidget2);
        roomNameLabel->setObjectName(QStringLiteral("roomNameLabel"));
        roomNameLabel->setFont(font3);
        roomNameLabel->setAlignment(Qt::AlignCenter);

        roomNameLayout->addWidget(roomNameLabel);

        roomName = new QLineEdit(layoutWidget2);
        roomName->setObjectName(QStringLiteral("roomName"));
        QFont font4;
        font4.setFamily(QStringLiteral("Gisha"));
        roomName->setFont(font4);

        roomNameLayout->addWidget(roomName);

        roomSelectLabel = new QLabel(roomsWidget);
        roomSelectLabel->setObjectName(QStringLiteral("roomSelectLabel"));
        roomSelectLabel->setGeometry(QRect(0, 11, 271, 31));
        roomSelectLabel->setFont(font2);
        roomSelectLabel->setAlignment(Qt::AlignCenter);

        setupLayout->addWidget(roomsWidget);

        deviceWidget = new QWidget(setupTab);
        deviceWidget->setObjectName(QStringLiteral("deviceWidget"));
        deviceWidget->setGeometry(QRect(290, 1, 280, 311));
        deviceLabel = new QLabel(deviceWidget);
        deviceLabel->setObjectName(QStringLiteral("deviceLabel"));
        deviceLabel->setGeometry(QRect(0, 0, 271, 16));
        deviceLabel->setFont(font);
        deviceLabel->setAlignment(Qt::AlignCenter);
        deviceSelectLabel = new QLabel(deviceWidget);
        deviceSelectLabel->setObjectName(QStringLiteral("deviceSelectLabel"));
        deviceSelectLabel->setGeometry(QRect(0, 11, 271, 31));
        deviceSelectLabel->setFont(font2);
        deviceSelectLabel->setAlignment(Qt::AlignCenter);
        deviceSelect = new QComboBox(deviceWidget);
        deviceSelect->setObjectName(QStringLiteral("deviceSelect"));
        deviceSelect->setGeometry(QRect(10, 35, 251, 20));
        deviceSelect->setFont(font4);
        deviceSelect->setFocusPolicy(Qt::WheelFocus);
        deviceSelect->setEditable(false);
        deviceSelect->setInsertPolicy(QComboBox::InsertAlphabetically);
        newDevice = new QPushButton(deviceWidget);
        newDevice->setObjectName(QStringLiteral("newDevice"));
        newDevice->setGeometry(QRect(83, 240, 114, 32));
        newDevice->setFont(font2);
        layoutWidget3 = new QWidget(deviceWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(35, 210, 211, 31));
        DeviceSaveRemoveLayout = new QHBoxLayout(layoutWidget3);
        DeviceSaveRemoveLayout->setSpacing(6);
        DeviceSaveRemoveLayout->setContentsMargins(11, 11, 11, 11);
        DeviceSaveRemoveLayout->setObjectName(QStringLiteral("DeviceSaveRemoveLayout"));
        DeviceSaveRemoveLayout->setContentsMargins(0, 0, 0, 0);
        deviceSaveButton = new QPushButton(layoutWidget3);
        deviceSaveButton->setObjectName(QStringLiteral("deviceSaveButton"));
        deviceSaveButton->setFont(font3);

        DeviceSaveRemoveLayout->addWidget(deviceSaveButton);

        deviceRemoveButton = new QPushButton(layoutWidget3);
        deviceRemoveButton->setObjectName(QStringLiteral("deviceRemoveButton"));
        deviceRemoveButton->setFont(font3);

        DeviceSaveRemoveLayout->addWidget(deviceRemoveButton);

        deviceName = new QLineEdit(deviceWidget);
        deviceName->setObjectName(QStringLiteral("deviceName"));
        deviceName->setGeometry(QRect(100, 65, 116, 20));
        deviceName->setFont(font4);
        deviceName->setMaxLength(32760);
        deviceNameLabel = new QLabel(deviceWidget);
        deviceNameLabel->setObjectName(QStringLiteral("deviceNameLabel"));
        deviceNameLabel->setGeometry(QRect(41, 65, 34, 20));
        deviceNameLabel->setFont(font3);
        deviceTypeLabel = new QLabel(deviceWidget);
        deviceTypeLabel->setObjectName(QStringLiteral("deviceTypeLabel"));
        deviceTypeLabel->setGeometry(QRect(41, 140, 34, 20));
        deviceTypeLabel->setFont(font3);
        deviceIDLabel = new QLabel(deviceWidget);
        deviceIDLabel->setObjectName(QStringLiteral("deviceIDLabel"));
        deviceIDLabel->setGeometry(QRect(41, 90, 52, 20));
        deviceIDLabel->setFont(font3);
        deviceID = new QLineEdit(deviceWidget);
        deviceID->setObjectName(QStringLiteral("deviceID"));
        deviceID->setGeometry(QRect(100, 90, 116, 20));
        deviceID->setFont(font4);
        roomLabel = new QLabel(deviceWidget);
        roomLabel->setObjectName(QStringLiteral("roomLabel"));
        roomLabel->setGeometry(QRect(41, 115, 34, 20));
        roomLabel->setFont(font3);
        deviceRoomSelect = new QComboBox(deviceWidget);
        deviceRoomSelect->setObjectName(QStringLiteral("deviceRoomSelect"));
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
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(41, 165, 35, 20));
        statusLabel->setFont(font3);
        deviceStatusSelect = new QComboBox(deviceWidget);
        deviceStatusSelect->setObjectName(QStringLiteral("deviceStatusSelect"));
        deviceStatusSelect->setGeometry(QRect(100, 165, 60, 20));
        deviceStatusSelect->setFont(font4);
        valueLabel = new QLabel(deviceWidget);
        valueLabel->setObjectName(QStringLiteral("valueLabel"));
        valueLabel->setGeometry(QRect(41, 190, 50, 20));
        valueLabel->setFont(font3);
        deviceValue = new QLineEdit(deviceWidget);
        deviceValue->setObjectName(QStringLiteral("deviceValue"));
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
        deviceTypeSelect->setObjectName(QStringLiteral("deviceTypeSelect"));
        deviceTypeSelect->setEnabled(true);
        deviceTypeSelect->setGeometry(QRect(390, 140, 85, 20));
        sizePolicy.setHeightForWidth(deviceTypeSelect->sizePolicy().hasHeightForWidth());
        deviceTypeSelect->setSizePolicy(sizePolicy);
        deviceTypeSelect->setMinimumSize(QSize(69, 0));
        deviceTypeSelect->setFont(font4);
        setupMonitorTabs->addTab(setupTab, QString());
        monitorTab = new QWidget();
        monitorTab->setObjectName(QStringLiteral("monitorTab"));
        updatedWindow = new QTextBrowser(monitorTab);
        updatedWindow->setObjectName(QStringLiteral("updatedWindow"));
        updatedWindow->setGeometry(QRect(10, 30, 551, 192));
        label = new QLabel(monitorTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 131, 16));
        QFont font5;
        font5.setFamily(QStringLiteral("Gisha"));
        font5.setPointSize(11);
        label->setFont(font5);
        setupMonitorTabs->addTab(monitorTab, QString());
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSetup->setText(QApplication::translate("MainWindow", "Setup", 0));
        actionMonitor->setText(QApplication::translate("MainWindow", "Monitor", 0));
        roomsLabel->setText(QApplication::translate("MainWindow", "Rooms", 0));
        newRoomButton->setText(QApplication::translate("MainWindow", "New Room", 0));
        saveRoom->setText(QApplication::translate("MainWindow", "Save Room", 0));
        removeRoom->setText(QApplication::translate("MainWindow", "Remove Room", 0));
        roomNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0));
        roomSelectLabel->setText(QApplication::translate("MainWindow", "Room Select", 0));
        deviceLabel->setText(QApplication::translate("MainWindow", "Devices", 0));
        deviceSelectLabel->setText(QApplication::translate("MainWindow", "Device Select", 0));
        newDevice->setText(QApplication::translate("MainWindow", "New Device", 0));
        deviceSaveButton->setText(QApplication::translate("MainWindow", "Save Device", 0));
        deviceRemoveButton->setText(QApplication::translate("MainWindow", "Remove Device", 0));
        deviceNameLabel->setText(QApplication::translate("MainWindow", "Name:", 0));
        deviceTypeLabel->setText(QApplication::translate("MainWindow", "Type:", 0));
        deviceIDLabel->setText(QApplication::translate("MainWindow", "Device ID:", 0));
        roomLabel->setText(QApplication::translate("MainWindow", "Room:", 0));
        statusLabel->setText(QApplication::translate("MainWindow", "Status:", 0));
        valueLabel->setText(QApplication::translate("MainWindow", "Set Value:", 0));
        setupMonitorTabs->setTabText(setupMonitorTabs->indexOf(setupTab), QApplication::translate("MainWindow", "Setup", 0));
        label->setText(QApplication::translate("MainWindow", "Last Updated:", 0));
        setupMonitorTabs->setTabText(setupMonitorTabs->indexOf(monitorTab), QApplication::translate("MainWindow", "Monitor", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
