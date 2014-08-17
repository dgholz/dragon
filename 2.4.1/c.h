#ifndef C_H
#define C_H

#include "Parser.h"

struct c : Parser {

    using Parser::Parser;


    void start() { S(); };
    virtual void S();

private:
    c();
};

#endif
