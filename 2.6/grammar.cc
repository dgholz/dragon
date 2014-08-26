#include "grammar.h"
#include <ostream>
#include <cctype>

void grammar::expr() {
    term();
    switch(*_ics) {
        case '+': _ics.match('+'); term(); std::cout << "+"; break;
        case '-': _ics.match('-'); term(); std::cout << "-"; break;
        default: std::cerr << "Syntax error" << std::endl; exit(1);
    }
}

void grammar::term() {
    _ics.check_exhausted();
    char c = *_ics;
    if(isdigit(c) ) {
        std::cout << c;
        _ics.match(c);
    } else {
        std::cerr << "Syntax error" << std::endl;
        exit(1);
    }
}
