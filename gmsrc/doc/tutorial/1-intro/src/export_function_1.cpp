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
	// Check the number of parameters passed is correct
	if (a_thread->GetNumParams() != 2 )
        return GM_EXCEPTION;
        
    // Local vars to hold data from params
	int a_x = 0;
	int a_y = 0;
	
	// Check params are valid types
	if (a_thread->ParamType(0) != GM_INT)
        return GM_EXCEPTION;
    if (a_thread->ParamType(1) != GM_INT)
        return GM_EXCEPTION;
	
	// Get data from params
	a_x = a_thread->Param(0).m_value.m_int;
	a_x = a_thread->Param(1).m_value.m_int;
	
	// perform calculation
	int ret = a_x * a_y;
	
	// return value
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

