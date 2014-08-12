#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <iterator>

struct Parser {
    std::istream_iterator<char> lookahead;
    Parser(std::istream_iterator<char> src);
    char* start();
private:
    Parser();
};

#endif
