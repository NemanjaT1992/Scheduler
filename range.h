#ifndef RANGE_H
#define RANGE_H

#include <utility>
#include <random>
#include <array>
#include "time_table.h"
#include "repository.h"

enum class type
{
    hours = 0,
    day,
    course,
    room,
    professor,
    student_group
};

namespace range
{
    using index_pair = std::pair<int, int>;
    using distribution = std::uniform_int_distribution<>;
    using getter = std::pair<int, int>(*)();

    index_pair hours()
    {
        return std::make_pair(0, constants::hours);
    }

    index_pair day()
    {
        return std::make_pair(0, 4);
    }

    index_pair course()
    {
        return std::make_pair(0, repository::get_instance().courses_count());
    }

    index_pair room()
    {
        return std::make_pair(0, repository::get_instance().rooms_count());
    }

    index_pair professor()
    {
        return std::make_pair(0, repository::get_instance().professors_count());
    }

    index_pair student_group()
    {
        return std::make_pair(0, repository::get_instance().student_groups_count());
    }

    const std::array<getter, 6> types { hours, day, course, room, professor, student_group };

    template<type t>
    distribution distribution_of()
    {
        auto pair = types[static_cast<int>(t)]();

        return distribution(pair.first, pair.second);
    }

}

#endif // RANGE_H
