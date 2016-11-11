#include <exception>
#include "../Scanner.h"


CMPR::CMPR() {
    expr1 = NULL;
    expr2 = NULL;
    isEqual = false;
    isLessThan = false;
    isLessThanEqual = false;
}

bool CMPR::matches(Token* token) {
    return dynamic_cast<CMPR*> (token) != NULL;
}

void CMPR::parse() {
    expr1 = new EXPR();
    expr1->parse();

	// Determine if token is =, <, or <=
    Token* signToken = scanner->getCurrentToken();
    isEqual = EQUALS::matches(signToken);
    isLessThan = LESSTHAN::matches(signToken);
    isLessThanEqual = LESSTHANEQUAL::matches(signToken);

    if (!(isEqual || isLessThan || isLessThanEqual)) {
		throw("Expecting =, <, or <=, recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    expr2 = new EXPR();
    expr2->parse();
}

int CMPR::exec() {
    int value = 0;

    if (isEqual) {
        value = expr1->exec() == expr2->exec();
    } else if (isLessThan) {
        value = expr1->exec() < expr2->exec();
    } else if (isLessThanEqual) {
        value = expr1->exec() <= expr2->exec();
    }

    return value;
}

void CMPR::print() {

}

std::string CMPR::toString() {
    return "CMPR";
}
