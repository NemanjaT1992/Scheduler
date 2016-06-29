#include "creator.h"

creator::creator()
{
    professor_pool.reserve(professors);
    class_pool.reserve(classes);
    room_pool.reserve(rooms);
}

void creator::professors_file()
{
//    write_file("professors.txt", [this](auto& stream)
//    {
//        for (int i = 0; i < professors; ++i)
//        {
//            stream << QString("%1|%2"
//        }
//    });
}

void creator::classes_file()
{
//    write_file("classes.txt", [this](auto& stream)
//    {
//        for (int i = 0; i < classes; ++i)
//            stream << QString("%1|%2|%3
//    });
}

void creator::rooms_file()
{
}
