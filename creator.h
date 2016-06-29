#ifndef CREATOR_H
#define CREATOR_H

#include <QFile>
#include <QTextStream>
#include <vector>
#include "random_generator.h"

class creator
{
private:
    int classes = 50;
    int professors = 100;
    int rooms = 30;

    std::vector<int> professor_pool;
    std::vector<int> class_pool;
    std::vector<int> room_pool;

public:
    creator();

    void professors_file();
    void classes_file();
    void rooms_file();

    template<typename F>
    void write_file(QString name, F&& writer)
    {
        QFile file(name);

        if (file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);

            writer(stream);
        }

        file.close();
    }
};

#endif // CREATOR_H
