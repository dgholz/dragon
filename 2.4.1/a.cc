#include "a.h"
#include <iostream>

void a::S() {
    char_iter eos;
    if(lookahead != eos) {
        switch(*lookahead) {
            case '+': match('+'); S(); S(); break;
            case '-': match('-'); S(); S(); break;
            case 'a': match('a'); break;
            default: std::cerr << "Syntax error" << std::endl; exit(1);
        }
    }
}
