#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include <iterator>

struct Lookahead {
    Lookahead(std::istream &instr) :
        peek(instr)
    {}

    bool no_more_input() const { return peek == std::istreambuf_iterator<char>(); };

    std::istreambuf_iterator<char> peek;
}

#endif
