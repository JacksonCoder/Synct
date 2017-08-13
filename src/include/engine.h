#ifndef ENGINE_H
#define ENGINE_H
//engine.h
#include "lexer.h"
#include "parser.h"
#include "log.h"
#include "ast.h"
extern Engine* globalengine;
class Engine {
	Log* log;
	std::vector<Token> postlex;
	std::vector<AST*> postparse;
	std::vector<std::pair<std::string,std::string> > arguments;
	std::vector<std::string> filecontents;
	AST* postlink;
	std::string postassemble;
	void addlog(std::string,LogType,int);
	public:
		Engine(std::vector<std::pair<std::string,std::string> >);
		void lex();
		void parse();
		std::string outputLex();
		std::string outputAST();
};
#endif
