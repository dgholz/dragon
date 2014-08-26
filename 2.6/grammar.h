#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <istream>
#include <iterator>
#include "icharstream.h"

struct grammar {
    grammar(icharstream ics) : _ics(ics) {};

    void expr();
    void term();

    void operator() () { expr(); };

private:
    grammar();
    icharstream _ics;
};

#endif
