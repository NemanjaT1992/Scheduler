#include "selector.h"

#include <algorithm>
#include <utility>

selector::selector(int elitism_rate, int tournament_size)
//    : elitism_rate(2)
    : elitism_rate(elitism_rate)
    , fitness_range(0.0, 1.0)
//    , tournament_size(5)
    , tournament_size(tournament_size)
{
}

index_pair selector::roulette(generation& gen)
{
    double sum = std::accumulate(gen.begin(), gen.end(), 0.0, [](double prev, auto& c) { return prev + c.fitness; });

//    double sum = 30.0;
    std::uniform_real_distribution<> dis_sum(0.0, sum);

    auto select = [&](auto& random)
    {
        double probability = random(dis_sum);
        int index = 0;

        while (probability > 0)
        {
            probability -= gen[index].fitness;
            ++index;
        }

        return index >= gen.size() ? index - 1 : index;
    };

    return index_pair(select(random), select(random));
}

index_pair selector::stochastic_roulette(generation& gen)
{
    auto chromosome = std::max_element(gen.begin(), gen.end(),
                                          [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });

    double max_fitness = chromosome->fitness;

//    double max_fitness = 0.9;
    auto chromosome_index = range::distribution_of(gen);

    auto select = [&](auto& random)
    {
        while(true)
        {
            int index = random(chromosome_index);
            double fitness = gen[index].fitness;
//            double fitness = 0.2;

            if (random(fitness_range) < fitness / max_fitness)
                return index;
        }
    };

    return index_pair(select(random), select(random));
}

index_pair selector::ranking(generation& gen)
{
    std::sort(gen.begin(), gen.end(), [](auto& c1, auto& c2) { return c1.fitness < c2.fitness; });

    int sum = 0;
    for (int i = 0; i < gen.size(); ++i)
        sum += i;

    std::uniform_int_distribution<> dis_sum(0, sum);

    auto select = [&](auto& random)
    {
        int probability = random(dis_sum);
        int index = 0;

        while (probability > 0)
        {
            probability -= index + 1;
            ++index;
        }

        return index >= gen.size() ? index - 1 : index;
    };

    return index_pair(select(random), select(random));
}

std::vector<chromosome> selector::elitism(generation& gen)
{
    std::sort(gen.begin(), gen.end(), [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });
    std::vector<chromosome> next_gen;
    next_gen.reserve(elitism_rate);

    for (int i = 0; i < elitism_rate; ++i)
        next_gen.push_back(gen[i]);

    return next_gen;
}

index_pair selector::tournament(generation& gen)
{
    auto chromosome_index = range::distribution_of(gen);

    std::vector<int> arena;
    arena.reserve(tournament_size);

    auto select = [&](auto& random)
    {
        arena.clear();

        for (int j = 0; j < tournament_size; ++j)
            arena.push_back(random(chromosome_index));

        std::sort(arena.begin(), arena.end(), [&](int first, int second)
        {
            return gen[first].fitness > gen[second].fitness;
        });

        return arena.front();
    };

    int first = select(random);
    int second = select(random);

    return index_pair(first, second);
}
