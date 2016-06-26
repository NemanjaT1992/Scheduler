#include "mutator.h"
#include "range.h"

mutator::mutator()
    : probability_distribution(0, 1000)
    , mutation_rate(5)
    , data({ &class_data::day, &class_data::time, &class_data::count, &class_data::course, &class_data::room, &class_data::student_group })
{

}

chromosome mutator::operator()(chromosome& c)
{
    for (int i = 0; i < c.schedule.size(); ++i)
    {
        int probability = random(probability_distribution);

        if (probability < mutation_rate)
        {
            auto& table = c.schedule[i];

            std::uniform_int_distribution<> table_index(0, table.size());
            std::uniform_int_distribution<> data_index(0, data.size());

            int ti = random(table_index);
            int di = random(data_index);

            auto data_distribution = range::distribution_of(static_cast<type>(di));
            int8_t value = random(data_distribution);

            table[ti].*data[di] = value;
        }
    }

    return c;
}
