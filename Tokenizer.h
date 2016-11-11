#include <map>
#include <string>

#include "Tokens/Tokens.h"

class Tokenizer {
public:
    static Token* createToken(std::string type);

private:
    Tokenizer();
};
