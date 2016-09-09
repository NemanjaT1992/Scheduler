#include "chromosome.h"

#include <algorithm>
#include <range.h>

chromosome::chromosome()
    : fitness(0)
{
    set();
}

chromosome::chromosome(const chromosome& other)
{
    schedule = other.schedule;
    fitness = other.fitness;
}

chromosome::chromosome(chromosome&& other)
{
    schedule = std::move(other.schedule);
    fitness = std::move(other.fitness);
}

chromosome& chromosome::operator=(const chromosome& other)
{
    schedule = other.schedule;
    fitness = other.fitness;

    return *this;
}

chromosome& chromosome::operator=(chromosome&& other)
{
    schedule = std::move(other.schedule);
    fitness = std::move(other.fitness);

    return *this;
}

bool chromosome::operator==(chromosome& other)
{
    for(int i = 0; i < schedule.size(); ++i)
        if(!(schedule[i] == other.schedule[i]))
            return false;
     return true;
}

void chromosome::initialize_chrom()
{
    time_table tt;
    for(int i=0; i<get::rooms().size(); ++i)
        schedule.push_back(tt);
}

void chromosome::print()
{
    for(int i=0; i<schedule.size(); ++i)
    {
        qDebug() << "-------------room" << i;
        schedule[i].print();
    }
}

void chromosome::set()
{
    std::vector<professor> professors = repository::get_instance().get_professors();
    std::vector<course_class> courses = repository::get_instance().get_courses();

    schedule.clear();
    initialize_chrom();
    for(int i=0; i<courses.size(); ++i)
    {
        courses[i].clear_professor_availability();
        for(int c=0; c<courses.at(i).professors.size(); ++c)
        {
            auto dis = range::distribution_of(type::day);
            int8_t day = random(dis);
            int8_t course = courses.at(i).id;
            int8_t count = courses.at(i).fond;
            std::uniform_int_distribution<> dis_t(0, constants::hours - count - 1);
            int8_t time = random(dis_t);
            int8_t prof = courses.at(i).get_professor(c);
            int8_t student_count = courses.at(i).num_of_students /courses.at(i).professors.size() ;

            dis = range::distribution_of(type::room);
            int8_t room = random(dis);

            class_data cl_data(time, course, count, prof, student_count);

            schedule[room].push_back(day, cl_data);
        }
    }

}
