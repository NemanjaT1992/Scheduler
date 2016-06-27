#ifndef SELECTOR_H
#define SELECTOR_H

#include "range.h"
#include "generation.h"
#include "random_generator.h"

struct selector
{
    int elitism_rate;
    random_generator random;

    selector();

    index_pair operator()(generation& gen);
    index_pair roulette(generation& gen);
    index_pair stochastic_roulette(generation& gen);
    index_pair ranking(generation& gen);
    index_pair elitism(generation& gen);
    index_pair tournament(generation& gen);
};

#endif // SELECTOR_H
