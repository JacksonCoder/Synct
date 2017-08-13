#ifndef ENVIROMENT_H
#define ENVIROMENT_H
#include <string>
class Enviroment 
{
	std::string cwd;
	public:
	std::string getCWD();
	Enviroment(int,char**,char*);
};
#endif
