#include <fstream>
#include <typeinfo>
#include <stdlib.h>
#include <exception>

#include "Scanner.h"

using namespace std;

Scanner::Scanner(char* fileName) {
    currentToken = NULL;
    isDeclPhase = true;

    fileStream = new ifstream();
    fileStream->open(fileName);

    if (!fileStream->good()) {
		throw("File empty or could not be opened.");
    }
}

Token* Scanner::getCurrentToken() {
    return currentToken;
}

void Scanner::getNextToken() {
    string token = "";

    char c = fileStream->get();

    removeWhiteSpace(c);

    // Handle UnaryCharacters
    if (token.empty() && !fileStream->eof()) {
        getUnaryChar(token, c);
    }

    // Handle BinaryCharacters
    if (token.empty() && !fileStream->eof()) {
        getBinaryChar(token, c);
    }

    // Handle Constants
    if (token.empty() && !fileStream->eof()) {
        getConst(token, c);
    }

    // Handle Variables and Keywords
    if (token.empty() && !fileStream->eof()) {
        getAlnumString(token, c);
    }

    // Set currentToken
    if (!token.empty()) {
        currentToken = Tokenizer::createToken(token);
    } else if (fileStream->eof()) {
        currentToken = new ENDOFFILE();
    } else {
		throw("Invalid characters recieved.");
    }

    // End Declaration Phase if at begin
    if (BEGIN::matches(currentToken)) {
        isDeclPhase = false;
    }

    // Declare Variable if in Declaration Phase
    if (isDeclPhase && ID::matches(currentToken)) {
        declareVariable(currentToken);
    } else if (ID::matches(currentToken)) {
        handleIfNotDeclared(currentToken);
    }
}

/*
	Private Functions ------------------------------------------------------------
*/

void Scanner::declareVariable(Token* token) {
    bool isDeclared = !(variables.find(token->toString()) == variables.end());

    if (isDeclared) {
		throw("Variable " + token->toString() + " was already declared.");
    }

    variables[token->toString()] = make_pair(false, 0);
}

void Scanner::handleIfNotInitialized(Token* token) {
    bool isInitialized = variables[token->toString()].first;
    if (!isInitialized) {
		throw("Variable " + token->toString() + " was not initialized.");
    }
}

int Scanner::getVariableValue(Token* token) {
    handleIfNotDeclared(token);
    handleIfNotInitialized(token);

    return variables[token->toString()].second;
}

int Scanner::setVariableValue(Token* token, int value) {
    handleIfNotDeclared(token);

    variables[token->toString()] = make_pair(true, value);

    return value;
}

void Scanner::handleIfNotDeclared(Token* token) {
    bool isNotDeclared = (variables.find(token->toString()) == variables.end());

    if (isNotDeclared) {
		throw("Variable " + token->toString() + " was not declared.");
    }
}

void Scanner::removeWhiteSpace(char& c) {
    while (isspace(c)) {
        c = fileStream->get();
    }
}

void Scanner::getUnaryChar(string& token, char& c) {
    string const unaryChars = ";,!=+-*()";

    if (unaryChars.find(c) != string::npos) {
        token.push_back(c);
    }
}

void Scanner::getBinaryChar(string& token, char& c) {
    string const binaryChars = ":<";

    if (binaryChars.find(c) != string::npos) {
        token.push_back(c);

        char peek = fileStream->peek();

        if (peek == '=') {
            token.push_back(peek);
            fileStream->get();
        } else if (c == ':') {
			throw("Expected '='");
        }
    }
}

void Scanner::getConst(string& token, char& c) {
    while (isdigit(c)) {
        token.push_back(c);

        c = fileStream->peek();

        if (isdigit(c)) {
            fileStream->get();
        }
    }
}

void Scanner::getAlnumString(string& token, char& c) {
    while (isalnum(c)) {
        token.push_back(c);

        c = fileStream->peek();

        if (isalnum(c)) {
            fileStream->get();
        }
    }
}
