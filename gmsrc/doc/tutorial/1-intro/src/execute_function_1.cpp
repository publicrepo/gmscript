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
	gmLoadAndExecuteScript ( &gm, "scripts/function_test.gm" );

    
    gmVariable funcName, funcFound;
    funcName.SetString( gm.AllocStringObject("sayHello") );
    // find in global table
    funcFound = gm.GetGlobals()->Get(funcName);

    if ( funcFound.m_type != GM_FUNCTION )
    {
    	std::cout << "Failed to find 'sayHello'";
    	return 0;
    }
    
    // Get function object from variable
    gmFunctionObject *func = (gmFunctionObject *)funcFound.m_value.m_ref;
    
    gmThread *thread = gm.CreateThread();
    // Push empty 'this' value
    thread->Push( gmVariable::s_null );
    thread->PushFunction( func );
    
    // No params needed
    
    // Get a blank variable to grab the return
    gmVariable returnVar;
    
    // execute the thread
    int state = thread->PushStackFrame( 0 );
    if (state != gmThread::KILLED )
    {
        state = thread->Sys_Execute( &returnVar );
    }
    

	return 0;
} 

