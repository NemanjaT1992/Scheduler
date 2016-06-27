#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
#include <algorithm>

#include "chromosome.h"
#include "constraint.h"
#include "mutator.h"
#include "generator.h"
#include "repository.h"
#include "range.h"

double test_eval(chromosome& c) { return 3.0; }

struct selector
{
    struct roulette {};
    struct roulette_stochastic {};
    struct ranking {};
    struct elitism {};
    struct tournament {};

    random_generator random;

    index_pair operator()(generation& gen)
    {
    }

    index_pair operator()(generation& gen, roulette)
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

    index_pair operator()(generation& gen, roulette_stochastic)
    {
//        double max_fitness = std::max_element(gen.begin(), gen.end(),
//                                              [](auto& c1, auto& c2) { return c1.fitness > c2.fitness; });

        double max_fitness = 0.9;
        std::uniform_int_distribution<> chromosome_index(0, gen.size());
        std::uniform_real_distribution<> fitness_range(0.0, 1.0);

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

    index_pair operator()(generation& gen, ranking)
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

//    index_pair operator()(generation& gen, elitism)
//    {
//        auto& chromosomes = gen.gen;
////        std::vector<chromosome> selected;
////        selected.reserve(chromosomes.size());
//        index_pair selected;

//        int elitism_rate = chromosomes.size() * 0.05;

////        std::sort(chromosomes.begin(), chromosomes.end(), [](auto& c1, auto& c2) { c1.fitness > c2.fitness; });

//        for (int i = 0; i < elitism_rate; ++i)
//            selected.push_back(chromosomes[i]);

//        return selected;
//    }

    index_pair operator()(generation& gen, tournament)
    {
        std::uniform_int_distribution<> chromosome_index(0, gen.size());

        int tournament_size = 5;
        std::vector<double> tour;
        tour.reserve(tournament_size);

        auto select = [&](auto random)
        {
            tour.clear();

            for (int j = 0; j < tournament_size; ++j);
//                tour.push_back(gen[random(chromosome_index)].fitness);

            std::sort(tour.begin(), tour.end());

            return tour.front();
        };

//        return selected;

        return index_pair(1 , 1);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    chromosome c;
//    constraint constraint1([](auto& c) { return 2.0; });
//    constraint constraint2(test_eval);

//    qDebug () << constraint1(c);
//    qDebug () << constraint2(c);

    repository::get_instance();
    generator m_generator(5);
//    m_generator.generate();

//    mutator{}(c);

    auto days = range::day();
    auto hours = range::hours();
    auto courses = range::course();
    auto rooms = range::room();
    auto professors = range::professor();

    qDebug () << days.first << days.second;
    qDebug () << hours.first << hours.second;
    qDebug () << courses.first << courses.second;
    qDebug () << rooms.first << rooms.second;
    qDebug () << professors.first << professors.second;

    auto dis = range::distribution_of(type::hours);
    range::distribution_of(type::course);

    random_generator r;
    for (int i = 0; i < 10; ++i)
        qDebug () << r(dis);

    return a.exec();
}
