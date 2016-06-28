#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "chromosome.h"

class evaluator
{
    using day = std::vector<class_data>;
public:
    double max_fitness;

    evaluator();

    void operator()(chromosome& c);

     void available(double& eval, class_data& reff_data, int day_index);
     void room_time_overlap(double& eval, time_table& table, class_data& reff_data, int index, int day_index );
     void professor_time_overlap(double& eval, chromosome& c, class_data& reff_data, int index, int day_index );
     void capability(double& eval, class_data& data, room& room);
};

#endif // EVALUATOR_H
