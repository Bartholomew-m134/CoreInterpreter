#include <exception>
#include "../Scanner.h"


bool THEN::matches(Token* token) {
    return dynamic_cast<THEN*> (token) != NULL;
}

void THEN::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int THEN::exec() {
    return 0;
}

void THEN::print() {

}

std::string THEN::toString() {
    return "then";
}
