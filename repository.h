#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "professor.h"
#include "course_class.h"
#include "room.h"
#include "student_group.h"
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class repository
{
public:
    static repository& get_instance()
    {
       static repository instance;
       return instance;
    }

    bool load_professors(QString fileName);
    bool load_classes(QString fileName);
    bool load_rooms(QString fileName);
    bool load_student_groups(QString fileName);

    professor& get_professor(int id);
    course_class& get_course(int id);
    room& get_room(int id);
    student_group& get_student_group(int id);

    std::vector<professor>& get_professors();
    std::vector<course_class>& get_courses();
    std::vector<room>& get_rooms();
    std::vector<student_group>& get_student_groups();

    int professors_count();
    int courses_count();
    int rooms_count();
    int student_groups_count();

private:
    repository();
    repository(repository const&)            = delete;
    repository& operator=(repository const&) = delete;
    repository(repository&& other)           = delete;

    std::vector<professor> professors;
    std::vector<course_class> courses;
    std::vector<room> rooms;
    std::vector<student_group> student_groups;


};

#endif // REPOSITORY_H
