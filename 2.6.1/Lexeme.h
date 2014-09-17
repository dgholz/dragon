#ifndef LEXEME_H
#define LEXEME_H

#include <string>

#include <boost/regex.hpp>

#include "Token.h"

struct Lexeme {
    boost::regex const pattern;
    typedef std::function<Token(boost::cmatch)> emitter;
    emitter const emit;
    Lexeme(boost::regex const &re, emitter const &e) : pattern(re), emit(e) {};
    Lexeme(std::string const &res, emitter const &e) : pattern(boost::regex(res)), emit(e) {};
    Token operator()(boost::cmatch const &m) { return emit(m); }
};

#endif
