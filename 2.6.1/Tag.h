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
};

std::ostream& operator<<(std::ostream &os, Tag const &t) {
    switch(t) {
#define X(t) case Tag::t: os << #t; break;
        XTAGS
#undef X
    };
    return os;
}

#endif
