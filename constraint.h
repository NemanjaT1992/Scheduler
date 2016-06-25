#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "chromosome.h"

class constraint
{
    using evaluator_fn = double(*)(chromosome&);

private:
    evaluator_fn evaluator;

public:
    constraint(evaluator_fn eval);
    constraint(const constraint& other);
    constraint(constraint&& other);

    constraint& operator=(const constraint& other);
    constraint& operator=(constraint&& other);

    double evaluate(chromosome& c);
};

#endif // CONSTRAINT_H
