#ifndef TAG_H
#define TAG_H

#include <ostream>

#define XTAGS \
    X(HI) \
    X(HELLO)

enum class Tag {
#define X(t) t,
    XTAGS
#undef X
    END_OF_INPUT,
};

std::ostream& operator<<(std::ostream &os, Tag const &t) {
    switch(t) {
#define X(t) case Tag::t: os << #t; break;
        XTAGS
#undef X
        case Tag::END_OF_INPUT: os << "END_OF_INPUT"; break;
    };
    return os;
}

#endif
