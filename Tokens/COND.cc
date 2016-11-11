#include <exception>
#include "../Scanner.h"


COND::COND() {
    cmpr = NULL;
    cond = NULL;
}

bool COND::matches(Token* token) {
    return dynamic_cast<COND*> (token) != NULL;
}

void COND::parse() {
    if (isCMPR()) {
        cmpr = new CMPR();
        cmpr->parse();

		// Handle optional or token
        if (OR::matches(scanner->getCurrentToken())) {
            OR orToken;
            orToken.parse();

            cond = new COND();
            cond->parse();
        }
    } else if (EXCLAMATION::matches(scanner->getCurrentToken())) {
        EXCLAMATION excl;
        excl.parse();

        LEFTPAREN left;
        left.parse();

        cond = new COND();
        cond->parse();

        RIGHTPAREN right;
        right.parse();
    } else {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
}

int COND::exec() {
    int value = 0;

    if (cmpr) {
        value = cmpr->exec();
        if (cond) {
            value = value || cond->exec();
        }
    } else {
        value = !cond->exec();
    }

    return value;
}

void COND::print() {

}

std::string COND::toString() {
    return "COND";
}

bool COND::isCMPR() {
    Token* token = scanner->getCurrentToken();

    return (CONST::matches(token) || ID::matches(token) || LEFTPAREN::matches(token));
}
