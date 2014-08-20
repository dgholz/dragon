#include "icharstream.h"
#include "a.h"
#include "b.h"
#include "c.h"
#include <iostream>

int main( int argc, char* *argv ) {
    icharstream ics(std::cin);

    if(argc>1) {
        switch(*argv[1]) {
            case 'a': a(ics).start(); break;
            case 'b': b(ics).start(); break;
            case 'c': c(ics).start(); break;
            default: std::cerr << "choose a question a,b, or c" << std::endl; return 1;
        }
    }
    else {
        std::cerr << "choose a question a, b, or c" << std::endl;
        return 1;
    }

    if(ics) {
        std::cerr << "Trailing input: ";
        while(ics) {
            std::cerr << *ics; ++ics;
        }
        std::cerr << std::endl;

        return 1;
    }
}
