#include "b.h"
#include <iostream>

void b::S() {
    if ((bool)_ics) {
        switch(*_ics) {
            case '(': _ics.match('('); S(); _ics.match(')'); S(); break;
            case ')': break;
            default: std::cerr << "Syntax error: didn't expect \"" << *_ics << "\" here" << std::endl; exit(1);
        }
    }
}
