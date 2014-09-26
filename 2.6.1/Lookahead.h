#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include <iterator>

struct Lookahead {
    Lookahead(std::istream &instr) :
        peek(instr)
    {}

    bool no_more_input() const { return peek == std::istreambuf_iterator<char>(); };

    typedef std::istreambuf_iterator<char> itr;
    itr peek;
    char operator *() { return *peek; };
    itr operator ++() { return peek++; };
    itr operator ++(int) { return ++peek; };
};

#endif
