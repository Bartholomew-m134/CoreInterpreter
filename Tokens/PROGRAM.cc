#include <exception>
#include "../Scanner.h"


PROGRAM::PROGRAM() {
    declSeq = NULL;
    stmtSeq = NULL;
}

bool PROGRAM::matches(Token* token) {
    return dynamic_cast<PROGRAM*> (token) != NULL;
}

void PROGRAM::parse() {
	// Check if PROGRAM token
    if (!matches(scanner->getCurrentToken())) {
        throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    declSeq = new DECLSEQ();
    declSeq->parse();

    BEGIN begin;
    begin.parse();

    stmtSeq = new STMTSEQ();
    stmtSeq->parse();

    END end;
    end.parse();

    ENDOFFILE eof;
    eof.parse();
}

int PROGRAM::exec() {
    return stmtSeq->exec();
}

void PROGRAM::print() {

}

std::string PROGRAM::toString() {
    return "program";
}
