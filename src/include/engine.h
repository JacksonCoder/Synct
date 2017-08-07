#ifndef ENGINE_H
#define ENGINE_H
//engine.h
#include "lexer.h"
#include "parser.h"
#include "log.h"
#include "ast.h"
class Engine {
	Log* log;
	std::vector<Token> postlex;
	std::vector<AST*> postparse;
	AST* postlink;
	std::string postassemble;
	void addlog(std::string,LogType,int);
	public:
		Engine(std::vector<std::string>);
		void run();
};
#endif
