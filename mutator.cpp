#include "mutator.h"

mutator::mutator()
    : dis(0, 1000)
    , mutation_rate(5)
    , data({ &class_data::day, &class_data::time, &class_data::count, &class_data::course, &class_data::room, &class_data::student_group })
{

}

chromosome mutator::operator()(chromosome& c)
{
    int probability = random(dis);

    if (probability < mutation_rate)
    {
        std::uniform_int_distribution<> dis_index(0, data.size());
        int index = random(dis_index);


    }

    return c;
}
