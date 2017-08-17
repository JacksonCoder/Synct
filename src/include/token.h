#ifndef TOKEN_H
#define TOKEN_H
#include "definitions.h"
class Token
{
	public: //temporary
	TokenType tokentype;
	int line;
	int scope;
	std::string value;
	Token(TokenType t,std::string s): tokentype(t),value(s) {}
	void setLine(int);
	void setScope(int);
	int getLine();
	int getScope();
	TokenType type();
};
#endif
