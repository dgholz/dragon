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

    void match(char const &c ) {
        if(operator bool()) {
            if( *lookahead == c ) {
                lookahead++;
            } else {
                std::cerr << "Syntax error: expected \"" << c << "\", saw \"" << *lookahead << "\"" << std::endl;
                exit(1);
            }
        } else {
            err_out_of_input();
        }
    };

    operator bool () const { return lookahead != _eos; };

    char operator*() const { return *lookahead; };

    void check_exhausted() const {
        if( ! operator bool() ) { err_out_of_input(); }
    }

    char_iter operator++() { return ++lookahead; }

private:
    icharstream();
    char_iter _eos;
    bool err_out_of_input() const {
        std::cerr << "Syntax error: ran out of input" << std::endl;
        exit(1);
    }

};

#endif
