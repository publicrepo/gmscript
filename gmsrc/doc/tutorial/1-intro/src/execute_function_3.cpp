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


int main()
{
	gmMachine gm;

	// Execute a simple script file
	gmLoadAndExecuteScript ( gm, "scripts/function_test.gm" );

    gmCall  call;
    if ( call.BeginGlobalFunction( &gm, "myMultiply" ) )
    {
        // Push the parameters
    	call.AddParamInt( 10 );
    	// Example showing a variable can be used
    	gmVariable var( 2 );
    	call.AddParam( var );

    	// Execute the call
    	call.End();
    	// Handle the return value
    	int myReturn = 0;
    	if (call.GetReturnedInt( myReturn ) )
    	{
    		std::cout << "myMultiply returned " << myReturn << std::endl;
    	}
    	else
    	{
    		std::cout << "myMultiply returned an incorrect value" << std::endl;
    	}
    }
    else
    {
        std::cout << "Error: Could execute function 'myMultiply'" << std::endl;
    }
    
	return 0;
} 

