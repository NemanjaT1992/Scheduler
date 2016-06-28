#ifndef EVALUATION_H
#define EVALUATION_H

#include "chromosome.h"
#include "room.h"
#include "professor.h"
#include "repository.h"

class evaluation
{
    using day = std::vector<class_data>;

//master evaluation for iteration 
// iterator i defines index that can be used like identificator for rooms




//    void same_classes(double& eval, class_data& data, int index)
//    {
//        //must be highest priority
//        for(int j = index + 1; j < table.size(); ++j)
//            if(data[i].course == data[j].course && data[i].student_group == data[j].student_group)
//                eval += constants::priority;
//    }

//    void same_time_classes(double& eval, time_table& table, class_data& reff_data, int i)
//    {
//        //if timetable for each table has time intersections between classes
//        //more intersections worse fitness
        
//        for(int j = i + 1; j < table.get_table().size(); ++j)
//        {
//            auto& data = table[j];
//            if(reff_data.day == data.day)
//            {
//                int8_t end_time2 = data.time + data.count;
//                int8_t end_time1 = reff_data.time + reff_data.count;
//                if(reff_data.time >= data.time && reff_data.time < end_time2 )
//                    eval += constants::priority;
//                if( end_time1 > data.time && end_time1 <= end_time2  )
//                    eval += constants::priority;
//            }
//        }
//    }


    //depth 2 functions



    //depth 1 functions


    double random(chromosome& c)
    {
        return 2.0;
    }

}



#endif // EVALUATION_H
