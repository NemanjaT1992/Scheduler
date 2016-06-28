#ifndef SELECTOR_H
#define SELECTOR_H

#include "range.h"
#include "generation.h"
#include "random_generator.h"

struct selector
{
    int elitism_rate;
    int tournament_size;
    std::uniform_int_distribution<> fitness_range;
    random_generator random;

    selector(int elitism_rate, int tournament_size);

    index_pair operator()(generation& gen);
    index_pair roulette(generation& gen);
    index_pair stochastic_roulette(generation& gen);
    index_pair ranking(generation& gen);
    std::vector<chromosome> elitism(generation& gen);
    index_pair tournament(generation& gen);
};

#endif // SELECTOR_H
