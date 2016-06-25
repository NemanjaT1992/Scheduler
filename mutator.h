#ifndef MUTATOR_H
#define MUTATOR_H

#include "chromosome.h"
#include "random_generator.h"
#include "time_table.h"
#include <utility>

class mutator
{
private:
    using gene_ptr = decltype(&class_data::count);

    random_generator random;
    std::uniform_int_distribution<> dis;
    int mutation_rate;
    std::vector<gene_ptr> data;

public:
    mutator();

    chromosome operator()(chromosome& c);
};

#endif // MUTATOR_H
