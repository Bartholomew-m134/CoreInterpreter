#include <iostream>
#include "../Scanner.h"


DECLSEQ::DECLSEQ() {
    decl = NULL;
    declSeq = NULL;
}

bool DECLSEQ::matches(Token* token) {
    return dynamic_cast<DECLSEQ*> (token) != NULL;
}

void DECLSEQ::parse() {
    decl = new DECL();
    decl->parse();

	// Handle optional additional declarations
    if (INT::matches(scanner->getCurrentToken())) {
        declSeq = new DECLSEQ();
        declSeq->parse();
    }
}

int DECLSEQ::exec() {
    return 0;
}

void DECLSEQ::print() {

}

std::string DECLSEQ::toString() {
    return "DECLSEQ";
}
