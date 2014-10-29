#ifndef TAG_H
#define TAG_H

#include <ostream>

#define XTAGS \
    X(NUM) \
    X(PUNCT)

enum class Tag {
#define X(t) t,
    XTAGS
#undef X
    END_OF_INPUT,
};

namespace {
std::ostream& operator<<(std::ostream &os, Tag const &t) {
    switch(t) {
#define X(t) case Tag::t: os << #t; break;
        XTAGS
#undef X
        case Tag::END_OF_INPUT: os << "END_OF_INPUT"; break;
    };
    return os;
}}

#endif
