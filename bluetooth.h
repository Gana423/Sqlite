#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <QDialog>
#include <QLineEdit>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

#include <QDebug>
#include <QMessageBox>
#include <QProcess>
#include <QInputDialog>
#include <QMediaPlayer>
#include <QFile>
#include <QSettings>
#include <QDir>

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

namespace Ui {
class Bluetooth;
}

class Bluetooth : public QDialog
{
    Q_OBJECT

public:
    explicit Bluetooth(QWidget *parent = 0);

    QMediaPlayer *player;
    QLineEdit *m_lineEdit;
    //QVBoxLayout *lt;
public slots:
    void DeviceScan();
    void read_macs();
    void dev_Response();
    void ui_notification(QString rcvd_mac, QString rcvd_name);
    //void write_macs();
    void welcome_sound(QString snd_mac);

private slots:

private:
    Ui::Bluetooth *ui;
};

#endif // BLUETOOTH_H
