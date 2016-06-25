#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include "time_table.h"
#include "professor.h"

class chromosome
{
public:
    std::vector<professor> schedule;

public:
    chromosome();
};

#endif // CHROMOSOME_H
