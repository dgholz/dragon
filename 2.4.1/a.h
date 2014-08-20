#ifndef A_H
#define A_H
#include "icharstream.h"

struct a {

    a(icharstream ics) : _ics(ics) {};

    void S();
    void operator() () { S(); };

private:
    a();
    icharstream _ics;
};

#endif
