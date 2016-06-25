#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

class random_generator
{
    std::random_device device;
    std::mt19937 gen;

public:
    random_generator();

    int operator()(std::uniform_int_distribution<>& distribution);
};
#endif // RANDOM_GENERATOR_H
