#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "time_table.h"
#include "time_table.h"

class chromosome
{
public:
    std::vector<time_table> schedule;

public:
    chromosome();
    chromosome(const chromosome& other);
    chromosome(chromosome&& other);

    chromosome& operator=(const chromosome& other);
    chromosome& operator=(chromosome&& other);
};

#endif // CHROMOSOME_H
