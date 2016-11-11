#include <exception>
#include "../Scanner.h"


IF::IF() {
    cond = NULL;
    stmtSeq1 = NULL;
    stmtSeq2 = NULL;
}

bool IF::matches(Token* token) {
    return dynamic_cast<IF*> (token) != NULL;
}

void IF::parse() {
	// Check if IF token
    if (!matches(scanner->getCurrentToken())) {
		throw("Expecting " + toString() + ", recieved " + scanner->getCurrentToken()->toString());
    }
    scanner->getNextToken();

    cond = new COND();
    cond->parse();

    THEN then;
    then.parse();

    stmtSeq1 = new STMTSEQ();
    stmtSeq1->parse();

	// Handle optional else statement
    if (ELSE::matches(scanner->getCurrentToken())) {
        ELSE elseToken;
        elseToken.parse();

        stmtSeq2 = new STMTSEQ();
        stmtSeq2->parse();
    }

    ENDIF endif;
    endif.parse();

    SEMICOLON semicolon;
    semicolon.parse();
}

int IF::exec() {
    int value = 0;

    if (cond->exec()) {
        value = stmtSeq1->exec();
    } else if (stmtSeq2) {
        value = stmtSeq2->exec();
    }

    return value;
}

void IF::print() {

}

std::string IF::toString() {
    return "if";
}
