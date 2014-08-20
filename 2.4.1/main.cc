#include "Parser.h"
#include "a.h"
#include "b.h"
#include "c.h"
#include <iostream>
#include <memory>

int main( int argc, char* *argv ) {
    std::unique_ptr<Parser> p;

    if(argc>1) {
        Parser::char_iter cin(std::cin); // blocks...
        switch(*argv[1]) {
            case 'a': p = std::unique_ptr<Parser>(new a(cin)); break;
            default: std::cerr << "choose a question a,b, or c" << std::endl; return 1;
        }
    }
    else {
        std::cerr << "choose a question a, b, or c" << std::endl;
        return 1;
    }

    p->start();
    if(p->lookahead != Parser::char_iter()) {
        std::cerr << "Trailing input: ";
        while(p->lookahead != Parser::char_iter) {
            std::cerr << *p->lookahead; p->lookahead++;
        }
        std::cerr << std::endl;

        return 1;
    }
}
