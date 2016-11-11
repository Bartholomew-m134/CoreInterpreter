#include <iostream>
#include "../Scanner.h"


DECL::DECL() {
    idList = NULL;
}

bool DECL::matches(Token* token) {
    return dynamic_cast<DECL*> (token) != NULL;
}

void DECL::parse() {
    Token* intToken = new INT();
    intToken->parse();

    idList = new IDLIST();
    idList->parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int DECL::exec() {
    return 0;
}

void DECL::print() {

}

std::string DECL::toString() {
    return "DECL";
}
