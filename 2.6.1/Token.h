#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

#include "boost/variant.hpp"

#include "Tag.h"

struct Token {
    typedef boost::variant<int, float, std::string> payload_t;
    typedef std::vector<payload_t> vpayload_t;
    Tag const tag;
    vpayload_t const payload;
    Token(Tag const t, payload_t const p) : tag(t), payload({p}) {};
    Token(Tag const t) : tag(t) {};
};

std::ostream& operator<<(std::ostream &os, Token const &t) {
    os << "[" << t.tag;
    for(auto p : t.payload) {
        os << ", " << p;
    }
    os << "]";
    return os;
}

#endif
