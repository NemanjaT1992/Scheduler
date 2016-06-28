#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QDebug>

struct course_class
{
    course_class() = default;
    course_class(int id, QString name, int fond, int num_of_studs, std::vector<int> profs);
    void print();

    int id;
    QString name;
    int fond;
    int num_of_students;
    std::vector<int> professors;
    std::vector<bool> professor_available;
    int num_of_classes();
    int get_professor();
    void clear_professor_availability();
};

#endif // CLASS_H
