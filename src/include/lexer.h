#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include <string>
#include "engine.h"
#include "token.h"
class Engine;
std::vector<Token> lex(Engine*,std::string);
#endif
