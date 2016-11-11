ReadMe
======

Author: 	Matt Bartholomew
Date:	11/11/2016

Summary
-------

This program is a recursive decent parser and interpreter for the Core language. 

The interpreter will receive the first Token from the global Scanner by reading each char at a time. Once the first Token has been received, the Token itself will parse for the structure it represents. This is accomplished by storing references of other Token objects it retrieves from the Scanner and parsing on each retrieved non-terminal Token.

Eventually, once the parsing has completed, the interpreter will execute the first Token, which recursively executes and calculates the corresponding values, until returning and outputting the result.

If an error or unexpected event occurs, the program will safely exit the program while explaining what the interpreter expected.


Core Language
--------

    <prog> ::= program <decl-seq> begin <stmt-seq> end
    <decl-seq> ::= <decl> | <decl><decl-seq>
    <stmt-seq> ::= <stmt> | <stmt><stmt-seq>
    
    <decl> ::= int <id-list> ;     
    <id-list> ::= id | id , <id-list>
    
    <stmt> ::= <assign> | <if> | <loop> | <in> | <out>
    <assign> ::= id := <expr> ;
    
    <in> ::= input id ;             
    <out> ::= output <expr> ;
    
    <if> ::= if <cond> then <stmt-seq> endif ;
		     | if <cond> then <stmt-seq> else <stmt-seq> endif ;
    <loop> ::= while <cond> begin <stmt-seq> endwhile ;
    
    <cond> ::= <cmpr> | ! ( <cond> ) | <cmpr> or <cond>
    <cmpr> ::= <expr> = <expr> | <expr> < <expr> | <expr> <= <expr>
    
    <expr> ::= <term> | <term> + <expr> | <term> – <expr>
    <term> ::= <factor> | <factor> * <term>
    <factor> ::= const | id | ( <expr> )


How to Run
----------

Navigate to the directory containing the MakeFile then execute

	make

After compiling, to execute the interpreter, run:

	CoreInterpreter good1.code < good1.in > good1.out
	
where good1.code is the Core language program to interpret, good1.in is the user input and good1.out is the file where all output from the CoreInterpreter will be placed.

To test the CoreInterpreter on sample test cases, run:
	
	make test


Known Issues
------------

None

	

Outside Sources
---------------

None