#include <exception>
#include "../Scanner.h"


bool LESSTHANEQUAL::matches(Token* token) {
    return dynamic_cast<LESSTHANEQUAL*> (token) != NULL;
}

void LESSTHANEQUAL::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int LESSTHANEQUAL::exec() {
    return 0;
}

void LESSTHANEQUAL::print() {

}

std::string LESSTHANEQUAL::toString() {
    return "<=";
}
