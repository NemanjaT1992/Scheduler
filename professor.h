#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "course_class.h"
#include <vector>
#include <QString>

using availability = std::vector<std::vector<int>>;

struct professor
{
    professor(int id, QString name, QString last_name, std::vector<int> courses, availability available);
    void print();

    int id;
    QString name;
    QString last_name;
    availability available;
    std::vector<int> courses;
};

#endif // PROFESSOR_H
