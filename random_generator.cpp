#include "random_generator.h"

random_generator::random_generator()
    : gen(device())
{
}

int random_generator::operator()(std::uniform_int_distribution<>& distribution)
{
    return distribution(gen);
}

double random_generator::operator()(std::uniform_real_distribution<>& distribution)
{
    return distribution(gen);
}
