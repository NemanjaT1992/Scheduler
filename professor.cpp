#include "professor.h"

professor::professor(int id, QString name, QString last_name, std::vector<int> courses, std::vector<std::vector<int>>available)
{
    this->id = id;
    this->name = name;
    this->last_name = last_name;
    this->courses = std::move(courses);
    this->available = std::move(available);
}

void professor::print()
{
    qDebug() << id << name << last_name << available << courses;
}
