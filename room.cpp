#include "room.h"

room::room(int i, int s, QString n)
    :id(i)
    ,seats(s)
    ,name(n)
{

}

void room::print()
{
    qDebug() << id << seats << name;
}
