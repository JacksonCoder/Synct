//engine.cpp
#include "../include/engine.h"
#include "../include/log.h"
#include "../include/lexer.h"
#include "../include/parser.h"
namespace local {
	std::string alpha = "abcdefghijklmnopqrstuvwxyzi_";
	std::string alphanum = "abcdefghijklmnopqrstuvwxyz0123456789_";
	std::string num = "0123456789.";
	bool isalpha(char test)
	{
		for(auto a : alpha) if(test == a) return true;
		return false;
	}
	bool isnum(char test)
	{
		for(auto a : num) if(test == a) return true;
		return false;
	}
	bool isalphanum(char test)
	{
		for(auto a : alphanum) if(test == a) return true;
		return false;
	}
}

Engine::Engine(std::vector<std::pair<std::string,std::string> > v,std::string f) : arguments(v), filecontents(f)
{}

void Engine::lex()
{
	//Runs lexing engine and dumps results into member variable postlex
	//First run basic checks
	if(filecontents.length() == 0)
	{
		lnprint("FATAL: Cannot read a blank file");
		exit(0);
	}
	//begin lexing
	for(int c_i = 0; c_i < filecontents.length(); c_i++)
	{
		for(auto l : lex_table)
		{
			//generic cases
			if(l.second[0] == filecontents[c_i])

			{
				Token t(l.first,l.second);
				postlex.push_back(t);
				break;
			}
			//specific cases
			if(local::isalpha(filecontents[c_i]))
			{
				std::string word;
				while(local::isalphanum(filecontents[c_i]))
				{
					word.push_back(filecontents[c_i]);
					c_i++;
				}
				Token t(TEXT,word);
				postlex.push_back(t);
				break;
			}
			if(local::isnum(filecontents[c_i]))
			{
				std::string number;
				while(local::isnum(filecontents[c_i]))
				{
					number.push_back(filecontents[c_i]);
					c_i++;
				}
				Token t(NUMBERTOKEN,number);
				postlex.push_back(t);
				break;
			}
		}
	}
	for(auto p : postlex)
	{
		lnprint(p.value);
	}		
}
