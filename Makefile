CC=g++

CFLAGS=-g -std=c++0x
TESTDIR=./SampleTests

all:
	$(CC) $(CFLAGS) -o CoreInterpreter Scanner.h Tokenizer.h Tokens/*.h Interpreter.cc Scanner.cc Tokenizer.cc Tokens/*.cc
	
test:
	CoreInterpreter $(TESTDIR)/good1.code < $(TESTDIR)/good1.data | diff $(TESTDIR)/good1.expected -
	CoreInterpreter $(TESTDIR)/good2.code < $(TESTDIR)/good2.data | diff $(TESTDIR)/good2.expected -
	CoreInterpreter $(TESTDIR)/good3.code < $(TESTDIR)/good3.data | diff $(TESTDIR)/good3.expected -
	CoreInterpreter $(TESTDIR)/good4.code < $(TESTDIR)/good4.data | diff $(TESTDIR)/good4.expected -
	CoreInterpreter $(TESTDIR)/good5.code < $(TESTDIR)/good5.data | diff $(TESTDIR)/good5.expected -
	CoreInterpreter $(TESTDIR)/bad1.code < $(TESTDIR)/bad1.data | grep "ERROR:"
	CoreInterpreter $(TESTDIR)/bad2.code < $(TESTDIR)/bad2.data | grep "ERROR:"
	CoreInterpreter $(TESTDIR)/bad3.code < $(TESTDIR)/bad3.data | grep "ERROR:"
	CoreInterpreter $(TESTDIR)/bad4.code < $(TESTDIR)/bad4.data | grep "ERROR:"
	CoreInterpreter $(TESTDIR)/bad5.code < $(TESTDIR)/bad5.data | grep "ERROR:"
