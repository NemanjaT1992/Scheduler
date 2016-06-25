#include "repository.h"

repository::repository()
{
    bool profs_loaded = load_professors("professors.txt");
    bool classes_loaded = load_classes("classes.txt");
    qDebug() << "professors_loaded:" << profs_loaded;
    qDebug() << "classes_loaded:" << classes_loaded;

    for(int i=0; i<professors.size(); ++i)
        professors.at(i).print();
    for(int i=0; i<courses.size(); ++i)
        courses.at(i).print();
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

            QString available = line_elements.at(3);
            std::vector<int> avail;
            for(int i=0; i<available.length(); ++i)
                avail.push_back(available.mid(i, 1).toInt());

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

professor& repository::get_professor(int id)
{
    return professors.at(id);
}

course_class& repository::get_course(int id)
{
    return courses.at(id);
}
