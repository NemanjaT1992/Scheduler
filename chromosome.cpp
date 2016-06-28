#include "chromosome.h"

#include <algorithm>

chromosome::chromosome()
    : fitness(0)
{

}

chromosome::chromosome(const chromosome& other)
{
    schedule = other.schedule;
}

chromosome::chromosome(chromosome&& other)
{
    schedule = std::move(other.schedule);
}

chromosome& chromosome::operator=(const chromosome& other)
{
    schedule = other.schedule;

    return *this;
}

chromosome& chromosome::operator=(chromosome&& other)
{
    schedule = std::move(other.schedule);

    return *this;
}

void chromosome::initialize_chrom()
{
    time_table tt;
    for(int i=0; i<get::rooms().size(); ++i)
        schedule.push_back(tt);
}

void chromosome::print()
{
    for(int i=0; i<schedule.size(); ++i)
    {
        qDebug() << "-------------room" << i;
        schedule[i].print();
    }
}
