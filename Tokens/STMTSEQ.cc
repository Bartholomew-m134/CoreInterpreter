#include <exception>
#include "../Scanner.h"


STMTSEQ::STMTSEQ() {
    stmt = NULL;
    stmtSeq = NULL;
}

bool STMTSEQ::matches(Token* token) {
    return dynamic_cast<STMTSEQ*> (token) != NULL;
}

void STMTSEQ::parse() {
    stmt = new STMT();
    stmt->parse();

	// Handle optional extra statement sequence
    if (isExtraStmtSeq()) {
        stmtSeq = new STMTSEQ();
        stmtSeq->parse();
    }
}

int STMTSEQ::exec() {
    stmt->exec();

    if (stmtSeq) {
        stmtSeq->exec();
    }

    return 0;
}

void STMTSEQ::print() {

}

std::string STMTSEQ::toString() {
    return "STMTSEQ";
}

bool STMTSEQ::isExtraStmtSeq() {
    Token* token = scanner->getCurrentToken();

    return !(END::matches(token) || ENDIF::matches(token)
             || ENDWHILE::matches(token) || ELSE::matches(token));
}
