#ifndef RECOMBINER_H
#define RECOMBINER_H

#include "chromosome.h"
#include <utility>

class recombiner
{
public:
    using children_pair = std::pair<chromosome,chromosome>;

    recombiner();
    children_pair recombine(chromosome& c1, chromosome& c2);
};

#endif // RECOMBINER_H
