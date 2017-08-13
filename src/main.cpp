//main.cpp
//This is where the command line data is collected and passed to the compiler
#include <iostream>
#include <unistd.h>
#include "include/compilerlayer.h"
//#include "objects/compilerlayer.cpp"
int main(int argc,char** argv)
{
	char cwd[1024];
	if(getcwd(cwd,sizeof(cwd)) != NULL)
	{
		CompilerLayer* compiler = new CompilerLayer(argc,argv);
//		compiler->setEnviroment(new Enviroment(argc,argv,cwd));
//		compiler->run();
	}
	else
	{
//	error
	}
	return 0;
}
