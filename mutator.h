#ifndef MUTATOR_H
#define MUTATOR_H

#include "chromosome.h"
#include "random_generator.h"
#include <utility>

class mutator
{
private:
    using mutate_handler = void(mutator::*)(chromosome&);

    random_generator random;
    std::uniform_int_distribution<> probability_distribution;
    int mutation_rate;
    std::vector<mutate_handler> handlers;

public:
    mutator(int mutation_rate);

    void operator()(chromosome& c);
    void mutate_day(chromosome& c);
    void mutate_time(chromosome& c);
    void swap_days(chromosome& c);
    void swap_rooms(chromosome& c);

    template<typename F>
    void mutate_base(chromosome& c, F&& f);
};

#endif // MUTATOR_H
