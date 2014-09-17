#include <ostream>
#include <vector>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"

std::vector<Lexeme> lexemes() {
    return std::vector<Lexeme> ({
        Lexeme(
            ".",
            [](boost::cmatch const &m) {
                return Token(Tag::HI, 1);
            }
        ),
    });
}

int main( int argc, char* *argv ) {
    auto l = lexemes();
    auto m = l[0];
    boost::cmatch g;
    boost::regex_match("g", g, m.pattern);
    Token t = m(g);
    std::cout << t << std::endl;
}
