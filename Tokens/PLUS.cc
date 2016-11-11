#include <exception>
#include "../Scanner.h"


bool PLUS::matches(Token* token) {
    return dynamic_cast<PLUS*> (token) != NULL;
}

void PLUS::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int PLUS::exec() {
    return 0;
}

void PLUS::print() {

}

std::string PLUS::toString() {
    return "+";
}
