#ifndef LEXER_H
#define LEXER_H

#include <cstdint>
#include <iterator>
#include "Token.h"

namespace lexer {
    struct Lexer {
        Lexer(std::istream &instr) : bis(instr), peek(bis), col(UINTMAX_C(0)), line(UINTMAX_C(0)) {};

        void skip_space();
        Token const& scan();

        std::istream &bis;
        std::istreambuf_iterator<char> peek;
        uintmax_t col;
        uintmax_t line;
    };
}

#endif
