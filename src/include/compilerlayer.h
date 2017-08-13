#ifndef COMPILERLAYER_H
#define COMPILERLAYER_H
//compilerlayer.h
#include "enviroment.h"
#include "engine.h"
#include "fmanager.h"
#include <string>
class CompilerLayer
{
        Enviroment* e;
        std::vector<std::pair<std::string,std::string> > arguments;
	Engine* engine;
	FManager* fmanager;
        public:
                void run();
		void setEnviroment(Enviroment*);
		CompilerLayer(int,char**);
};
#endif
