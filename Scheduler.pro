#-------------------------------------------------
#
# Project created by QtCreator 2016-06-22T20:24:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Scheduler
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    class.cpp

HEADERS  += mainwindow.h \
    room.h \
    class.h

FORMS    += mainwindow.ui
