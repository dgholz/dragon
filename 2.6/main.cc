#include "icharstream.h"
#include "grammar.h"
#include <iostream>

int main( int argc, char* *argv ) {
    icharstream ics(std::cin);

    grammar g(ics);
    g();

    if(ics) {
        std::cerr << "Trailing input: ";
        while(ics) {
            std::cerr << *ics; ++ics;
        }
        std::cerr << std::endl;

        return 1;
    }
}
