#include <ostream>
#include <vector>
#include <cstdlib>

#include <boost/regex.hpp>

#include "Tag.h"
#include "Token.h"
#include "Lexeme.h"
#include "Lookahead.h"
#include "Tokenizer.h"

std::vector<Lexeme<char>> const static lexemes({
    Lexeme<char>(
        "[\\d]+",
        Tag::NUM
    ),
    Lexeme<char>(
        "[\\-+]",
        Tag::PUNCT
    ),
});

int main(int argc, char* *argv) {
    auto p = Lookahead<char>(std::cin);
    Tokenizer<char> t(p, lexemes);

    for( auto tok : t ) {
        std::cout << tok;
        if(Tag::END_OF_INPUT != tok.tag) std::cout << ", ";
    }
    std::cout << std::endl;

    return t ? EXIT_SUCCESS : EXIT_FAILURE;
}
