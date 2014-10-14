#ifndef LEXEME_H
#define LEXEME_H

#include <string>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"

struct Lexeme {
    boost::regex const pattern;
    Tag const tag;

    Lexeme(const boost::regex &re, const Tag &t) : pattern(re), tag(t) {};
    Lexeme(const std::string &res, const Tag &t) : pattern(boost::regex(res)), tag(t) {};
    Token operator()(const boost::cmatch &cmatch) const { return Token(tag, cmatch[0]); };
};

#endif
