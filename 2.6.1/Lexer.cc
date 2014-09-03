#include "Lexer.h"
#include <cctype>

using namespace lexer;

void Lexer::skip_space() {
    for(; std::isspace(*peek); ++peek) {
        if(isblank(*peek)) {
            ++col;
        }
        else {
            col = UINTMAX_C(0);
            ++line;
        }
    }
}

Token const& Lexer::scan() {
    skip_space();
    if(std::isdigit(*peek)) {
    }

}
