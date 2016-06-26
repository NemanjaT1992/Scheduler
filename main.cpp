#include "mainwindow.h"
#include "repository.h"
#include <QApplication>
#include <iostream>
#include <QDebug>

#include "chromosome.h"
#include "constraint.h"
#include "mutator.h"
#include "generator.h"

double test_eval(chromosome& c) { return 3.0; }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    chromosome c;
//    constraint constraint1([](auto& c) { return 2.0; });
//    constraint constraint2(test_eval);

//    qDebug () << constraint1(c);
//    qDebug () << constraint2(c);

    repository::get_instance();
    generator m_generator(5);
    m_generator.generate();

//    mutator{}(c);

//    auto days = range::day();
//    auto hours = range::hours();
//    auto courses = range::course();
//    auto rooms = range::room();
//    auto professors = range::professor();

//    qDebug () << days.first << days.second;
//    qDebug () << hours.first << hours.second;
//    qDebug () << courses.first << courses.second;
//    qDebug () << rooms.first << rooms.second;
//    qDebug () << professors.first << professors.second;

    return a.exec();
}
