#ifndef B_H
#define B_H
#include "icharstream.h"

struct b {

    b(icharstream& ics) : _ics(ics) {};

    void S();
    void operator() () { S(); };

private:
    b();
    icharstream _ics;

};

#endif
