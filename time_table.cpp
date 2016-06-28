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
void time_table::print()
{
    for(int i=0; i<table.size(); ++i)
        table.at(i).print();
}
