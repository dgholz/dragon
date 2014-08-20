#include "c.h"
#include <iostream>

void c::S() {
    _ics.match('0');
    switch(*_ics) {
        case '0': S(); break;
        case '1': break;
        default: std::cerr << "Syntax error: didn't expect \"" << *_ics << "\" here" << std::endl; exit(1);
    }
    _ics.match('1');
}
