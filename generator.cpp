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
    qDebug() << "generation_length:" << generation_length;

    std::vector<professor> professors = repository::get_instance().get_professors();
    std::vector<course_class> courses = repository::get_instance().get_courses();

    for(int i=0; i<generation_length; ++i)
    {
        chromosome chrom;
        chrom.schedule.clear();
        for(int p=0; p<professors.size(); ++p)
        {
            professor infoProf = professors.at(p);
            time_table tt = time_table();
//            professor prof(p, infoProf.name, infoProf.last_name, infoProf.courses, infoProf.available);

            int professor_course_count = professors.at(p).courses.size();
            qDebug() << "professor_course_count: " << professor_course_count;
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
                        while(dividing >= 50 && last_count != fond)
                        {
                            std::uniform_int_distribution<> dis(0, 4);
                            day = random(dis);
                            dis = std::uniform_int_distribution<> (0, constants::hours);
                            time = random(dis);
                            int course = professors.at(p).courses.at(c);
                            dis = std::uniform_int_distribution<> (last_count, fond);
                            count = random(dis);
                            last_count = count;

                            dis = std::uniform_int_distribution<> (0, repository::get_instance().rooms_count());
                            int8_t room = random(dis);
                            dis = std::uniform_int_distribution<> (0, repository::get_instance().student_groups_count());
                            int8_t student_group = random(dis);
                            class_data cl_data(day, time, course, count, room, student_group);
                            tt.push_back(cl_data);
//                            professors.at(p).table.push_back(cl_data);
//                            prof.table.push_back(cl_data);
//                            chrom.schedule.push_back(tt);
                        }
                    }
                }
                dis = std::uniform_int_distribution<> (0, repository::get_instance().rooms_count());
                int8_t room = random(dis);
                dis = std::uniform_int_distribution<> (0, repository::get_instance().student_groups_count());
                int8_t student_group = random(dis);

                class_data cl_data(day, time, course, count, room, student_group);
                tt.push_back(cl_data);
//                professors.at(p).table.push_back(cl_data);
//                prof.table.push_back(cl_data);
//                chrom.schedule.push_back(tt);
//                chrom.schedule.at(p).table.push_back(cl_data);
                qDebug() << c;
            }
            chrom.schedule.push_back(tt);
//            qDebug() << "chrom added:" << c;
        }
        f_generation.gen.push_back(chrom);
    }
    f_generation.print();
    return f_generation;
}
