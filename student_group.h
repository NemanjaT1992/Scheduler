#ifndef STUDENT_GROUP_H
#define STUDENT_GROUP_H

#include <QString>
#include <QDebug>

class student_group
{
public:
    student_group(int id, int num, QString n);
    void print();

private:
    int id;
    int num_of_students;
    QString name;
};

#endif // STUDENT_GROUP_H
