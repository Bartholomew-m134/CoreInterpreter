#include <exception>
#include "../Scanner.h"


bool LEFTPAREN::matches(Token* token) {
    return dynamic_cast<LEFTPAREN*> (token) != NULL;
}

void LEFTPAREN::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int LEFTPAREN::exec() {
    return 0;
}

void LEFTPAREN::print() {

}

std::string LEFTPAREN::toString() {
    return "(";
}
