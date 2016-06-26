#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "course_class.h"
#include <vector>
#include <QString>

struct professor
{
    professor(int id, QString name, QString last_name, std::vector<int> courses, std::vector<int> available);
    void print();

    int id;
    QString name;
    QString last_name;
    std::vector<int> available;
    std::vector<int> courses;
};

#endif // PROFESSOR_H
