#include "recombiner.h"
#include <algorithm>


#include "time_table.h"

recombiner::recombiner()
{

}

recombiner::children_pair recombiner::recombine(chromosome &c1, chromosome &c2)
{
    chromosome child1;
    chromosome child2;

    for(int i = 0; i < c1.schedule.size(); ++i)
    {
        auto& p1 = c1.schedule[i];
        auto& p2 = c2.schedule[i];

//        int intersect = std::rand() % p1.size();
        auto& child_p1(p1);
        auto& child_p2(p2);
//        std::copy(p2.begin() + intersect, p2.end(), child_p1.begin());
//        std::copy(p1.begin() + intersect, p1.end(), child_p2.begin());

//        if(int index1 = child_p1.has_same() != -1)
//        {
//            int index2 = child_p2.has_same();
//            class_data tmp =  child_p1[index1];
//            child_p1[index1] = child_p2[index2];
//            child_p2[index2] = tmp;
//        }

        child1.schedule.push_back(child_p1);
        child2.schedule.push_back(child_p2);
    }
    return children_pair(child1, child2);
}
