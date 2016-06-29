#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "generation.h"
#include "evaluator.h"
#include "selector.h"
#include "recombiner.h"
#include "mutator.h"
#include "generator.h"
#include "mainwindow.h"

template<typename Iter, typename F>
void for_each_chromosome(Iter begin, Iter end, F&& handler)
{
    for (Iter it = begin; it != end; ++it)
        handler(*it);
}

class genetic_algorithm
{
private:
    int generation_size;

    generation gen;
    evaluator evaluate;
    selector select;
    recombiner recombine;
    mutator mutate;
    MainWindow* window;
    double crossover_rate;
public:
    genetic_algorithm(int generation_size, int mutation_rate, int elitism_rate, int tournament_size, MainWindow* m, double cr );

    chromosome run();
};

#endif // GENETIC_ALGORITHM_H
