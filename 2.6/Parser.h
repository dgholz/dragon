#ifndef PARSER_H
#define PARSER_H

#include <istream>
#include <iterator>
#include <vector>
#include <string>

struct Parser {
    Parser(std::istream_iterator<char>);

    void expr();
    void term();

    std::istream_iterator<char> lookahead;
    void match(char const&);

private:
    Parser();
};

#endif
