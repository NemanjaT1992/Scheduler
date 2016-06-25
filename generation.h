#ifndef GENERATION_H
#define GENERATION_H

#include <utility>
#include <vector>

#include "chromosome.h"

class generation
{
private:
    std::vector<chromosome> gen;
public:
    generation();
    generation(int size);
};

#endif // GENERATION_H
