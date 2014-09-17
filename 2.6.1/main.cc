#include "Token.h"
#include <iostream>

int main( int argc, char* *argv ) {
    lexer::Lexer l(std::cin);
    while(!l.no_more_input()) {
        lexer::Token const* t = &l.scan();
        t->ostr(std::cout);
        std::cout << ", ";
    }
    std::cout << std::endl;
}
