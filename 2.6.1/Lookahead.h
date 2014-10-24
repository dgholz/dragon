#ifndef LOOKAHEAD_H
#define LOOKAHEAD_H

#include <iterator>

template<typename T> struct Lookahead {
    typedef std::istreambuf_iterator<T> itr;

    itr peek;

    Lookahead(): peek() {};
    Lookahead(itr &_peek): peek(_peek) {};
    Lookahead(std::basic_istream<T> &instr): peek(instr) {};

    T operator *() { return *peek; };
    itr operator ++() { return peek++; };
    itr operator ++(int) { return ++peek; };

    bool no_more_input() const { return peek == std::istreambuf_iterator<T>(); };
};

#endif
