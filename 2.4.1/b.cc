#include "b.h"
#include <iostream>

void b::S() {
    std::istream_iterator<char> eos;
    while(lookahead != eos) {
        switch(*lookahead) {
            case '+': match('+'); S(); std::cout << "+"; break;
            case '-': match('-'); S(); std::cout << "-"; break;
            default: std::cerr << "Syntax error" << std::endl; exit(1);
        }
    }
}
