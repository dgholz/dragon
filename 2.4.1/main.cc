#include "icharstream.h"
#include "a.h"
#include "b.h"
#include "c.h"
#include <iostream>

template<typename T> void parse( icharstream ics ) {
    T grammar(ics);
    grammar();
}

int main( int argc, char* *argv ) {
    icharstream ics(std::cin);

    if(argc>1) {
        switch(*argv[1]) {
            case 'a': parse<a>( ics ); break;
            case 'b': parse<b>( ics ); break;
            case 'c': parse<c>( ics ); break;
            default: std::cerr << "choose a question a, b, or c" << std::endl; return 1;
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
