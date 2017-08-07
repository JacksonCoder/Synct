#ifndef TOKEN_H
#define TOKEN_H
#include "definitions.h"
class Token
{
	TokenType tokentype;
	int line;
	int scope;
	public:
	Token(TokenType);
	void setLine(int);
	void setScope(int);
	int getLine();
	int getScope();
	TokenType type();
};
#endif
