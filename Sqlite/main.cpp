#include "bluetooth.h"
#include <QApplication>
#include <QMessageBox>

#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bluetooth w;

    w.show();

    //return a.exec();
}
