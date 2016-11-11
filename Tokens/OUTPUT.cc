#include <exception>
#include <iostream>
#include <stdlib.h>
#include "../Scanner.h"


OUTPUT::OUTPUT() {
    expr = NULL;
}

bool OUTPUT::matches(Token* token) {
    return dynamic_cast<OUTPUT*> (token) != NULL;
}

void OUTPUT::parse() {
	// Check if OUTPUT token
    if (!matches(scanner->getCurrentToken())) {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    expr = new EXPR();
    expr->parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int OUTPUT::exec() {
    int value = expr->exec();

    std::cout << value << std::endl;

    return value;
}

void OUTPUT::print() {

}

std::string OUTPUT::toString() {
    return "output";
}
