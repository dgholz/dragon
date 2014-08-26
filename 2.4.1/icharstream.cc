#include "icharstream.h"

void icharstream::match(char const &c ) {
    if(operator bool()) {
        if( *lookahead == c ) {
            lookahead++;
        } else {
            std::cerr << "Syntax error: expected \"" << c << "\", saw \"" << *lookahead << "\"" << std::endl;
            exit(1);
        }
    } else {
        err_out_of_input();
    }
};

bool icharstream::err_out_of_input() const {
    std::cerr << "Syntax error: ran out of input" << std::endl;
    exit(1);
}

icharstream::char_iter const icharstream::_eos;
