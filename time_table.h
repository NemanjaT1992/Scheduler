#ifndef TIME_TABLE_H
#define TIME_TABLE_H

#include <vector>
#include <utility>
#include <QDebug>

namespace constants
{
    constexpr int hours = 12;

    //evaluation priorities constants
    constexpr double priority = 0.01;


}

struct class_data
{
    class_data(int8_t t, int8_t course, int8_t count, int8_t p)
        :time(t)
        ,course(course)
        ,count(count)
        ,professor(p)
//        ,student_group(s)
    {
    }

    void print()
    {
        qDebug() << "class_data:" << time << course << count << professor;
    }


    int8_t time;
    int8_t course;
    int8_t count;
    int8_t professor;
    int8_t student_group;
};

class time_table
{
private:
    using container = std::vector<std::vector<class_data>>;
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
    void push_back(int ind, class_data cl_data);

    container get_table();
    int size();
    void print();
};

#endif // TIME_TABLE_H
