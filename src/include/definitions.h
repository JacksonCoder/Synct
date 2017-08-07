#ifndef DEFINITIONS_H
#define DEFINITIONS_H
//
//Parsing
//
enum CommandType {
	IMPORTCMD,
	INCLUDECMD,
	RETURNCMD,
	VARSETCMD,
	VARDECCMD,
	VARINITCMD
};
enum SequenceType {
	VARDECSEQ,
	VARINITSEQ,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULO,
	DEREFERENCE,
	FULLVAR //ex. namespace foo { int bar; } {{foo::bar}}<- = 3; 
};

enum SingletonType {
	VAR, //ex. int foo = 1; foo <-
	TYPE, //ex. int <- foo = 1;
	NUMBER, //ex. int foo = 1 <-;
	NAMESPACE, //ex int foo = somenamespace<-::constant
	MEMBER, //ex int foo = someclass.<-number;
	KEYWORD //ex const<- int foo;
};

enum ContainerType {
	IF,
	WHILE,
	FOR,
	FOREACH,
	FUNC,
	CASE,
	OBJECT,
	ENUM
};
//
//Lexing
//

enum TokenType
{
	TAB,
	ENDLINE,
	OP,
	CP,
	TEXT,
	QUOTE,
	NUMBERTOKEN,
	IMPORTKEYWORD,
	INCLUDEKEYWORD,
	RETURNKEYWORD,
	IFKEYWORD,
	ADDOP,
	SUBTRACTOP,
	DIVIDEOP,
	MULTIPLYOP,
	MODULOOP
};

//
//Logging
//

enum LogType
{
	ERROR,
	NOTE,
	DEBUG
};
#endif
