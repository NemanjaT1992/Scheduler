#include "generation.h"

generation::generation()
{

}
generation::generation(int size)
{
    this->size = size;
}

void generation::insert(chromosome chr)
{
    gen.push_back(chr);
}

void generation::print()
{
//    for(int c=0; c<gen.size(); ++c)
//    {
//        qDebug() << "chromosome "<< c <<"---------------------------------------------";
//        for(int p=0; p<gen.at(c).schedule.size(); ++p)
//        {
//            professor prof = gen.at(c).schedule.at(p);
//            qDebug() << prof.name << prof.last_name;
//            prof.table.print();
//        }
//    }
}
