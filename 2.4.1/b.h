#ifndef B_H
#define B_H

#include "Parser.h"

struct b : Parser {

    using Parser::Parser;


    void start() { S(); };
    virtual void S();

private:
    b();
};

#endif
