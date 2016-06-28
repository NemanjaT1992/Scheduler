#ifndef RECOMBINER_H
#define RECOMBINER_H

#include "chromosome.h"
#include <utility>


class recombiner
{
   // using day = std::vector<class_data>;
public:
    using children_pair = std::pair<chromosome,chromosome>;

    recombiner();
    children_pair recombine(chromosome& c1, chromosome& c2);
    void find_class_data(chromosome& reff_chromosome, chromosome& child, std::vector<class_data> day);
};

#endif // RECOMBINER_H
