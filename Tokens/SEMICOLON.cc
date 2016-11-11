#include <exception>
#include "../Scanner.h"


bool SEMICOLON::matches(Token* token) {
    return dynamic_cast<SEMICOLON*> (token) != NULL;
}

void SEMICOLON::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int SEMICOLON::exec() {
    return 0;
}

void SEMICOLON::print() {

}

std::string SEMICOLON::toString() {
    return ";";
}
