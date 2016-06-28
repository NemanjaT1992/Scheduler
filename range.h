#ifndef RANGE_H
#define RANGE_H

#include <utility>
#include <random>
#include <array>
#include "time_table.h"
#include "repository.h"
#include <map>

enum class type
{
    day = 0,
    hours,
    room,
    count,
    course,
    student_group,
    professor
};

using index_pair = std::pair<int, int>;

namespace range
{
//    using index_pair = std::pair<int, int>;
    using distribution = std::uniform_int_distribution<>;
    using getter = std::pair<int, int>(*)();


    index_pair hours();
    index_pair day();
    index_pair count();
    index_pair course();
    index_pair room();
    index_pair professor();
    index_pair student_group();

    static std::array<getter, 7> types = { day, hours, room, count, course, student_group, professor };

    template<typename T>
    distribution distribution_of(T&& t)
    {
        return distribution(0, t.size() ? t.size() - 1 : 0);
    }

    distribution distribution_of(type t);
}

#endif // RANGE_H
