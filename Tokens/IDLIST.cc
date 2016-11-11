#include "../Scanner.h"


IDLIST::IDLIST() {
    id = NULL;
    idList = NULL;
}

bool IDLIST::matches(Token* token) {
    return dynamic_cast<IDLIST*> (token) != NULL;
}

void IDLIST::parse() {
    std::string varName = scanner->getCurrentToken()->toString();
    id = new ID(varName);
    id->parse();

	// Handle optional additional ids
    if (COMMA::matches(scanner->getCurrentToken())) {
        COMMA comma;
        comma.parse();

        idList = new IDLIST();
        idList->parse();
    }
}

int IDLIST::exec() {
    return 0;
}

void IDLIST::print() {

}

std::string IDLIST::toString() {
    return "IDLIST";
}
