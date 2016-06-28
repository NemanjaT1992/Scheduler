#include "genetic_algorithm.h"

genetic_algorithm::genetic_algorithm(int generation_size, int mutation_rate, int elitism_rate, int tournament_size)
    : generation_size(generation_size)
    , select(elitism_rate, tournament_size)
    , mutate(mutation_rate)
{
}

void genetic_algorithm::run()
{
//    gen = generator(generation_size).generate();
//    std::for_each(gen.begin(), gen.end(), evaluate);

//    while (evaluate.max_fitness < 1.0)
//    {
//        generation next_gen = select.elitism(gen);

//        while (next_gen.size() < generation_size)
//        {
//            index_pair parents = select(gen);
//            children_pair children = recombine(gen[parents.first], gen[parents.second]);

//            next_gen.push_back(children.first);
//            next_gen.push_back(children.second);
//        }

//        std::for_each(next_gen.begin() + select.elitism_rate, next_gen.end(), mutate);
//        std::for_each(next_gen.begin() + select.elitism_rate, next_gen.end(), evaluate);

//        gen = std::move(next_gen);
//    }
}
