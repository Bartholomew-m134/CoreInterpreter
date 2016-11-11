#include <exception>
#include "../Scanner.h"


bool RIGHTPAREN::matches(Token* token) {
    return dynamic_cast<RIGHTPAREN*> (token) != NULL;
}

void RIGHTPAREN::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int RIGHTPAREN::exec() {
    return 0;
}

void RIGHTPAREN::print() {

}

std::string RIGHTPAREN::toString() {
    return ")";
}
