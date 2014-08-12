#include "Parser.h"
#include <boost/algorithm/string/join.hpp>
#include <ostream>
#include <cctype>

Parser::Parser(std::istream_iterator<char> src) : lookahead(src) {}

void Parser::expr() {
    term();
    std::istream_iterator<char> eos;
    while(lookahead != eos) {
        switch(*lookahead) {
            case '+': match('+'); term(); std::cout << "+"; break;
            case '-': match('-'); term(); std::cout << "-"; break;
            default: std::cerr << "Syntax error" << std::endl; exit(1);
        }
    }
}

void Parser::term() {
    char c = *lookahead;
    if(isdigit(c) ) {
        std::cout << c;
        match(c);
    } else {
        std::cerr << "Syntax error" << std::endl;
        exit(1);
    }
}

void Parser::match(char const &c) {
    if( *lookahead == c ) {
        lookahead++;
    } else {
        std::cerr << "Syntax error" << std::endl;
        exit(1);
    }
}
