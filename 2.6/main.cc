#include "Parser.h"
#include <iostream>

int main( int argc, char* *argv ) {
    Parser a(std::cin);
    a.expr();
    std::cout << std::endl;
}
