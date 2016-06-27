#include "repository.h"

namespace get
{
std::vector<professor>& professors()
{
    return repository::get_instance().get_professors();
}

std::vector<course_class>& courses()
{
    return repository::get_instance().get_courses();
}

std::vector<room>& rooms()
{
    return repository::get_instance().get_rooms();
}

std::vector<student_group>& student_groups()
{
    return repository::get_instance().get_student_groups();
}

professor& professor_at(int id)
{
    return repository::get_instance().get_professor(id);
}

course_class& course_at(int id)
{
    return repository::get_instance().get_course(id);
}

room& room_at(int id)
{
    return repository::get_instance().get_room(id);
}

student_group& student_group_at(int id)
{
    return repository::get_instance().get_student_group(id);
}
}



repository::repository()
{
    bool profs_loaded = load_professors("professors.txt");
    bool classes_loaded = load_classes("classes.txt");
    bool rooms_loaded = load_rooms("rooms.txt");
    bool groups_loaded = load_student_groups("student_groups.txt");
    qDebug() << "professors_loaded:" << profs_loaded;
    qDebug() << "classes_loaded:" << classes_loaded;
    qDebug() << "rooms_loaded:" << rooms_loaded;
    qDebug() << "groups_loaded:" << groups_loaded;

    for(int i=0; i<professors.size(); ++i)
        professors.at(i).print();
    for(int i=0; i<courses.size(); ++i)
        courses.at(i).print();
    for(int i=0; i<rooms.size(); ++i)
        rooms.at(i).print();
    for(int i=0; i<student_groups.size(); ++i)
        student_groups.at(i).print();
}

bool repository::load_professors(QString fileName)
{
    QFile inputFile(fileName);
    int id = 0;
    if(inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in_stream(&inputFile);
        while(!in_stream.atEnd())
        {
            QString line = in_stream.readLine();
            QStringList line_elements = line.split("|");
            QString classList = line_elements.at(2);
            QStringList classes = classList.split(",");
            std::vector<int> classesTmp;
            for(int i=0; i<classes.length(); ++i)
                classesTmp.push_back(classes.at(i).toInt());

            std::vector<std::vector<int>> avail;

            for(int i=3; i<line_elements.length(); ++i)
            {
                QString day_avail = line_elements.at(i);
                std::vector<int> day_vector;
                for(int i=0; i<day_avail.length(); ++i)
                    day_vector.push_back(day_avail.mid(i, 1).toInt());
                avail.push_back(day_vector);
            }

            professor prof(id++, line_elements.at(0), line_elements.at(1), std::move(classesTmp), std::move(avail));
            professors.push_back(prof);
        }
        inputFile.close();
        return true;
    }
    return false;
}

bool repository::load_classes(QString fileName)
{
    QFile inputFile(fileName);
    if(inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in_stream(&inputFile);
        while(!in_stream.atEnd())
        {
            QString line = in_stream.readLine();
            QStringList line_elements = line.split("|");
            course_class course(line_elements.at(0).toInt(), line_elements[1], line_elements[2].toInt());
            courses.push_back(course);
        }
        inputFile.close();
        return true;
    }
    return false;
}

bool repository::load_rooms(QString fileName)
{

    QFile inputFile(fileName);
    if(inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in_stream(&inputFile);
        while(!in_stream.atEnd())
        {
            QString line = in_stream.readLine();
            QStringList line_elements = line.split("|");
            room r(line_elements.at(0).toInt(), line_elements.at(1).toInt(), line_elements.at(2));
            rooms.push_back(r);
        }
        inputFile.close();
        return true;
    }
    return false;
}

bool repository::load_student_groups(QString fileName)
{
    QFile inputFile(fileName);
    if(inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in_stream(&inputFile);
        while(!in_stream.atEnd())
        {
            QString line = in_stream.readLine();
            QStringList line_elements = line.split("|");
            student_group std_gr(line_elements.at(0).toInt(), line_elements.at(1).toInt(), line_elements.at(2));
            student_groups.push_back(std_gr);
        }
        inputFile.close();
        return true;
    }
    return false;
}

professor& repository::get_professor(int id)
{
    return professors.at(id);
}

course_class& repository::get_course(int id)
{
    return courses.at(id);
}

room &repository::get_room(int id)
{
    return rooms.at(id);
}

student_group &repository::get_student_group(int id)
{
    return student_groups.at(id);
}

std::vector<professor>& repository::get_professors()
{
    return professors;
}

std::vector<course_class>& repository::get_courses()
{
    return courses;
}

std::vector<room> &repository::get_rooms()
{
    return rooms;
}

std::vector<student_group> &repository::get_student_groups()
{
    return student_groups;
}

int repository::professors_count()
{
    return professors.size();
}

int repository::courses_count()
{
    return courses.size();
}

int repository::rooms_count()
{
    return rooms.size();
}

int repository::student_groups_count()
{
    return student_groups.size();
}
