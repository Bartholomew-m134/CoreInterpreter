#include <exception>
#include "../Scanner.h"


bool COLONEQUALS::matches(Token* token) {
    return dynamic_cast<COLONEQUALS*> (token) != NULL;
}

void COLONEQUALS::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int COLONEQUALS::exec() {
    return 0;
}

void COLONEQUALS::print() {

}

std::string COLONEQUALS::toString() {
    return ":=";
}
