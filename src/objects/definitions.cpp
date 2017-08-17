#include "../include/definitions.h"
std::vector<std::pair<TokenType,std::string> > lex_table = {
	{TAB,"\t"},
	{ENDLINE,"\n"},
	{OPAREN,"("},
	{CPAREN,")"},
	{ADDOP,"+"},
	{SUBTRACTOP,"-"},
	{DIVIDEOP,"/"},
	{MULTIPLYOP,"*"},
	{MODULOOP,"%"}
};
