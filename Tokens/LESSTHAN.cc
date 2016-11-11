#include <exception>
#include "../Scanner.h"


bool LESSTHAN::matches(Token* token) {
    return dynamic_cast<LESSTHAN*> (token) != NULL;
}

void LESSTHAN::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int LESSTHAN::exec() {
    return 0;
}

void LESSTHAN::print() {

}

std::string LESSTHAN::toString() {
    return "<";
}
