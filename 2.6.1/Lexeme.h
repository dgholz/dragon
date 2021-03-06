#ifndef LEXEME_H
#define LEXEME_H

#include <string>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"

template<typename T> struct Lexeme {

    boost::basic_regex<T> pattern;
    Tag tag;

    Lexeme(const boost::basic_regex<T> &re, const Tag &t) : pattern(re), tag(t) {};
    Lexeme(const std::basic_string<T> &res, const Tag &t) : pattern(boost::basic_regex<T>(res)), tag(t) {};
    Lexeme(const Lexeme<T> &l) : pattern(l.pattern), tag(l.tag) {};

    bool operator==(const Lexeme<T> &l) const {
        return pattern == l.pattern && tag == l.tag;
    };

    Token<T> operator()(const boost::match_results<const T*> &match) const { return Token<T>(tag, match[0]); };
    Token<T> operator()(const std::basic_string<T> &match) const { return Token<T>(tag, match); };

};

namespace std {
    template<typename T> struct hash<const Lexeme<T>> {
        std::size_t operator()(const Lexeme<T>& l) const {
            auto p = std::hash<std::basic_string<T>>()(l.pattern.str());
            auto t = std::hash<int>()(static_cast<int>(l.tag));
            return p ^ t;
        }
    };
}

#endif
