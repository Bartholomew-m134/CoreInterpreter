#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <exception>

#include "Scanner.h"


using namespace std;

Scanner* scanner;


int main(int argc, char* argv[]) {

	try {
		scanner = new Scanner(argv[1]);
		scanner->getNextToken();
		Token* token = 	scanner->getCurrentToken();

		// Interpret if valid program
		if (PROGRAM::matches(token)) {
			token->parse();
			token->exec();
		} else {
			throw("Program must start with program, recieved " + scanner->getCurrentToken()->toString());
		}
	} catch (const char* msg) {
		cout << "ERROR: " << msg << endl;
		exit(1);
	} catch (string& msg) {
		cout << "ERROR: " << msg << endl;
		exit(1);
	} catch (...) {
		cout << "ERROR: An unknown error has occurred" << endl;
		exit(1);
	}

    return 0;
}
