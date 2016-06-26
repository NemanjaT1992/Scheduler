#ifndef EVALUATION_H
#define EVALUATION_H

#include "chromosome.h"
#include "professor.h"

//int8_t day;
//int8_t time;
//int8_t course;
//int8_t count;
//int8_t room;
//int8_t student_group;
namespace evaluation
{
    double master_eval(chromosome& c)
    {
        double eval = 0;

        for(int i = 0; i < c.schedule.size(); ++i)
        {
            professor& professor = c.schedule[i];

            for(int j = 0; j < professor.table.size(); ++j)
            {

            }
        }

        return eval;
    }

    double available(chromosome& c)
    {
        //this one has to be highest or high priority
        double eval = 0;
        for(auto& professor : c.schedule )
            for(auto& data : professor.table.get_table())
            {
                std::vector& day = professor.avaible[data.day];
                int8_t end_time = data.time + data.count;
                int8_t start_time = data.time;
                for(int j = 0; j < day.size(); j += 2)
                {
                    if(start_time >= day[j] && start_time < day[j + 1])
                        eval += constants::priority;
                    if(end_time > day[j] && end_time <= day[j + 1] )
                        eval += constants::priority;
                }
            }
        return eval;
    }

    double same_classes(chromosome& c)
    {
        //must be highest priority
        double eval = 0;
        for(auto& professor : c.schedule)
            if(professor.table.has_same())
                eval += constants::priority;
        return eval;
    }

    double same_time_classes(chromosome& c)
    {
        //if timetable for each professor has time intersections between classes
        //more intersections worse fitness
        double eval = 0;
        for(auto& professor : c.schedule )
            for(int i = 0; i < professor.table.get_table().size() - 1; ++i)
            {
                auto& reff_data = professor.table.get_table()[i];
                for(int j = i + 1; j < professor.table.get_table().size(); ++j)
                {

                    auto& data = professor.table.get_table()[j];
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
        return eval;

    }

    double random(chromosome& c)
    {
        return 2.0;
    }

}



#endif // EVALUATION_H
