#include <exception>
#include "../Scanner.h"


bool EXCLAMATION::matches(Token* token) {
    return dynamic_cast<EXCLAMATION*> (token) != NULL;
}

void EXCLAMATION::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int EXCLAMATION::exec() {
    return 0;
}

void EXCLAMATION::print() {

}

std::string EXCLAMATION::toString() {
    return "!";
}
