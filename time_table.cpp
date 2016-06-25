#include "time_table.h"

time_table::time_table()
{
}

time_table::time_table(const time_table& other)
{
    table = other.table;
}

time_table::time_table(time_table&& other)
{
    table = std::move(other.table);
}

time_table& time_table::operator=(const time_table& other)
{
    table = other.table;

    return *this;
}

time_table& time_table::operator=(time_table&& other)
{
    table = std::move(other.table);

    return *this;
}

time_table::value& time_table::operator[](int&& i)
{
    return table[i];
}

time_table::value& time_table::operator[](int& i)
{
    return table[i];
}

time_table::container::iterator time_table::begin()
{
    return table.begin();
}

time_table::container::iterator time_table::end()
{
    return table.end();
}

time_table::container::const_iterator time_table::begin() const
{
    return table.cbegin();
}

time_table::container::const_iterator time_table::end() const
{
    return table.cend();
}

time_table::container time_table::get_table()
{
    return table;
}
int time_table::size()
{
    return table.size();
}
int time_table::has_same()
{
    for(int i = 0; i < table.size(); i++)
        for(int j = i + 1; j < table.size(); ++j)
            if(table[i].course == table[j].course && table[i].student_group == table[j].student_group)
                return i;
    return -1;
}
