#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <iterator>
#include <cstdlib> 
#include <iostream>

struct Parser {

    typedef std::istream_iterator<char> char_iter;

    char_iter& lookahead;


    Parser();
    Parser(char_iter& src) : lookahead(src) {};


    virtual void start() = 0;


    void match(char const &c ) {
        if( *lookahead == c ) {
            lookahead++;
        } else {
            std::cerr << "Syntax error" << std::endl;
            exit(1);
        }
    };

    bool more_input() { return lookahead == char_iter(); };

};

#endif
