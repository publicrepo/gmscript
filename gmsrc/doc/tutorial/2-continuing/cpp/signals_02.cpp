#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"
#include "gmCall.h"

int GM_CDECL gmStartAnimation(gmThread *a_thread)
{
	GM_CHECK_STRING_PARAM(a_animname, 0);
	std::cout << a_thread->ThisString() << " starting animation: " << a_animname << std::endl;
	return GM_OK;
}

int GM_CDECL gmCreateDoor(gmThread *a_thread)
{
	GM_CHECK_FUNCTION_PARAM(a_func, 0);
	// Simple example, return "TESTDOOR" as the user object
	gmStringObject *door = a_thread->GetMachine()->AllocStringObject("TESTDOOR");
	// Call passed in function as a new thread (gmCall does this under the hood)
    gmCall gmcall;
    gmcall.BeginFunction(a_thread->GetMachine(), a_func, gmVariable(door), false);
    gmcall.End();
	a_thread->PushString(door);
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	
	// Bind a create door function
	gm.GetGlobals()->Set(&gm, "createDoor", gmVariable(gm.AllocFunctionObject(gmCreateDoor)));
	gm.GetGlobals()->Set(&gm, "startAnimation", gmVariable(gm.AllocFunctionObject(gmStartAnimation)));

	const char *script = "global DoorFunction = function() \
						 {	\
							 while(true)	\
							 {	\
								print(this, \"waiting for use...\"); \
								block(\"usedoor\");	\
								this:startAnimation(\"dooropen\"); \
								sleep(5);	\
								this:startAnimation(\"doorclose\"); \
							 } \
						 }; \
						 createDoor(DoorFunction);";
							
	
	int x = gm.ExecuteString(script);
	if (x != 0)
	{
		bool first = true;
		while(first)
			std::cout << gm.GetLog().GetEntry(first) << std::endl;
	}
	else
	{
		// Open the door... fire global signal for now
		gm.Signal(gmVariable( gm.AllocStringObject("usedoor") ), GM_INVALID_THREAD, 0);
		while (1)
		{
			gm.Execute(1);
		}
	}
	return 0;
}

