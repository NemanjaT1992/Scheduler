#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "chromosome.h"

class evaluator
{
    using day = std::vector<class_data>;
public:
    int max_fitness;

    evaluator();

    void operator()(chromosome& c);

     void available(int& eval, class_data& reff_data, int day_index);
     void room_time_overlap(int& eval, time_table& table, class_data& reff_data, int index, int day_index );
     void professor_time_overlap(int& eval, chromosome& c, class_data& reff_data, int index, int day_index );
     void capacity(int& eval, class_data& data, room& room);
     void time_off_limits(int& eval, class_data& data);
};

#endif // EVALUATOR_H
