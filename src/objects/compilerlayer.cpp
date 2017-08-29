//compilerlayer.cpp
#include "../include/compilerlayer.h"
#include "../include/log.h"
#include <fstream>
using namespace std;
namespace local {
	//move this to be a global utility
	bool v_find(std::vector<std::string> vect, std::string s)
	{
		for(auto v : vect) if(v==s) return true;
		return false;
	}
	void print_version()
	{
		lnprint("Synct: A versatile, powerful, and flexible language");
		lnprint("Developed exclusively by Jackson Lewis. All rights reserved.");
		lnprint("Synct is licensed under the MIT license. You can find more about this license online.");
		lnprint("Current version is 0.0.3");
	}
	void print_help()
	{
		lnprint("Synct Command Line guide:");
		lnprint("Usage: synct <command> <filenames> [options]");
		lnprint("Commands:");
		lnprint("compile : instructs compiler to compile files specificed");
		lnprint("version : prints version and exits");
		lnprint("help : shows compiler help");
		lnprint("Options:");
		lnprint("-debug : enables debug mode");
		lnprint("-cstdlib : Loads symbols in the C/C++ standard libraries into the global symbol table");
		lnprint("-o <file>: Specifies output file");
		lnprint("-log <file> : Copies compiler log to the designated file");
		lnprint("-cfile <file> : Parses and loads symbols from a C/C++ file");
	}
	std::vector<std::string> cmdoptions = {"compile","version","help"};
	std::vector<std::string> scommand_table = {
		"-debug"//show debug
	};
	std::vector<std::string> secommand_table = { "-cstdlib" };
	std::vector<std::string> dcommand_table = {
		"-o" //set output to certain file
	};
	std::vector<std::string> decommand_table = { "-log","-cfile" };
}
CompilerLayer::CompilerLayer(int argc,char** argv)
{
	std::vector<std::pair<std::string,std::string> > engineargs;
	if (argc == 1)
	{
		local::print_help();
		exit(0);
	}
	if(local::v_find(local::cmdoptions,string(argv[1])))
	{
		if(std::string(argv[1]) == "compile")
		{
			for(int argc_i = 2; argc_i < argc;argc_i++)
			{	
				if(local::v_find(local::scommand_table,argv[argc_i]))
					this->arguments.push_back({string(argv[argc_i]),""});
				if(local::v_find(local::secommand_table,argv[argc_i]))
					engineargs.push_back({string(argv[argc_i]),""});
				if(local::v_find(local::dcommand_table,string(argv[argc_i])))
				{
					auto argument = argv[argc_i+1];
					if(argc == argc_i + 1){ lnprint("No second piece specified for a two-piece option"); exit(0); }
					this->arguments.push_back({string(argv[argc_i]),argument});
					argc_i++;
				}
				if(local::v_find(local::decommand_table,string(argv[argc_i])))
                                {
                                        auto argument = argv[argc_i+1];
					if(argc == argc_i + 1){ lnprint("No second piece specified for a two-piece option"); exit(0); }
                                        engineargs.push_back({string(argv[argc_i]),argument});
                                        argc_i++;
                                }
				
			}
			//put this logic in fmanager structure later
			std::string outfile;
			for(auto a : arguments) if(a.first == "-o") outfile = a.second;
			fstream f;
			f.open(outfile);
			if(!f.is_open())
			{
				lnprint("Could not open the file '" + outfile + "'");
				exit(0);
			}
			std::string fcontents;
			while(!f.eof())
			{
				std::string temp;
				getline(f,temp,'\n');
				fcontents += temp + "\n";
			}
			lnprint(fcontents);
			this->engine = new Engine(engineargs,fcontents);
			engine->lex();
			//engine->printLex();
			//engine->parse();
			//engine->printAST();
		}
		else if(std::string(argv[1]) == "version")
		{
			local::print_version();
			exit(0);
		}
		else if(std::string(argv[1]) == "help")
		{
			local::print_help();
			exit(0);
		}
	}
	else
	{
		lnprint("Invalid first argument!");
		local::print_help();
		exit(0);
	}
}
