#include "generator.h"

generator::generator(int generation_length)
{
    this->generation_length = generation_length;
}

generation generator::generate()
{
    generation f_generation(generation_length);

    std::vector<professor> professors = repository::get_instance().get_professors();
    std::vector<course_class> courses = repository::get_instance().get_courses();

    for(int i=0; i<generation_length; ++i)
    {
        chromosome chrom;
        for(int p=0; p<professors.size(); ++p)
        {
            int professor_course_count = professors.at(p).courses.size();
            for(int c=0; c<professor_course_count; ++c)
            {
                std::uniform_int_distribution<> dis(0, 4);
                int8_t day = random(dis);
                dis = std::uniform_int_distribution<> (0, constants::hours);
                int8_t time = random(dis);
                int8_t course = professors.at(p).courses.at(c);
                int fond = courses.at(course).fond;
                int8_t count = 0;

                int last_count = 0;
                if(fond <= 2)
                {
                    count = fond;
                }
                else
                {
                    dis = std::uniform_int_distribution<> (0, 100);
                    int dividing = random(dis);
                    if(dividing < 50)
                    {
                        count = fond;
                    }
                    else
                    {
                        while(dividing >= 50)
                        {
                            std::uniform_int_distribution<> dis(0, 4);
                            day = random(dis);
                            dis = std::uniform_int_distribution<> (0, constants::hours);
                            time = random(dis);
                            int course = professors.at(p).courses.at(c);
                            dis = std::uniform_int_distribution<> (last_count* 100, fond * 100);
                            count = random(dis);
                            last_count = count/100;

                            dis = std::uniform_int_distribution<> (0, 10);
                            int8_t room = random(dis);
                            dis = std::uniform_int_distribution<> (0, 10);
                            int8_t student_group = random(dis);

                            class_data cl_data(day, time, course, count, room, student_group);
                            professors.at(p).table.push_back(cl_data);
                        }
                    }
                }
                dis = std::uniform_int_distribution<> (0, 10);
                int8_t room = random(dis);
                dis = std::uniform_int_distribution<> (0, 10);
                int8_t student_group = random(dis);

                class_data cl_data(day, time, course, count, room, student_group);
                professors.at(p).table.push_back(cl_data);
            }
            chrom.schedule.push_back(professors.at(p));
        }
        f_generation.gen.push_back(chrom);
    }
    return f_generation;
}
