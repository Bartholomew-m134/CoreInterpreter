#include <exception>
#include "../Scanner.h"


bool MINUS::matches(Token* token) {
    return dynamic_cast<MINUS*> (token) != NULL;
}

void MINUS::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int MINUS::exec() {
    return 0;
}

void MINUS::print() {

}

std::string MINUS::toString() {
    return "-";
}
