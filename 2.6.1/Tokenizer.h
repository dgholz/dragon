#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iosfwd>
#include <unordered_map>

#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

template<typename T> struct Tokenizer {
    typedef std::unordered_map<const Lexeme<T>, std::basic_string<T>> mlex_match;
    typedef std::pair<const Lexeme<T>, std::basic_string<T>> pair_lex_match;

    Lookahead<T> p;
    std::vector<Lexeme<T>> const lexemes;
    std::basic_stringstream<T> buf;
    mlex_match best_matches;

    Tokenizer(Lookahead<T> &_p, std::vector<Lexeme<T>> const &_lexemes): p(_p), lexemes(_lexemes), buf(), best_matches() {};

    bool add_one_char();
    void cleanup_match(const std::basic_string<T> &matching_text);
    bool all_partial_match(mlex_match const &ml, std::string::size_type const &l);
    bool try_matching();
    Token<T> next();
};

#endif
