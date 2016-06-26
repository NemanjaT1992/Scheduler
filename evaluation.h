#ifndef EVALUATION_H
#define EVALUATION_H

#include "chromosome.h"

#include "repository.h"
//int8_t day;
//int8_t time;
//int8_t course;
//int8_t count;
//int8_t room;
//int8_t student_group;
namespace evaluation
{

//master evaluation for iteration 
//depth 1 for tables time_table
//depth 2 for time_tables class_data
    double master_eval(chromosome& c)
    {
        double eval = 0;

        for(int i = 0; i < c.schedule.size(); ++i)
        {
            time_table& table = c.schedule[i];
            professor& professor = repository::get_instance().get_professor(i);
            
            //call functions here for depth 1
            
            
            for(int j = 0; j < table.size(); ++j)
            {
                eval_depth_3(eval, table, professor, table.get_table()[j]);
            }
            
        }

        return eval;
    }
    void eval_depth_3(double& eval, time_table& table, professor& professor, class_data& reff_data )
    {
        available(eval, professor, reff_data);
        same_classes(eval, reff_data, j);
        same_time_classes(eval, table, reff_data, j);
    }
    void eval_depth_2()
    {
        
    }
    void eval_depth_1()
    {
        
    }
    
    void available(double& eval, professor& p, class_data& reff_data)
    {
        //this one has to be highest or high priority
     
        std::vector<int> day = p.available[reff_data.day];
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
   

    void same_classes(double& eval, class_data& data, int i)
    {
        //must be highest priority
        for(int j = i + 1; j < table.size(); ++j)
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
    void dsa(double& eval, table& p)
    {
        
    }

    double random(chromosome& c)
    {
        return 2.0;
    }

}



#endif // EVALUATION_H
