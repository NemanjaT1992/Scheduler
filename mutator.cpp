#include "mutator.h"
#include "range.h"

mutator::mutator(int mutation_rate)
    : probability_distribution(0, 1000)
//    , mutation_rate(5)
    , mutation_rate(mutation_rate)
    , handlers({ &mutator::mutate_day, &mutator::mutate_time, &mutator::swap_rooms, &mutator::swap_days })
{

}

void mutator::operator()(chromosome& c)
{
    int probability = random(probability_distribution);

    if (probability < mutation_rate)
    {
        auto handler_index = range::distribution_of(handlers);
        int index = random(handler_index);

        auto handler = handlers[index];
        (this->*handler)(c);
    }
}

void mutator::mutate_day(chromosome &c)
{
    mutate_base(c, [](auto& table, auto& random, auto& day_index, int day1, int class_)
    {
        int day2 = random(day_index);

        auto cl_data = table[day1][class_];
        table[day1].erase(table[day1].begin() + class_);

        table[day2].push_back(cl_data);
    });
}

void mutator::mutate_time(chromosome& c)
{
    mutate_base(c, [](auto& table, auto& random, auto& day_index, int day, int class_)
    {
        auto time_range = range::distribution_of(type::hours);
        int8_t value = random(time_range);

        table[day][class_].time = value;
    });
}

void mutator::swap_days(chromosome& c)
{
    auto room_index = range::distribution_of(c.schedule);
    auto day_index = range::distribution_of(type::day);

    int room = random(room_index);

    int first = random(day_index);
    int second = random(day_index);

    std::swap(c.schedule[room][first],
            c.schedule[room][second]);
}

void mutator::swap_rooms(chromosome& c)
{
    auto room_index = range::distribution_of(c.schedule);

    int first = random(room_index);
    int second = random(room_index);

    std::swap(c.schedule[first],
            c.schedule[second]);

    int x = 5;
}

template<typename F>
void mutator::mutate_base(chromosome& c, F&& f)
{
    auto room_index = range::distribution_of(c.schedule);
    int room = random(room_index);

    auto& table = c.schedule[room];
    auto day_index = range::distribution_of(type::day);
    int day = random(day_index);

    auto class_index = range::distribution_of(table[day]);
    int class_ = random(class_index);

    if(class_ == table[day].size())
    {
        swap_days(c);
        return;
    }

    f(table, random, day_index, day, class_);
}
