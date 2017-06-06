#include "bluetooth.h"
#include "ui_bluetooth.h"

QString mac_1,mac_2,mac_3,mac_4,mac_5;
QString mac_y1,mac_y2,mac_y3,mac_y4,mac_y5;

QString Address;
QString Name;
QString Voice;
QString Play_path;
QString text, play_mac;

QStringList values;
QStringList childKeys;

int cnt, mac_cnt;
int num_rsp ,dev_id, sock, flags ;
int len  = 8, max_rsp = 255;

inquiry_info *ii = NULL;

Bluetooth::Bluetooth(QWidget *parent) : QDialog(parent), ui(new Ui::Bluetooth)
{
    player = new QMediaPlayer(this);

    read_macs();

    DeviceScan();
}

void Bluetooth::DeviceScan()
{
    while(1) {

        dev_id = hci_get_route(NULL);
        sock = hci_open_dev( dev_id );

        if (dev_id < 0 || sock < 0) {
            perror("opening socket");
            exit(1);
        }

        flags = IREQ_CACHE_FLUSH; /*the cache of previously detected devices is flushed before performing the current inquiry....*/
        ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));

        num_rsp = hci_inquiry(dev_id, len, max_rsp, NULL, &ii, flags);
        if(num_rsp == 0)
            mac_cnt = 0;

        printf("No.of devices found : %d\n", num_rsp);
        dev_Response();

        free( ii );
    }
}
void Bluetooth::dev_Response()
{

    char addr[19] = { 0 };
    char name[248] = { 0 };
    int i;

    for (i = 0; i < num_rsp; i++) {

        ba2str(&(ii+i)->bdaddr, addr);
        memset(name, 0, sizeof(name));

        if (hci_read_remote_name(sock, &(ii+i)->bdaddr, sizeof(name), name, 0) < 0) {
            strcpy(name, "[unknown]");
        }

        printf("********************************************\n");
        printf("%s  %s\n", addr, name);
        printf("********************************************\n");

        Address = addr;
        Name = name;

        ui_notification(Address, Name);
    }
}
void Bluetooth::ui_notification(QString rcvd_mac, QString rcvd_name)
{

    if(rcvd_mac!=mac_1 && rcvd_mac!=mac_2 && rcvd_mac!=mac_3 && rcvd_mac!=mac_4 && rcvd_mac!=mac_5){
        if(mac_y1 != rcvd_mac && mac_y2 != rcvd_mac && mac_y3 != rcvd_mac && mac_y4 != rcvd_mac && mac_y5 != rcvd_mac) {
            QMessageBox msgbox;
            msgbox.setWindowTitle(rcvd_name);
            msgbox.setIcon(QMessageBox::Question);
            msgbox.setText("New Device is Identified, Do you want to register");
            msgbox.setStandardButtons(QMessageBox::Yes);
            msgbox.addButton(QMessageBox::No);
            msgbox.setDefaultButton(QMessageBox::No);

            if(msgbox.exec() == QMessageBox::Yes) {
                cnt  = cnt + 1;
                if(cnt == 1)
                    mac_y1 = rcvd_mac;
                if(cnt == 2)
                    mac_y2 = rcvd_mac;
                if(cnt == 3)
                    mac_y3 = rcvd_mac;
                if(cnt == 4)
                    mac_y4 = rcvd_mac;
                if(cnt == 5)
                    mac_y5 = rcvd_mac;
                if(cnt > 5){
                    QMessageBox::warning(this, "Registration Failed", "You can't register more devices");
                }

                // Taking input string from user

                QByteArray ba = rcvd_name.toLatin1();
                char *dev_name = ba.data();

                bool ok;
                QString wlcm = "Welcome  ";
                text = QInputDialog::getText(this, tr(dev_name), tr("User Name:"), QLineEdit::Normal,"", &ok);
                Voice = wlcm.append(text);

                // Creating audio file
                QProcess process;
                process.startDetached("flite", QStringList() << "-t"<< Voice << text);

                // Writing Dev info to audio.ini
                QSettings* settings = new QSettings(QDir::currentPath() + "/audio.ini", QSettings::IniFormat);
                settings->setValue(rcvd_mac, text);
                settings->sync();

                return ;
            }
            if(msgbox.exec() == QMessageBox::No) {
                return ;
            }
        }else {
            qDebug()<<"Your Device is already registered";
        }

    }else{

        welcome_sound(rcvd_mac);
    }
}

void Bluetooth::welcome_sound(QString snd_mac)
{
    int i;

    if(mac_cnt != num_rsp && mac_cnt < num_rsp){
        mac_cnt = num_rsp;
        for(i = 0; i<childKeys.count(); i++) {
            QString Sound_path = "/home/pi/22_03/Bluetooth/";

            if(childKeys.at(i) == snd_mac) {
                Play_path = Sound_path.append(values.at(i));
                player->setMedia(QUrl::fromLocalFile(Play_path));
                player->play();
                play_mac = snd_mac;
                sleep(2);
            }
        }
    }else {
        mac_cnt = num_rsp;
    }
}

void Bluetooth::read_macs()
{
    QSettings* stngs = new QSettings("/home/pi/22_03/Bluetooth/audio.ini", QSettings::IniFormat);
    childKeys = stngs->childKeys();

    foreach (const QString &childKey, childKeys)
        values << stngs->value(childKey).toString();

    for(int i = 0; i < childKeys.count(); i++) {
        qDebug()<<childKeys.at(i)  <<values.at(i);
        if(i == 0)
            mac_1 = childKeys.at(i);
        else if(i == 1)
            mac_2 = childKeys.at(i);
        else if(i == 2)
            mac_3 = childKeys.at(i);
        else if(i == 3)
            mac_4 = childKeys.at(i);
        else if(i == 4)
            mac_5 = childKeys.at(i);
    }
    qDebug()<<"Mac_1: "<<mac_1;
    qDebug()<<"Mac_2: "<<mac_2;
    qDebug()<<"Mac_3: "<<mac_3;
}
