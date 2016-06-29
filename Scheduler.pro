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
    recombiner.cpp \
    generation.cpp \
    room.cpp \
    constraint.cpp \
    mutator.cpp \
    repository.cpp \
    professor.cpp \
    course_class.cpp \
    generator.cpp \
    random_generator.cpp \
    student_group.cpp \
    range.cpp \
    selector.cpp \
    genetic_algorithm.cpp \
    evaluator.cpp \
    creator.cpp

HEADERS  += mainwindow.h \
    chromosome.h \
    time_table.h \
    room.h \
    recombiner.h \
    generation.h \
    course_class.h \
    professor.h \
    repository.h \
    constraint.h \
    mutator.h \
    random_generator.h \
    range.h \
    generator.h \
    student_group.h \
    evaluation.h \
    selector.h \
    genetic_algorithm.h \
    evaluator.h \
    creator.h


FORMS    += mainwindow.ui

CONFIG += c++14
