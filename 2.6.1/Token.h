#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>

namespace lexer {
    struct Token {
        enum Tag { NUM, ID, TRUE, FALSE };
        Token(Tag const& t) : tag(t) {};
        Tag tag;
    };

    struct Num : Token {
        Num(int const& v) : Token(Tag::NUM), value(v) {};
        int const value;
    };

    struct Word : Token {
        std::string const lexeme;
        Word(Tag const& t, std::string const& s) : Token(t), lexeme(s) { };
    };
}

#endif
