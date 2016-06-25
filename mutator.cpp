#include "mutator.h"

mutator::mutator()
{

}

chromosome mutator::operator()(chromosome& c)
{
    std::uniform_int_distribution<> dis(0, 100);

    for (int i = 0; i < 10; ++i)
        qDebug () << random(dis);

    return chromosome();
}
