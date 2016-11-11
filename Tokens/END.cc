#include <exception>
#include "../Scanner.h"


bool END::matches(Token* token) {
    return dynamic_cast<END*> (token) != NULL;
}

void END::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int END::exec() {
    return 0;
}

void END::print() {

}

std::string END::toString() {
    return "end";
}
