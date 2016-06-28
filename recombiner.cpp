#include "recombiner.h"
#include <algorithm>


#include "time_table.h"

recombiner::recombiner()
{

}

recombiner::children_pair recombiner::operator()(chromosome &c1, chromosome &c2)
{
    int size = c1.schedule.size();
    int intersect = std::rand() % size;

    chromosome child_1(c1);
    chromosome child_2(c2);

    for(int i = intersect; i < size; ++i )
    {
        time_table& time_table_1 = c1.schedule[i];
        time_table& time_table_2 = c2.schedule[i];


        for(int j = 0; j < 5; ++j)
        {
            std::vector<class_data> day_1 = time_table_1.get_table()[j];
            std::vector<class_data> day_2 = time_table_2.get_table()[j];
            int size = day_1.size() > day_2.size() ? day_1.size() : day_2.size();

            child_1.schedule[i].get_table()[j].clear();
            child_2.schedule[i].get_table()[j].clear();

            find_class_data(c2, child_1, day_1);

            find_class_data(c1, child_2, day_2);
        }
    }

    return children_pair(child_1, child_2);
}

void recombiner::find_class_data(chromosome& reff_chromosome, chromosome& child, std::vector<class_data>& day)
{
    for(int k = 0; k < day.size() ; ++k)
    {

        class_data& reff_data = day[k];


        bool found = false;
        int room_index = 0; // defines index/identificator of room
        int day_index = 0;
        while(!found && room_index < reff_chromosome.schedule.size())
        {
            time_table& other_table = reff_chromosome.schedule[room_index];

            // defines index of day
            day_index = 0;
            while (!found && day_index < 5)
            {
                std::vector<class_data> other_day = other_table[day_index];
                int n = 0; // defines index of class_data in day_array
                while (!found && n < other_day.size())
                {
                    if(other_day[n].professor == reff_data.professor && other_day[n].course == reff_data.course)
                    {
                        reff_data.time = other_day[n].time;
                        found = true;
                        break;
                    }

                    n++;
                }
                if (found)
                    break;

                day_index++;
            }
            if (found)
                break;

            room_index++;
        }

        if(found)
           child.schedule[room_index].get_table()[day_index].push_back(reff_data);
    }
}

//for(int k = 0; k < day_1.size() ; ++k)
//{

//    class_data& reff_data = day[k];


//    bool found = false;
//    int room_index = -1; // defines index/identificator of room

//    do
//    {
//        room_index++;
//        time_table& other_table = c2.schedule[room_index].get_table();
//        int day_index = -1; // defines index of day
//        do
//        {
//            day_index++;
//            std::vector<class_data> other_day = other_table[day_index];
//            int n = -1; // defines index of class_data in day_array
//            do
//            {
//                n++;
//                if(other_day[n].professor == reff_data.professor && other_day[n].course == reff_data.course)
//                {
//                    reff_data.time = other_day[n].time;
//                    found = true;
//                }

//            }while(!found && n < other_day.size());


//        }while(!found && day_index < 5);

//    }while(!found && room_index < c2.schedule.size());

//    if(found)
//       child_1.schedule[room_index].get_table()[day_index].push_back(reff_data);
//}
