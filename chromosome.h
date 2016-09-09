#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "time_table.h"
#include "repository.h"
#include "random_generator.h"

class chromosome
{
public:
    std::vector<time_table> schedule;
    int fitness;
    random_generator random;

public:
    chromosome();
    chromosome(const chromosome& other);
    chromosome(chromosome&& other);

    chromosome& operator=(const chromosome& other);
    chromosome& operator=(chromosome&& other);
    bool operator==(chromosome& other);
    void initialize_chrom();
    void print();
    void set();
};

#endif // CHROMOSOME_H
