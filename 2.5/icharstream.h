#ifndef ICHARSTREAM_H
#define ICHARSTREAM_H

#include <istream>
#include <iterator>
#include <cstdlib>
#include <iostream>

struct icharstream {

    typedef std::istream_iterator<char> char_iter;

    char_iter& lookahead;

    icharstream(char_iter src) : lookahead(src) {};

    void match(char const &c);

    operator bool () const { return lookahead != _eos; };

    char operator*() const { return *lookahead; };

    void check_exhausted() const {
        if( ! operator bool() ) { err_out_of_input(); }
    }

    char_iter operator++() { return ++lookahead; }

private:
    icharstream();
    static char_iter const _eos;
    bool err_out_of_input() const;

};

#endif
