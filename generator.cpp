#include "generator.h"

generator::generator(int generation_length)
{
    this->generation_length = generation_length;
}

generation generator::generate()
{
    generation gen(generation_length);

    std::vector<professor> professors = repository::get_instance().get_professors();
    std::vector<course_class> courses = repository::get_instance().get_courses();

    for(int i=0; i<generation_length; ++i)
    {
        for(int p=0; p<professors.size(); ++p)
        {
            int professor_course_count = professors.at(p).courses.size();
            for(int c=0; c<professor_course_count; ++c)
            {
//                int day = rand()%
            }
        }
    }

    return gen;
}
