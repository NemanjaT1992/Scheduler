#ifndef MUTATOR_H
#define MUTATOR_H

#include "chromosome.h"
#include "random_generator.h"
//#include "time_table.h"
#include <utility>

class mutator
{
private:
    using data_ptr = decltype(&class_data::count);

    random_generator random;
    std::uniform_int_distribution<> probability_distribution;
    int mutation_rate;
    std::vector<data_ptr> data;

public:
    mutator();

    chromosome operator()(chromosome& c);
};

#endif // MUTATOR_H
