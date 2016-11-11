#include "../Scanner.h"


ASSIGN::ASSIGN() {
    id = NULL;
    expr = NULL;
}

bool ASSIGN::matches(Token* token) {
    return dynamic_cast<ASSIGN*> (token) != NULL;
}

void ASSIGN::parse() {
    id = new ID(scanner->getCurrentToken()->toString());
    id->parse();

    COLONEQUALS colonEquals;
    colonEquals.parse();

    expr = new EXPR();
    expr->parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int ASSIGN::exec() {
    int value = expr->exec();

    scanner->setVariableValue(id, value);

    return value;
}

void ASSIGN::print() {

}

std::string ASSIGN::toString() {
    return "ASSIGN";
}
