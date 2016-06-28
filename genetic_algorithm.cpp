#include "genetic_algorithm.h"

genetic_algorithm::genetic_algorithm(int generation_size, int mutation_rate, int elitism_rate, int tournament_size)
    : generation_size(generation_size)
    , select(elitism_rate, tournament_size)
    , mutate(mutation_rate)
{
}

chromosome genetic_algorithm::run()
{
    gen = generator(generation_size).generate();
    for_each_chromosome(gen.begin(), gen.end(), evaluate);

    while (evaluate.max_fitness < 1.0)
    {
        qDebug () << "max fitness: " << evaluate.max_fitness;

        evaluate.max_fitness = 0;
//        generation next_gen = std::move(select.elitism(gen));
        generation next_gen;

        while (next_gen.size() < generation_size)
        {
            index_pair parents = select.stochastic_roulette(gen);
            recombiner::children_pair children = recombine(gen[parents.first], gen[parents.second]);
            next_gen.push_back(std::move(children.first));
            next_gen.push_back(std::move(children.second));
        }

        for_each_chromosome(next_gen.begin() + select.elitism_rate, next_gen.end(), mutate);
        for_each_chromosome(next_gen.begin(), next_gen.end(), evaluate);

        gen = std::move(next_gen);
    }

//    int x = 5;
    auto it = std::max_element(gen.begin(), gen.end(), [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });

    return *it;
}
