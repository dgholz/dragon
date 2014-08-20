#ifndef C_H
#define C_H
#include "icharstream.h"

struct c {

    c(icharstream& ics) : _ics(ics) {};

    void S();
    void operator() () { S(); };

private:
    c();
    icharstream _ics;

};

#endif
