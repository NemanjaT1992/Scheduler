#ifndef GENERATOR_H
#define GENERATOR_H

#include "generation.h"
#include "random_generator.h"
#include "chromosome.h"
#include "professor.h"
#include "course_class.h"
#include "room.h"
#include "student_group.h"

class generator
{
public:
    generator(int generation_length);
    generation generate();

private:
    int generation_length;
    random_generator random;
};

#endif // GENERATOR_H
