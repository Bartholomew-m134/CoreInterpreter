#include <exception>
#include "../Scanner.h"


bool EQUALS::matches(Token* token) {
    return dynamic_cast<EQUALS*> (token) != NULL;
}

void EQUALS::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int EQUALS::exec() {
    return 0;
}

void EQUALS::print() {

}

std::string EQUALS::toString() {
    return "=";
}
