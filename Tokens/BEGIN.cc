#include <exception>
#include "../Scanner.h"


bool BEGIN::matches(Token* token) {
    return dynamic_cast<BEGIN*> (token) != NULL;
}

void BEGIN::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int BEGIN::exec() {
    return 0;
}

void BEGIN::print() {

}

std::string BEGIN::toString() {
    return "begin";
}
