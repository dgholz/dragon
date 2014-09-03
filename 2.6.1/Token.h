#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>

namespace lexer {
    struct Token {
        enum Tag { NUM, ID, TRUE, FALSE, PUNCT, ENDOFINPUT };
        Token(Tag const& t) : tag(t) {};
        Tag tag;
        virtual std::ostream& ostr(std::ostream& os) const { os << "[ TOKEN ]"; return os; };
    };

    struct Num : Token {
        Num(int const& v) : Token(Tag::NUM), value(v) {};
        int const value;
        virtual std::ostream& ostr(std::ostream& os) const { os << "[ NUM, " << value << " ]"; return os; };
    };

    struct Word : Token {
        std::string const lexeme;
        Word(Tag const& t, std::string const& s) : Token(t), lexeme(s) { };
        virtual std::ostream& ostr(std::ostream& os) const { os << "[ WORD, " << lexeme << " ]"; return os; };
    };

    struct Punct : Token {
        char const sym;
        Punct(char const s) : Token(Tag::PUNCT), sym(s) { };
        virtual std::ostream& ostr(std::ostream& os) const { os << "[ PUNCT, " << sym << " ]"; return os; };
    };

    struct EndOfInput : Token {
        EndOfInput() : Token(Tag::ENDOFINPUT) {};
        virtual std::ostream& ostr(std::ostream& os) const { os << "[ ENDOFINPUT ]"; return os; };
    };

}

#endif
