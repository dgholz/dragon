#include <ostream>
#include <vector>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"

std::vector<Lexeme> lexemes({
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
    auto m = l[0];
    boost::cmatch g;
    boost::regex_match(*p.peek, g, m.pattern);
    Token t = m(g);
    std::cout << t << std::endl;
}
