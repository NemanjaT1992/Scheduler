#ifndef RECOMBINER_H
#define RECOMBINER_H

#include "chromosome.h"
#include <utility>
#include "random_generator.h"


class recombiner
{
   // using day = std::vector<class_data>;
    random_generator random;
public:
    using children_pair = std::pair<chromosome,chromosome>;

    recombiner();
    children_pair operator()(chromosome& c1, chromosome& c2);
    void find_class_data(chromosome& reff_chromosome, chromosome& child, std::vector<class_data>& day
                         ,int parent_room, int parent_day);
};

#endif // RECOMBINER_H
