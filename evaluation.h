#ifndef EVALUATION_H
#define EVALUATION_H

#include "chromosome.h"
#include "room.h"
#include "professor.h"
#include "repository.h"

namespace evaluation
{
    using day = std::vector<class_data>;

//master evaluation for iteration 
// iterator i defines index that can be used like identificator for rooms


    double master_eval(chromosome& c)
    {
        double eval = 0;

        for(int i = 0; i < c.schedule.size(); ++i)
        {
            time_table& table = c.schedule[i];
            room& room = get::room_at(i);
            
            //call functions here for depth 1
            
            //iterator j defines day index
            for(int j = 0; j < table.size(); ++j)
            {
                day current_day = table.get_table()[j];



                for(int k = 0; k < current_day; ++k)
                {
                    class_data& reff_data = current_day[k];

                    available(eval, reff_data, j);

                    // maybe will be considered depending on recombination
                     //   same_classes(eval, reff_data, j);
                 //   same_time_classes(eval, table, reff_data, j);
                }
            }
            
        }

        return eval;
    }

    //depth 3 functions
    void available(double& eval, class_data& reff_data, int day_index)
    {
        //this one has to be highest or high priority
     
        day availability = get::professor_at(reff_data.professor).available[day_index];
        int8_t end_time = reff_data.time + reff_data.count;
        int8_t start_time = reff_data.time;
        for(int j = 0; j < day.size(); j += 2)
        {
            if(start_time >= day[j] && start_time < day[j + 1])
                eval += constants::priority;
            if(end_time > day[j] && end_time <= day[j + 1] )
                eval += constants::priority;
        }
    }
    void room_time_overlap(double& eval, time_table& table, class_data& reff_data, int index, int day_index )
    {
        day& day = table.get_table()[day_index];
        int8_t end_time = reff_data.time + reff_data.count;
        int8_t start_time = reff_data.time;
        for(int i = index + 1; i < day.size(); ++i)
        {
            int8_t other_start = day[i].time;
            int8_t other_end = other_start + day[i].count;
            if(start_time >= other_start && start_time < other_end)
                eval += constants::priority;
            if(end_time > other_start && end_time <= other_end )
                eval += constants::priority;
        }
    }
    void professor_time_overlap(double& eval, chromosome& c, class_data& reff_data, int index, int day_index )
    {
        for(int i = index + 1; i < c.schedule.size(); ++i)
        {
            day& day = c.schedule[i].get_table()[day_index];
            int8_t end_time = reff_data.time + reff_data.count;
            int8_t start_time = reff_data.time;
            for(int j = 0; j < day.size(); ++j)
            {
                if(day[i].professor == reff_data.professor)
                {
                    int8_t other_start = day[i].time;
                    int8_t other_end = other_start + day[i].count;


                    if(start_time >= other_start && start_time < other_end)
                        eval += constants::priority;
                    if(end_time > other_start && end_time <= other_end )
                        eval += constants::priority;
                }
            }
        }
    }
    void capability(double& eval, class_data& data, room& room)
    {
        if(room.seats < data.student_count)
            eval += constants::priority;
    }

    void same_classes(double& eval, class_data& data, int index)
    {
        //must be highest priority
        for(int j = index + 1; j < table.size(); ++j)
            if(data[i].course == data[j].course && data[i].student_group == data[j].student_group)
                eval += constants::priority;
    }

    void same_time_classes(double& eval, table& table, class_data& reff_data, int i)
    {
        //if timetable for each table has time intersections between classes
        //more intersections worse fitness
        
        for(int j = i + 1; j < table.get_table().size(); ++j)
        {
            auto& data = table.get_table()[j];
            if(reff_data.day == data.day)
            {
                int8_t end_time2 = data.time + data.count;
                int8_t end_time1 = reff_data.time + reff_data.count;
                if(reff_data.time >= data.time && reff_data.time < end_time2 )
                    eval += constants::priority;
                if( end_time1 > data.time && end_time1 <= end_time2  )
                    eval += constants::priority;
            }
        }            
    }


    //depth 2 functions



    //depth 1 functions
    void dsa(double& eval, table& p)
    {
        
    }

    double random(chromosome& c)
    {
        return 2.0;
    }

}



#endif // EVALUATION_H
