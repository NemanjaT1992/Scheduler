#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QDebug>

class room
{
public:
    room(int i, int s, QString n);
    void print();
    int seats;
private:
    int id;

    QString name;
};

#endif // ROOM_H
