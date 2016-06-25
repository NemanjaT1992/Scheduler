#include "student_group.h"

student_group::student_group(int id, int num, QString n)
    :id(id)
    ,num_of_students(num)
    ,name(n)
{

}

void student_group::print()
{
    qDebug() << id << num_of_students << name;
}
