#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include "gmThread.h"
#include "gmCall.h"

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

int GM_CDECL gm_myMultiply( gmThread *a_thread )
{
	GM_CHECK_NUM_PARAMS(2);
	GM_CHECK_INT_PARAM( a_x, 0 );
	GM_CHECK_INT_PARAM( a_y, 1 );
	
	int ret = a_x * a_y;
	
	a_thread->PushInt( ret );
	
	return GM_OK;
}

gmFunctionEntry s_myLibrary [] =
{
	{ "myMultiply", gm_myMultiply }
};

int main()
{
	gmMachine gm;

    // Bind the function to GameMonkey
    gm.RegisterLibrary( s_myLibrary, sizeof(s_myLibrary) / sizeof(s_myLibrary[1]), 0 );
    
    	// Execute a simple script file
	gmLoadAndExecuteScript ( gm, "scripts/export_test.gm" );
    
	return 0;
} 

