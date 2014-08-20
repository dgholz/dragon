#include "a.h"
#include <iostream>

void a::S() {
    _ics.check_exhausted();
    switch(*_ics) {
        case '+': _ics.match('+'); S(); S(); break;
        case '-': _ics.match('-'); S(); S(); break;
        case 'a': _ics.match('a'); break;
        default: std::cerr << "Syntax error: didn't expect \"" << *_ics << "\" here" << std::endl; exit(1);
    }
}
