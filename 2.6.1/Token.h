#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>

namespace lexer {
    struct Token {
        enum Tag { NUM, ID, TRUE, FALSE, PUNCT, ENDOFINPUT };
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

    struct Punct : Token {
        char const sym;
        Punct(char const s) : Token(Tag::PUNCT), sym(s) { };
    };

    struct EndOfInput : Token {
        EndOfInput() : Token(Tag::ENDOFINPUT) {};
    };

}

#endif
