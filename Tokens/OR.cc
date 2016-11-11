#include <exception>
#include "../Scanner.h"


bool OR::matches(Token* token) {
    return dynamic_cast<OR*> (token) != NULL;
}

void OR::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int OR::exec() {
    return 0;
}

void OR::print() {

}

std::string OR::toString() {
    return "or";
}
