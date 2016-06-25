#ifndef MUTATOR_H
#define MUTATOR_H

#include "chromosome.h"

class mutator
{
public:
    mutator();

    chromosome operator()(chromosome& c);
};

#endif // MUTATOR_H
