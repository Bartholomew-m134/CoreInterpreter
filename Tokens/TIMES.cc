#include <exception>
#include "../Scanner.h"


bool TIMES::matches(Token* token) {
    return dynamic_cast<TIMES*> (token) != NULL;
}

void TIMES::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int TIMES::exec() {
    return 0;
}

void TIMES::print() {

}

std::string TIMES::toString() {
    return "*";
}
