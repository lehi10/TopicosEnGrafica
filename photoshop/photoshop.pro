#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T21:25:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = photoshop
TEMPLATE = app

INCLUDEPATH += /usr/include/opencv
LIBS += -Lusr/lib/x86_64-linux-gnu -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
