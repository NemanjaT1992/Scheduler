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
    repository.cpp \
    professor.cpp \
    course_class.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    time_table.h \
    room.h \
    repository.h \
    professor.h \
    course_class.h

FORMS    += mainwindow.ui

CONFIG += c++14
