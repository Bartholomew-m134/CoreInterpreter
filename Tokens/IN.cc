#include <exception>
#include <iostream>
#include "../Scanner.h"


IN::IN() {
    id = NULL;
}

bool IN::matches(Token* token) {
    return dynamic_cast<IN*> (token) != NULL;
}

void IN::parse() {
	// Check if input token
    if (!matches(scanner->getCurrentToken())) {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    id = new ID(scanner->getCurrentToken()->toString());
    id->parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int IN::exec() {
    int value = 0;

    std::cin >> value;
    scanner->setVariableValue(id, value);

    return value;
}

void IN::print() {

}

std::string IN::toString() {
    return "input";
}
