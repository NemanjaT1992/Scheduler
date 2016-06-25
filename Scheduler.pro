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
    chromosome.cpp \
    time_table.cpp \
    constraint.cpp \
    mutator.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    time_table.h \
    room.h \
    class.h \
    constraint.h \
    mutator.h

FORMS    += mainwindow.ui

CONFIG += c++14
