#ifndef FMANAGER_H
#define FMANAGER_H
#include <fstream>

class FManager
{
	std::fstream streamer;
	public:
	std::string read(std::string);
	std::string write(std::string);
};


#endif
