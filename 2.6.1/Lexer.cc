#include "Lexer.h"
#include <cctype>
#include <sstream>

using namespace lexer;

void Lexer::skip_space() {
    for(; std::isspace(*peek); ++peek) {
        if(isblank(*peek)) {
            ++col;
        }
        else {
            col = UINTMAX_C(0);
            ++line;
        }
    }
}

Token const& Lexer::scan() {
    skip_space();
    if(no_more_input()) {
        return EndOfInput();
    }
    std::stringstream ss;
    if(std::isdigit(*peek)) {
        while(std::isdigit(*peek)) {
            ss << *peek++;
            ++col;
        }
        uintmax_t value;
        ss >> value;
        return Num(value);
    }
    if(std::isalpha(*peek)) {
        while(std::isalnum(*peek)) {
            ss << *peek++;
            ++col;
        }
        auto f = words.emplace(ss.str(), Word(Token::Tag::ID, ss.str()));
        return f.first->second;
    }
}
