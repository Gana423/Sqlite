#-------------------------------------------------
#
# Project created by QtCreator 2017-03-10T15:09:51
#
#-------------------------------------------------

QT       += core gui
QT       += bluetooth
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bluetooth
TEMPLATE = app

LIBS += -L/usr/lib -lbluetooth

SOURCES += main.cpp\
        bluetooth.cpp

HEADERS  += bluetooth.h

FORMS    += bluetooth.ui
