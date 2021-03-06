#include "evaluator.h"

evaluator::evaluator()
    : max_fitness(0)
{

}

//master evaluation for iteration
// iterator i defines index that can be used like identificator for rooms

void evaluator::operator ()(chromosome& c)
{
    c.fitness = 0;
    for(int i = 0; i < c.schedule.size(); ++i)
    {
        time_table& table = c.schedule[i];
        room& room = get::room_at(i);

        //iterator j defines day index
        for(int j = 0; j < table.size(); ++j)
        {
            day current_day = table.get_table()[j];

            for(int k = 0; k < current_day.size(); ++k)
            {
                class_data& reff_data = current_day[k];


                available(c.fitness, reff_data, j);
                room_time_overlap(c.fitness, table, reff_data, k, j);
                professor_time_overlap(c.fitness, c, reff_data, i, j);
                capacity(c.fitness, reff_data, room);
                time_off_limits(c.fitness, reff_data);

                // maybe will be considered depending on recombination
                //   same_classes(eval, reff_data, j);
                //   same_time_classes(eval, table, reff_data, j);
            }
        }
    }
    // qDebug() << "fitnes : "<< c.fitness;
    max_fitness = c.fitness > max_fitness ? c.fitness : max_fitness;
}
void evaluator::available(int& eval, class_data& reff_data, int day_index)
{
    //this one has to be highest or high priority

    std::vector<int> availability = get::professor_at(reff_data.professor).available[day_index];
    int8_t end_time = reff_data.time + reff_data.count;
    int8_t start_time = reff_data.time;
    bool satisfy = true;
    for(int j = 0; j < availability.size(); j += 2)
        if((end_time <= availability[j + 1] && end_time > availability[j])
                || (start_time < availability[j + 1] && start_time >= availability[j])
                || (start_time <= availability[j] && end_time >= availability[j + 1]))
            return;

    eval += constants::priority;
}
void evaluator::room_time_overlap(int& eval, time_table& table, class_data& reff_data, int index, int day_index )
{
    day& day = table[day_index];
    int8_t end_time = reff_data.time + reff_data.count;
    int8_t start_time = reff_data.time;

    for(int i = 0; i < day.size(); ++i)
        if(index != i)
        {
            int8_t other_start = day[i].time;
            int8_t other_end = other_start + day[i].count;
            if((start_time < other_end && start_time >= other_start)
                    || (end_time >= other_start && end_time < other_end)
                    || (start_time <= other_start && end_time >= other_end))
                return;
        }

    eval += constants::priority;
}
void evaluator::professor_time_overlap(int& eval, chromosome& c, class_data& reff_data, int index, int day_index )
{
    int8_t end_time = reff_data.time + reff_data.count;
    int8_t start_time = reff_data.time;

    for(int i = 0; i < c.schedule.size(); ++i)
    {
        if(i != index)
        {
            day& day = c.schedule[i][day_index];

            for(int j = 0; j < day.size(); ++j)
                if(day[j].professor == reff_data.professor)
                {
                    int8_t other_start = day[j].time;
                    int8_t other_end = other_start + day[j].count;
                    if((start_time < other_end && start_time >= other_start)
                            || (end_time >= other_start && end_time < other_end)
                            || (start_time <= other_start && end_time >= other_end))
                        return;
                }
        }
    }

    eval += constants::priority;
}
void evaluator::capacity(int& eval, class_data& data, room& room)
{
    if(room.seats >= data.student_count)
        eval += constants::priority;
    //    else
    //        eval -= constants::priority;
}
void evaluator::time_off_limits(int& eval, class_data& data)
{
    if(data.time + data.count <= constants::hours)
        eval += constants::priority;
    //    else
    //        eval -= constants::priority;
}
