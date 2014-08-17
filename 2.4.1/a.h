#ifndef A_H
#define A_H

#include "Parser.h"

struct a : Parser {

    using Parser::Parser;


    void S();
    virtual void start() { S(); };

private:
    a();

};

#endif
