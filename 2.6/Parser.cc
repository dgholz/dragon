#include "Parser.h"

Parser::Parser(std::istream_iterator<char> src) : lookahead(src) {}

char* Parser::start() {
     return "hi";
}
