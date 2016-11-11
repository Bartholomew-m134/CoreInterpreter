#include <string>


class Token {
public:
    virtual void parse() = 0;
    virtual int exec() = 0;
    virtual void print() = 0;
    virtual std::string toString() = 0;
};

/* Terminal Tokens */

class LEFTPAREN : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class RIGHTPAREN : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class TIMES : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class PLUS : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class MINUS : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class SEMICOLON : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class CONST : public Token {
public:
    CONST(std::string strValue);
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    int value;
    std::string strValue;
};

class ID : public Token {
public:
    ID(std::string varName);
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    std::string varName;
};

class ENDOFFILE : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class BEGIN : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};


class COLONEQUALS : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class ELSE : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class END : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class ENDIF : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class ENDWHILE : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class EQUALS : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class EXCLAMATION : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class INT : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class LESSTHAN : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class LESSTHANEQUAL : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class OR : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class THEN : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

class COMMA : public Token {
public:
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
};

/*----------------------------------------- Non-terminal Tokens ----------------------------------------*/

class OUTPUT : public Token {
public:
    OUTPUT();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
private:
    Token* expr;
};

class EXPR : public Token {
public:
    EXPR();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
private:
    Token* term;
    bool isAdd;
    bool isMinus;
    Token* expr;
};

class TERM : public Token {
public:
    TERM();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
private:
    Token* factor;
    Token* term;
};

class FACTOR : public Token {
public:
    FACTOR();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();
private:
    Token* constant;
    Token* id;
    Token* expr;
};

class ASSIGN : public Token {
public:
    ASSIGN();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* id;
    Token* expr;
};

class CMPR : public Token {
public:
    CMPR();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* expr1;
    Token* expr2;
    bool isEqual;
    bool isLessThan;
    bool isLessThanEqual;
};

class COND : public Token {
public:
    COND();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* cmpr;
    Token* cond;
private:
    bool isCMPR();
};

class DECLSEQ : public Token {
public:
    DECLSEQ();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* decl;
    Token* declSeq;
};

class DECL : public Token {
public:
    DECL();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* idList;
};

class IDLIST : public Token {
public:
    IDLIST();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* id;
    Token* idList;
};

class IF : public Token {
public:
    IF();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* cond;
    Token* stmtSeq1;
    Token* stmtSeq2;
};

class IN : public Token {
public:
    IN();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* id;
};

class LOOP : public Token {
public:
    LOOP();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* cond;
    Token* stmtSeq;
};

class PROGRAM : public Token {
public:
    PROGRAM();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* declSeq;
    Token* stmtSeq;
};

class STMT : public Token {
public:
    STMT();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* token;
};

class STMTSEQ : public Token {
public:
    STMTSEQ();
    static bool matches(Token* token);
    void parse();
    int exec();
    void print();
    std::string toString();

    Token* stmt;
    Token* stmtSeq;

private:
    bool isExtraStmtSeq();
};
