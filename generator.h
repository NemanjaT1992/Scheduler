#ifndef GENERATOR_H
#define GENERATOR_H

#include "chromosome.h"
#include "generation.h"
#include "repository.h"
#include "professor.h"
#include "course_class.h"

class generator
{
public:
    generator(int generation_length);
    generation generate();

private:
    int generation_length;
};

#endif // GENERATOR_H
