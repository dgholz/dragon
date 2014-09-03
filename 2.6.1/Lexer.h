#ifndef LEXER_H
#define LEXER_H

#include <cstdint>
#include <iterator>
#include <unordered_map>
#include "Token.h"

namespace lexer {
    struct Lexer {
        Lexer(std::istream &instr) :
            bis(instr),
            peek(bis),
            col(UINTMAX_C(0)),
            line(UINTMAX_C(0)),
            words(
                {
                    {"true",  Word(Token::Tag::TRUE,  "true" )},
                    {"false", Word(Token::Tag::FALSE, "false")}
                }
            )
                {};

        void skip_space();
        Token const& scan();
        bool no_more_input() const { return peek == std::istreambuf_iterator<char>(); };

        std::istream &bis;
        std::istreambuf_iterator<char> peek;
        uintmax_t col;
        uintmax_t line;
        std::unordered_map<std::string, Word const> words;
    };
}

#endif
