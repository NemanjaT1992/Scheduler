#include "time_table.h"

time_table::time_table()
{
    table.resize(5);
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

void time_table::push_back(int ind, class_data cl_data)
{
    table[ind].push_back(std::move(cl_data));
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
        for(int j=0; j<table.at(i).size(); ++j)
        {
            qDebug() << i << "," << j;
            class_data cl_data = table.at(i).at(j);
//            if(cl_data)
//                qDebug() << "cl_data:";
            cl_data.print();
        }
}












