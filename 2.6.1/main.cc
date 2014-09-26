#include <ostream>
#include <vector>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

std::vector<Lexeme> lexemes({
        Lexeme(
            ".",
            [](boost::cmatch const &m) {
                return Token(Tag::HI, 1);
            }
        ),
    });

int main( int argc, char* *argv ) {
    auto l = lexemes;
    auto p = Lookahead(std::cin);
    auto m = l[0];
    boost::cmatch g;
    boost::regex_match(*p.peek, g, m.pattern);
    Token t = m(g);
    std::cout << t << std::endl;
}
