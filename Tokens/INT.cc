#include <exception>
#include "../Scanner.h"


bool INT::matches(Token* token) {
    return dynamic_cast<INT*> (token) != NULL;
}

void INT::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int INT::exec() {
    return 0;
}

void INT::print() {

}

std::string INT::toString() {
    return "int";
}
