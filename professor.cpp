#include "professor.h"

professor::professor(int id, QString name, QString last_name, std::vector<int> courses, std::vector<int> available)
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

bool professor::is_available()
{
    auto classes = table.get_table();
    for(int i=0; i<classes.size(); ++i)
    {
        int startIndex = classes.at(i).day * constants::hours + classes.at(i).time;
        int endIndex = startIndex + classes.at(i).count;

//        while((available.at(startIndex) == 1) && ((startIndex - 1) != endIndex))
//            startIndex++;

//        if(startIndex - 1 == endIndex)
//            return true;
//        else
//            return false;

        return std::all_of(available.begin() + startIndex, available.begin() + endIndex,
                           [](int& i) { return i == 1; });

    }
}
