#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QDebug>

class room
{
public:
    room(int i, int s, QString n);
    void print();

private:
    int id;
    int seats;
    QString name;
};

#endif // ROOM_H
