#include <exception>
#include "../Scanner.h"


LOOP::LOOP() {
    cond = NULL;
    stmtSeq = NULL;
}

bool LOOP::matches(Token* token) {
    return dynamic_cast<LOOP*> (token) != NULL;
}

void LOOP::parse() {
	// Check if LOOP token
    if (!matches(scanner->getCurrentToken())) {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    cond = new COND();
    cond->parse();

    BEGIN begin;
    begin.parse();

    stmtSeq = new STMTSEQ();
    stmtSeq->parse();

    ENDWHILE endwhile;
    endwhile.parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int LOOP::exec() {
    while (cond->exec()) {
        stmtSeq->exec();
    }

    return 0;
}

void LOOP::print() {

}

std::string LOOP::toString() {
    return "while";
}
