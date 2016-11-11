#include <exception>
#include "../Scanner.h"


bool ENDWHILE::matches(Token* token) {
    return dynamic_cast<ENDWHILE*> (token) != NULL;
}

void ENDWHILE::parse() {
    if (matches(scanner->getCurrentToken())) {
        scanner->getNextToken();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int ENDWHILE::exec() {
    return 0;
}

void ENDWHILE::print() {

}

std::string ENDWHILE::toString() {
    return "endwhile";
}
