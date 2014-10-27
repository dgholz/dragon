#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

#include "boost/variant.hpp"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

#include "Tag.h"

template<typename T> struct Token {
    typedef boost::variant<int, float, std::basic_string<T>> payload_t;
    typedef std::vector<payload_t> vpayload_t;
    Tag const tag;
    vpayload_t const payload;

    Token(Tag const t, payload_t const p) : tag(t), payload({p}) {};
    Token(Tag const t) : tag(t) {};
};

template<typename T> struct quote_unprintables {
    template<typename FindResultT>
    std::basic_string<T> operator()(const FindResultT& unprint_itr) const
    {
        std::basic_stringstream<T> buf;
        std::unordered_map<T, std::basic_string<T>> unprint_map {
            { '\n', "\\n" }
        };

        for (auto i: unprint_itr) {
            auto up_itr = unprint_map.find(i);
            if ( up_itr != unprint_map.end() ) {
                buf << up_itr->second;
            }
            else {
                buf << i;
            }
        }
        return buf.str();
    }
};

template<typename T> std::ostream& operator<<(std::ostream &os, Token<T> const &t) {
    os << "[ " << t.tag;
    for(auto p : t.payload) {
        os << ", ";
        if(p.type() == typeid(std::basic_string<T>)) {
            std::basic_string<T> s(boost::get<std::basic_string<T>>(p));
            boost::find_format_all(s, boost::token_finder(!boost::is_print()), quote_unprintables<T>());
            os << s;
        }
        else {
            os << p;
        }
    }
    os << " ]";
    return os;
}

#endif
