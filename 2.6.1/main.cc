#include <ostream>
#include <vector>
#include <sstream>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

std::vector<const Lexeme> lexemes({
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

    while(!p.no_more_input()) {
        std::stringstream buf;
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
