#ifndef LEXEME_H
#define LEXEME_H

#include <string>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"

struct Lexeme {
    boost::regex const pattern;
    Tag const tag;
    boost::cmatch cmatch;

    Lexeme(boost::regex const &re, Tag const &t) : pattern(re), tag(t) {};
    Lexeme(std::string const &res, Tag const &t) : pattern(boost::regex(res)), tag(t) {};
    Token operator()() { return Token(tag, cmatch[0]); };
};

#endif
