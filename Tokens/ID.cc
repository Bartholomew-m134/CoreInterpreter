#include <exception>
#include "../Scanner.h"


ID::ID(std::string varName) {
    this->varName = varName;
}

bool ID::matches(Token* token) {
    return dynamic_cast<ID*> (token) != NULL;
}

void ID::parse() {
    if (matches(scanner->getCurrentToken())) {
        varName = ((ID*)scanner->getCurrentToken())->varName;
        scanner->getNextToken();
    } else {
		throw("Expecting ID, recieved " + scanner->getCurrentToken()->toString());
    }
}

int ID::exec() {
    return 0;
}

void ID::print() {

}

std::string ID::toString() {
    return varName;
}
