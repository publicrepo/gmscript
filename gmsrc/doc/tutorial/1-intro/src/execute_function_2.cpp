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

    
    gmVariable funcName, funcFound;
    funcName.SetString( gm.AllocStringObject("myMultiply") );
    // find in global table
    funcFound = gm.GetGlobals()->Get(funcName);

    if ( funcFound.m_type != GM_FUNCTION )
    {
    	std::cout << "Failed to find 'myMultiply'";
    	return 0;
    }
    
    // Get function object from variable
    gmFunctionObject *func = reinterpret_cast<gmFunctionObject *>(funcFound.m_value.m_ref);
    
    gmThread *thread = gm.CreateThread();
    // Push empty 'this' value
    thread->Push( gmVariable::s_null );
    thread->PushFunction( func );
    
    // Push two parameters, one holding 10 and the other 2 (both integers)
    // This effectivley calls: myMutliply( 10, 2 )
    thread->PushInt( 10 );
    thread->PushInt( 2 );
    
    // Get a blank variable to grab the return
    gmVariable returnVar;
    
    // execute the thread
    int state = thread->PushStackFrame( 2 );    // NOTE! 2 parameters passed!
    if (state != gmThread::KILLED )
    {
        state = thread->Sys_Execute( &returnVar );
    }
    
    // Check the return
    if (returnVar.m_type != GM_INT)
    {
    	std::cout << "There was a problem; non-int returned from myMultiply!";
        return 0;
    }
    
    int myReturn = returnVar.m_value.m_int;
    
    std::cout << "myMultiply returned " << myReturn << std::endl;

	return 0;
} 

