#include "constraint.h"

constraint::constraint(evaluator_fn eval)
    : evaluator(std::move(eval))
{

}

constraint::constraint(const constraint& other)
{
    evaluator = other.evaluator;
}

constraint::constraint(constraint&& other)
{
    evaluator = std::move(other.evaluator);
}

constraint& constraint::operator=(const constraint& other)
{
    evaluator = other.evaluator;

    return *this;
}

constraint& constraint::operator=(constraint&& other)
{
    evaluator = std::move(other.evaluator);

    return *this;
}

double constraint::evaluate(chromosome& c)
{
    return evaluator(c);
}
