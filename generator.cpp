#include "generator.h"
#include "range.h"
#include "repository.h"

generator::generator(int generation_length)
{
    this->generation_length = generation_length;
}

generation generator::generate()
{
    generation f_generation(generation_length);

    std::vector<professor> professors = repository::get_instance().get_professors();
    std::vector<course_class> courses = repository::get_instance().get_courses();

    for(int g=0; g<generation_length; ++g)
    {
       // f_generation[g].set();
        for(int j=0; j<courses.size(); ++j)
            courses[j].clear_professor_availability();
        time_table tt;

        for(int i=0; i<courses.size(); ++i)
        {
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

                tt.push_back(day, cl_data);

                f_generation[g].schedule[room].push_back(day, cl_data);
            }
        }
        qDebug() << "---------------------------------------------------chromosome" << g;
        f_generation[g].print();

        tt.print();
    }

    return f_generation;
}
