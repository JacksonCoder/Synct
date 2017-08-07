#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "engine.h"
#include "token.h"
class Engine;
std::vector<Token> lex(Engine*,std::string);
#endif
