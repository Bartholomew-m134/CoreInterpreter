#include <exception>
#include <stdlib.h>
#include "../Scanner.h"


FACTOR::FACTOR() {
    constant = NULL;
    expr = NULL;
    id = NULL;
}

bool FACTOR::matches(Token* token) {
    return dynamic_cast<FACTOR*> (token) != NULL;
}

void FACTOR::parse() {
    Token* curToken = scanner->getCurrentToken();

    if (CONST::matches(curToken)) {
        constant = new CONST(curToken->toString());
        constant->parse();
    } else if (ID::matches(curToken)) {
        id = new ID(curToken->toString());
        id->parse();
    } else if (LEFTPAREN::matches(curToken)) {
        LEFTPAREN leftParen;
        leftParen.parse();

        expr = new EXPR();
        expr->parse();

        RIGHTPAREN rightParen;
        rightParen.parse();
    } else {
		throw("Expecting CONST, ID, or (, recieved " + scanner->getCurrentToken()->toString());
    }
}

int FACTOR::exec() {
    int value = 0;

    if (constant) {
        value = constant->exec();
    } else if (id) {
        value = scanner->getVariableValue(id);
    } else if (expr) {
        value = expr->exec();
    }

    return value;
}

void FACTOR::print() {

}

std::string FACTOR::toString() {
    return "FACTOR";
}
