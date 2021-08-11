#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include "gmThread.h"

int gmLoadAndExecuteScript( gmMachine &a_machine, const char *a_filename )
{
    std::ifstream file(a_filename);
    if (!file)
        return GM_EXCEPTION;
	
	std::string fileString = std::string(std::istreambuf_iterator<char>(file),
                                         std::istreambuf_iterator<char>());
	file.close();
	return a_machine.ExecuteString(fileString.c_str());
}


int main()
{
	gmMachine gm;

	// Execute a simple script file
	gmLoadAndExecuteScript ( gm, "scripts/hello.gm" );

	return 0;
} 

