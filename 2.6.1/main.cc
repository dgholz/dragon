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

    auto exit_val = 0;
    while(1) {
        auto tok = t.next();
        std::cout << tok << ", ";
        if(tok.tag == Tag::END_OF_INPUT) {
            exit_val = tok.payload.size() == 0 ? 0 : 1;
            break;
        }
    }
    std::cout << std::endl;

    return exit_val;
}
