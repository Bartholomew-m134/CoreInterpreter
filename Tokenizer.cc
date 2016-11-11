#include <typeinfo>
#include <stdlib.h>
#include "Tokenizer.h"

using namespace std;

Tokenizer::Tokenizer() {}

Token* Tokenizer::createToken(string type) {
	// Initialize terminal token dictionary
    map<string, Token*> dictionary;
    dictionary["("] = new LEFTPAREN();
    dictionary[")"] = new RIGHTPAREN();
    dictionary["*"] = new TIMES();
    dictionary["+"] = new PLUS();
    dictionary["-"] = new MINUS();
    dictionary[";"] = new SEMICOLON();
    dictionary["!"] = new EXCLAMATION();
    dictionary["="] = new EQUALS();
    dictionary["<"] = new LESSTHAN();
    dictionary["<="] = new LESSTHANEQUAL();
    dictionary[","] = new COMMA();
    dictionary["program"] = new PROGRAM();
    dictionary["begin"] = new BEGIN();
    dictionary["end"] = new END();
    dictionary["int"] = new INT();
    dictionary[":="] = new COLONEQUALS();
    dictionary["input"] = new IN();
    dictionary["output"] = new OUTPUT();
    dictionary["if"] = new IF();
    dictionary["then"] = new THEN();
    dictionary["else"] = new ELSE();
    dictionary["endif"] = new ENDIF();
    dictionary["while"] = new LOOP();
    dictionary["endwhile"] = new ENDWHILE();
    dictionary["or"] = new OR();

	// Set Token value
    Token* token = NULL;
	
    if (dictionary.find(type) != dictionary.end()) {
        token = dictionary.find(type)->second;
    } else if (isdigit(type[0])) {
        token = new CONST(type);
    } else if (isalpha(type[0])) {
        token = new ID(type);
    } else {
		throw("Invalid character(s), recieved ");
    }

    return token;
}
