#include "selector.h"

selector::selector()
    : elitism_rate(2)
    , fitness_range(0.0, 1.0)
    , tournament_size(5)
{
}

index_pair selector::roulette(generation& gen)
{
//        double sum = std::accumulate(gen.begin(), gen.end(), 0.0, [](double prev, auto& c) { return prev + c.fitness; });

    double sum = 30.0;
    std::uniform_real_distribution<> dis_sum(0.0, sum);

    auto select = [&](auto& random)
    {
        double probability = random(dis_sum);
        int index = 0;

        while (probability > 0)
        {
//                probability -= gen[index].fitness;
            ++index;
        }

        return index;
    };

    return index_pair(select(random), select(random));
}

index_pair selector::stochastic_roulette(generation& gen)
{
//        double max_fitness = std::max_element(gen.begin(), gen.end(),
//                                              [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });

    double max_fitness = 0.9;
    std::uniform_int_distribution<> chromosome_index(0, gen.size());

    auto select = [&](auto& random)
    {
        while(true)
        {
            int index = random(chromosome_index);
//                double fitness = gen[index].fitness;
            double fitness = 0.2;

            if (random(fitness_range) < fitness / max_fitness)
                return index;
        }
    };

    return index_pair(select(random), select(random));
}

index_pair selector::ranking(generation& gen)
{
//        std::sort(gen.begin(), gen.end(), [](auto& c1, auto& c2) { return c1.fitness < c2.fitness; });

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

        return index;
    };

    return index_pair(select(random), select(random));
}

index_pair selector::elitism(generation& gen)
{
//        std::sort(chromosomes.begin(), chromosomes.end(), [](auto& c1, auto& c2) { c1.fitness > c2.fitness; });

    for (int i = 0; i < elitism_rate; ++i);
//        selected.push_back(chromosomes[i]);

    return index_pair();
}

index_pair selector::tournament(generation& gen)
{
    std::uniform_int_distribution<> chromosome_index(0, gen.size());

    std::vector<double> tour;
    tour.reserve(tournament_size);

    auto select = [&](auto& random)
    {
        tour.clear();

        for (int j = 0; j < tournament_size; ++j);
//                tour.push_back(gen[random(chromosome_index)].fitness);

        std::sort(tour.begin(), tour.end());

        return tour.front();
    };

    return index_pair(select(random), select(random));
}
