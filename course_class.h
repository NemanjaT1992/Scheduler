#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QDebug>

struct course_class
{
    course_class() = default;
    course_class(int id, QString name, int fond);
    void print();

    int id;
    QString name;
    int fond;
};

#endif // CLASS_H
