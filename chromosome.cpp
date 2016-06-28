#include "chromosome.h"

#include <algorithm>

chromosome::chromosome()
    : fitness(0)
{

}

chromosome::chromosome(const chromosome& other)
{
    schedule = other.schedule;
    fitness = other.fitness;
}

chromosome::chromosome(chromosome&& other)
{
    schedule = std::move(other.schedule);
    fitness = std::move(other.fitness);
}

chromosome& chromosome::operator=(const chromosome& other)
{
    schedule = other.schedule;
    fitness = other.fitness;

    return *this;
}

chromosome& chromosome::operator=(chromosome&& other)
{
    schedule = std::move(other.schedule);
    fitness = std::move(other.fitness);

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
