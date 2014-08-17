#include "c.h"
#include <iostream>

void c::S() {
    std::istream_iterator<char> eos;
    match('0');
    while(lookahead != eos) {
        switch(*lookahead) {
            case '0': S(); break;
            case '1': match('1'); break;
            default: std::cerr << "Syntax error" << std::endl; exit(1);
        }
    }
}
