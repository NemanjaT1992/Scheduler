#include "genetic_algorithm.h"

genetic_algorithm::genetic_algorithm(int generation_size, int mutation_rate, int elitism_rate
                                     ,int tournament_size, MainWindow* m, double cr)
    : generation_size(generation_size)
    , select(elitism_rate, tournament_size)
    , mutate(mutation_rate)
    , window(m)
    , crossover_rate(cr)
{
}

chromosome genetic_algorithm::run()
{
    gen = generator(generation_size).generate();
    for_each_chromosome(gen.begin(), gen.end(), evaluate);


    int  i = 0;
    int prev_max = 0;
    int gen_counter = 0;

    while (evaluate.max_fitness < 84)
    {
        qDebug () << "max fitness: " << evaluate.max_fitness;

        if (evaluate.max_fitness == 83)
            int x = 5;

        evaluate.max_fitness = 0;
        generation next_gen = std::move(select.elitism(gen));
        //generation next_gen;

        while(next_gen.size() < generation_size * (1 - crossover_rate))
        {
            index_pair parents = select.ranking(gen);
        //    qDebug() << parents.first << " , " << parents.second;
            next_gen.push_back(gen[parents.first]);
            next_gen.push_back(gen[parents.second]);
        }
        while (next_gen.size() < generation_size)
        {
            index_pair parents = select.ranking(gen);
            recombiner::children_pair children = recombine(gen[parents.first], gen[parents.second]);

            next_gen.push_back(std::move(children.first));
            next_gen.push_back(std::move(children.second));
        }

        for_each_chromosome(next_gen.begin() + select.elitism_rate, next_gen.end(), mutate);
        for_each_chromosome(next_gen.begin(), next_gen.end(), evaluate);

        gen = std::move(next_gen);
        i++;
        qDebug() << "generation: " << i;

        if(prev_max == evaluate.max_fitness)
            ++gen_counter;
        else
        {
            gen_counter = 0;
            prev_max = evaluate.max_fitness;
        }

        if (gen_counter == 2000)
        {
            for_each_chromosome(gen.begin(), gen.end(), [this](auto& c)
            {
                mutate.mutate_time(c);

                for (int i = 0; i < c.schedule.size(); ++i)
                        std::random_shuffle(c.schedule[i].begin(), c.schedule[i].end());

                std::random_shuffle(c.schedule.begin(), c.schedule.end());

//                mutate.mutate_day(c);
//                mutate.mutate_time(c);
//                mutate.swap_rooms(c);
//                mutate.swap_days(c);
            });

            gen_counter = 0;
        }
    }

//    int x = 5;
    double max_fit = gen[0].fitness;
    chromosome res = gen[0];
    for(int i = 1; i < gen.size(); ++i)
        if(max_fit < gen[i].fitness)
        {
            max_fit = gen[i].fitness;
            res = gen[i];

        }
    //auto it = std::max_element(gen.begin(), gen.end(), [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });

    return res;
}
