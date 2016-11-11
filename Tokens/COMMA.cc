#include <exception>
#include "../Scanner.h"


bool COMMA::matches(Token* token) {
    return dynamic_cast<COMMA*> (token) != NULL;
}

void COMMA::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int COMMA::exec() {
    return 0;
}

void COMMA::print() {

}

std::string COMMA::toString() {
    return ",";
}
