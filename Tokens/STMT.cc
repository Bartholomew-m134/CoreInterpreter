#include <exception>
#include "../Scanner.h"


STMT::STMT() {
    token = NULL;
}

bool STMT::matches(Token* token) {
    return dynamic_cast<STMT*> (token) != NULL;
}

void STMT::parse() {
    Token* curToken = scanner->getCurrentToken();

    if (ID::matches(curToken)) {
        token = new ASSIGN();
    } else if (IF::matches(curToken)) {
        token = new IF();
    } else if (LOOP::matches(curToken)) {
        token = new LOOP();
    } else if (IN::matches(curToken)) {
        token = new IN();
    } else if (OUTPUT::matches(curToken)) {
        token = new OUTPUT();
    } else {
		throw("Expecting id, if, while, input, or output, recieved " + scanner->getCurrentToken()->toString());
    }

    token->parse();
}

int STMT::exec() {
    return token->exec();
}

void STMT::print() {

}

std::string STMT::toString() {
    return "STMT";
}
