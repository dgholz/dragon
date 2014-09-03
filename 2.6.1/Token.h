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

    struct Num : protected Token {
        Num(int const& v) : Token(Tag::NUM), value(v) {};
        int const value;
    };

    struct Word : protected Token {
        std::string const lexeme;
        Word(Tag tag, std::string s) : Token(tag), lexeme(s) { };
    };
}

#endif
