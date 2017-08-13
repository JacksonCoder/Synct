#ifndef PARSING_H
#define PARSING_H
#include <vector>
#include <string>
#include "definitions.h"
#include "engine.h"
#include "token.h"
#include "ast.h"
#include "node.h"
#include "engine.h"
class Engine;
extern Engine* globalengine;
AST* parse(Engine*,std::vector<Token>); //top level parser
Node* buildRoot(std::vector<Token>); //builds AST root
Node* build(std::vector<Token>); //determines type, then builds it
Node* buildCommand(std::vector<Token>,CommandType); //Builds command defined in CommandType
Node* buildContainer(std::vector<Token>,ContainerType); //Builds container defined in ContainerType
Node* buildSingleton(std::vector<Token>,SingletonType); //Builds singleton defined in SingletonType
Node* buildSequence(std::vector<Token>,SequenceType); //Builds sequence defined in SequenceType
#endif
