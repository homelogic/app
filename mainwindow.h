#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "device.h"
#include <QString>
#include <QtSql/QtSql>
#include <QList>
#include <QTimer>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void load_device_defaults();
    void load_device_list();
    void timer_start();
    void change_updated(QString msg);
    
private slots:


    void on_deviceSelect_currentIndexChanged(int index);

    void on_newDevice_clicked();

    void on_deviceRemoveButton_clicked();

    void on_deviceSaveButton_clicked();

    void on_roomSelect_currentIndexChanged();

    void on_saveRoom_clicked();

    void on_removeRoom_clicked();

    void on_newRoomButton_clicked();

    void device_timer_timeout();

    void check_status_timeout();

private:

    Ui::MainWindow *ui;
    QString currentDevice;
    QSqlDatabase db;
    bool dbSuccess;
    Device  myDevice;
    QList<Device *> devices;


};

#endif // MAINWINDOW_H
