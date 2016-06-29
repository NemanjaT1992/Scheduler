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

            child_1.schedule[i][j].clear();
            child_2.schedule[i][j].clear();

            find_class_data(c2, child_1, day_1, i, j );

            find_class_data(c1, child_2, day_2, i, j);
        }
    }

     return children_pair(child_1, child_2);
}

void recombiner::find_class_data(chromosome& reff_chromosome, chromosome& child, std::vector<class_data>& day
                                 ,int parent_room, int parent_day)
{
    std::uniform_int_distribution<> dis(0, 100);

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
                        int value = random(dis);
                       // if(value > 50)
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
        {
            int value = random(dis);
//           if(value < 50)
//               room_index = parent_room;
//           value = random(dis);
//           if(value < 50)
//               day_index = parent_day;
           child.schedule[room_index].get_table()[day_index].push_back(reff_data);
        }
    }
}


