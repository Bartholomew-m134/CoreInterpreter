#include <exception>
#include "../Scanner.h"


bool ELSE::matches(Token* token) {
    return dynamic_cast<ELSE*> (token) != NULL;
}

void ELSE::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int ELSE::exec() {
    return 0;
}

void ELSE::print() {

}

std::string ELSE::toString() {
    return "else";
}
