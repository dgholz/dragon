#ifndef TOKENIZERITERATOR_H
#define TOKENIZERITERATOR_H

#include <boost/iterator/iterator_facade.hpp>
#include <boost/optional.hpp>
#include <boost/none.hpp>

#include "Token.h"
#include "Tag.h"

template<typename T> struct Tokenizer;

template<typename T> struct TokenizerIterator : public std::iterator<std::input_iterator_tag, Token<T>> {
    boost::optional<Token<T>> tok;
    Tokenizer<T> *t;
    bool at_end;

    TokenizerIterator() : tok(boost::none), t(nullptr), at_end(true) {};
    TokenizerIterator(Tokenizer<T> *_t) : tok(), t(_t), at_end(false) {};

    TokenizerIterator<T>& operator++() {
        fetch_next();
        return *this;
    }

    bool operator !=(TokenizerIterator<T> const& t_itr) const {
        return !(this->operator==(t_itr));
    }

    bool operator ==(TokenizerIterator<T> const& t_itr) const {
        return at_end == t_itr.at_end;
    };

    Token<T> const*const operator->() {
        lazily_fetch_first();
        return &*tok;
    }

    Token<T> const& operator*() {
        lazily_fetch_first();
        return *tok;
    }

    void lazily_fetch_first() {
        if(!at_end && !tok && nullptr != t) {
            fetch_next();
        }
    }

    void fetch_next() {
        if(tok && Tag::END_OF_INPUT == tok->tag) {
            at_end = true;
        }
        else {
            tok.reset(t->next());
        }
    }
};

#endif
