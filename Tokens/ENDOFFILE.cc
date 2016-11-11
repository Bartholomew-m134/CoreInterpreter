#include <exception>
#include "../Scanner.h"


bool ENDOFFILE::matches(Token* token) {
    return dynamic_cast<ENDOFFILE*> (token) != NULL;
}

void ENDOFFILE::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int ENDOFFILE::exec() {
    return 0;
}

void ENDOFFILE::print() {

}

std::string ENDOFFILE::toString() {
    return "EOF";
}
