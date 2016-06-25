#ifndef MUTATOR_H
#define MUTATOR_H

#include "chromosome.h"
#include "random_generator.h"

class mutator
{
private:
    random_generator random;

public:
    mutator();

    chromosome operator()(chromosome& c);
};

#endif // MUTATOR_H
