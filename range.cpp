#include "range.h"
#include "repository.h"
#include "time_table.h"

namespace range
{
    index_pair hours()
    {
        return index_pair(0, constants::hours);
    }

    index_pair day()
    {
        return index_pair(0, 4);
    }

    index_pair count()
    {
        return index_pair(0, constants::hours);
    }

    index_pair course()
    {
//        return index_pair(0, repository::get_instance().courses_count());
        return index_pair(0, get::courses().size() - 1);
    }

    index_pair room()
    {
        return index_pair(0, get::rooms().size() - 1);
    }

    index_pair professor()
    {
        return index_pair(0, get::professors().size() - 1);
    }

    index_pair student_group()
    {
        return index_pair(0, get::student_groups().size() - 1);
    }

    distribution distribution_of(type t)
    {
        auto pair = types[static_cast<int>(t)]();

        return distribution(pair.first, pair.second);
    }

}
