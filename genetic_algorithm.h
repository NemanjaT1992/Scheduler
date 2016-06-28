#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "generation.h"
//#include "evaluation.h"
#include "selector.h"
#include "recombiner.h"
#include "mutator.h"
#include "generator.h"

class genetic_algorithm
{
private:
    int generation_size;

    generation gen;
//    evaluator evaluate;
    selector select;
    recombiner recombine;
    mutator mutate;

public:
    genetic_algorithm(int generation_size, int mutation_rate, int elitism_rate, int tournament_size);

    chromosome run();
};

#endif // GENETIC_ALGORITHM_H
