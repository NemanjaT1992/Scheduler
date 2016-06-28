#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "time_table.h"
#include "repository.h"

class chromosome
{
public:
    std::vector<time_table> schedule;
    double fitness;

public:
    chromosome();
    chromosome(const chromosome& other);
    chromosome(chromosome&& other);

    chromosome& operator=(const chromosome& other);
    chromosome& operator=(chromosome&& other);

    void initialize_chrom();
    void print();
};

#endif // CHROMOSOME_H
