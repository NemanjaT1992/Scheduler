#include "course_class.h"

course_class::course_class(int id, QString name, int fond, int num_of_studs, std::vector<int> profs)
{
    this->id = id;
    this->name = name;
    this->fond = fond;
    this->num_of_students = num_of_studs;
    this->professors = profs;
    for(int i=0; i<profs.size(); ++i)
        professor_available.push_back(true);
}

void course_class::print()
{
    qDebug() << id << name << fond << num_of_students << professors << professor_available;
}

int course_class::num_of_classes()
{
    return num_of_students/professors.size();
}

int course_class::get_professor()
{
    int ind = 0;
    while(!professor_available.at(ind))
        ind++;
    if(ind != professor_available.size())
    {
        professor_available[ind] = false;
        return professors.at(ind);
    }
    return -1;
}

void course_class::clear_professor_availability()
{
    for(int i=0; i<professor_available.size(); ++i)
        professor_available[i] = true;
}
