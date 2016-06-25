#include "chromosome.h"

#include <algorithm>

chromosome::chromosome()
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
