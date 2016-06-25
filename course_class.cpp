#include "course_class.h"

course_class::course_class(int id, QString name, int fond)
{
    this->id = id;
    this->name = name;
    this->fond = fond;
}

void course_class::print()
{
    qDebug() << id << name << fond;
}
