#include "../Scanner.h"
#include <iostream>


EXPR::EXPR() {
    term = NULL;
    expr = NULL;
    isAdd = false;
    isMinus = false;
}

bool EXPR::matches(Token* token) {
    return dynamic_cast<EXPR*> (token) != NULL;
}

void EXPR::parse() {
    term = new TERM();
    term->parse();

	// Check for optional +, - sign
    Token* sign = NULL;
    if (PLUS::matches(scanner->getCurrentToken())) {
        sign = new PLUS();
        isAdd = true;
    } else if (MINUS::matches(scanner->getCurrentToken())) {
        sign = new MINUS();
        isMinus = true;
    }

	// Handle optional additional expression
    if (isAdd || isMinus) {
		// Consume + or -
        sign->parse();

        expr = new EXPR();
        expr->parse();
    }
}

int EXPR::exec() {
    int value = term->exec();

    if (expr) {
        if (isAdd) {
            value += expr->exec();
        } else if (isMinus) {
            value -= expr->exec();
        }
    }

    return value;
}

void EXPR::print() {

}

std::string EXPR::toString() {
    return "EXPR";
}
