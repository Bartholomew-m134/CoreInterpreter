#include <exception>
#include "../Scanner.h"


bool ENDIF::matches(Token* token) {
    return dynamic_cast<ENDIF*> (token) != NULL;
}

void ENDIF::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int ENDIF::exec() {
    return 0;
}

void ENDIF::print() {

}

std::string ENDIF::toString() {
    return "endif";
}
