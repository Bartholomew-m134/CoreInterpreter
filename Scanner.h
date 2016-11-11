#include <fstream>
#include <string>
#include "Tokenizer.h"

class Scanner {
public:
    Scanner(char* fileName);
    Token* getCurrentToken();
    void getNextToken();
    int getVariableValue(Token* token);
    int setVariableValue(Token* token, int value);

    std::ifstream* fileStream;

private:
    void declareVariable(Token* token);
    void handleIfNotDeclared(Token* token);
    void removeWhiteSpace(char& c);
    void getUnaryChar(std::string& token, char& c);
    void getBinaryChar(std::string& token, char& c);
    void getConst(std::string& token, char& c);
    void getAlnumString(std::string& token, char& c);
    void handleIfNotInitialized(Token* token);

    Token* currentToken;
    std::map<std::string, std::pair<bool, int>> variables;
    bool isDeclPhase;
};

extern Scanner* scanner;
