#include <iostream>
#include "../Scanner.h"

CONST::CONST(std::string strValue) {
    this->strValue = strValue;
    value = atoi(strValue.c_str());
}

bool CONST::matches(Token* token) {
    return dynamic_cast<CONST*> (token) != NULL;
}

void CONST::parse() {
    if (matches(scanner->getCurrentToken())) {
        value = ((CONST*)scanner->getCurrentToken())->value;
        scanner->getNextToken();
    } else {
		throw("Expecting CONSTANT, recieved " + scanner->getCurrentToken()->toString());
    }

}

int CONST::exec() {
    return value;
}

void CONST::print() {

}

std::string CONST::toString() {
    return strValue;
}
