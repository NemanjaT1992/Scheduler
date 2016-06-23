#ifndef TIME_TABLE_H
#define TIME_TABLE_H

#include <vector>
#include <utility>

namespace constants
{
    constexpr int hours = 12;
}

struct class_
{
    int id;
    int total;
};

class time_table
{
private:
    using container = std::vector<class_>;
    using value = container::value_type;

    container table;

public:
    time_table();
    time_table(const time_table& other);
    time_table(time_table&& other);

    time_table& operator=(const time_table& other);
    time_table& operator=(time_table&& other);

    value& operator[](int&& i);
    value& operator[](int& i);
    container::iterator begin();
    container::iterator end();
    container::const_iterator begin() const;
    container::const_iterator end() const;
};

struct professor
{
    int id;
    time_table table;
};


#endif // TIME_TABLE_H
