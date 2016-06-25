#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "professor.h"
#include "course_class.h"
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

    professor& get_professor(int id);
    course_class& get_course(int id);

    std::vector<professor>& get_professors();
    std::vector<course_class>& get_courses();

private:
    repository();
    repository(repository const&)            = delete;
    repository& operator=(repository const&) = delete;
    repository(repository&& other)           = delete;

    std::vector<professor> professors;
    std::vector<course_class> courses;

};

#endif // REPOSITORY_H
