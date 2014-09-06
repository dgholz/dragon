#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>

namespace lexer {
    struct Token {
        bool match(std::istreambuf_iterator);
        std::vector<std::tuple>& add_payload(std::vector &v)
    }
}

#endif
