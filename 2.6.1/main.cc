#include <ostream>
#include <array>
#include <sstream>

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

int main( int argc, char* *argv ) {
    auto l = lexemes;
    auto p = Lookahead(std::cin);
    std::stringstream buf;

    while(!p.no_more_input()) {
        decltype(l) m({});
        buf << *p;
        for( auto lex : l ) {
            if(boost::regex_match(buf.str().c_str(), lex.cmatch, lex.pattern)) {
                m.push_back(lex);
            }
        }
        if(1==m.size()) {
            std::cout << m[0]() << std::endl;
        }
        p++;
    }
}
