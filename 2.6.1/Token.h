#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

#include "Tag.h"

struct Token {
    typedef int payload_t;
    Tag const tag;
    payload_t const payload;
    Token( Tag const t, payload_t const p) : tag(t), payload(p) {};
};

std::ostream& operator<<(std::ostream &os, Token const &t) {
    os << "[" << t.tag << ", " << t.payload << "]";
    return os;
}

#endif
