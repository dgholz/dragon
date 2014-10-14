#include <ostream>
#include <array>
#include <sstream>
#include <unordered_map>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

std::array<const Lexeme, 2> const static lexemes({
    Lexeme(
        "[a-z]+",
        Tag::HI
    ),
    Lexeme(
        "[\n \t]",
        Tag::HELLO
    ),
});

typedef std::unordered_map<const Lexeme, boost::cmatch> mlex_match;

template<typename T> mlex_match try_matching(T lex_itr, T const &lex_end, char const * const chars) {
    mlex_match m;
    while(lex_itr != lex_end) {
        std::cout << lex_itr->tag << " match '" << chars << "'";
        boost::cmatch cmatch;
        if(boost::regex_match(chars, cmatch, lex_itr->pattern)) {
            std::cout << ": " << cmatch[0];
            m[*lex_itr] = cmatch;
        }
        std::cout << std::endl;
        ++lex_itr;
    }
    return m;
}

static bool lm_cmp(const std::pair<const Lexeme, boost::cmatch> &a, const std::pair<const Lexeme, boost::cmatch> &b) {
    return a.second.length() > b.second.length();
}

int main(int argc, char* *argv) {
    auto p = Lookahead(std::cin);
    std::stringstream buf;

    while(!p.no_more_input()) {
        buf << *p; p++;

        mlex_match what_m = try_matching(lexemes.begin(), lexemes.end(), buf.str().c_str());
        mlex_match prev_wm;
        while(!what_m.empty()) {
            buf << *p; p++;
            what_m.insert(prev_wm.begin(), prev_wm.end());
            prev_wm = what_m;
            what_m = try_matching(what_m.begin(), what_m.end(), buf.str().c_str());
        }

        auto longest = std::max_element(prev_wm.begin(), prev_wm.end(), lm_cmp);
        if(longest == prev_wm.end()) {
            std::cout << "could not match token for '" << buf.str() << "'" << std::endl;
            return 1;
        }
        auto m = longest->first( longest->second );
        std::cout << "best match was " << m << std::endl;
        buf.str( buf.str().substr( longest->second.length() - 1 ) );
    }
}
