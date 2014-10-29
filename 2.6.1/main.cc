#include <ostream>
#include <vector>

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
    Tokenizer<char> tend;

    while(t != tend) {
        std::cout << t.next() << ", ";

    }
    std::cout << std::endl;

    return 0;
}
