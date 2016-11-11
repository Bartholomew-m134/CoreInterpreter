#include <exception>
#include "../Scanner.h"


TERM::TERM() {
    factor = NULL;
    term = NULL;
}

bool TERM::matches(Token* token) {
    return dynamic_cast<TERM*> (token) != NULL;
}

void TERM::parse() {
    factor = new FACTOR();
    factor->parse();

	// Handle optional multiplication
    if (TIMES::matches(scanner->getCurrentToken())) {
        TIMES times;
        times.parse();

        term = new TERM();
        term->parse();
    }
}

int TERM::exec() {
    int value = factor->exec();

    if (term) {
        value *= term->exec();
    }

    return value;
}

void TERM::print() {

}

std::string TERM::toString() {
    return "TERM";
}
