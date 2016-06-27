#ifndef GENERATION_H
#define GENERATION_H

#include <utility>
#include <vector>

#include "chromosome.h"

class generation
{
private:
    int size;

public:
    std::vector<chromosome> gen;

public:
    generation();
    generation(int size);

    void insert(chromosome chr);
    void print();
};

#endif // GENERATION_H
