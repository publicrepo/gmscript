#include "stdafx.h"
#include <iostream>
#include "gmThread.h"

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// A test script which creates the function we're testing
	const char *testscript = "global threadfunc = function() { print(\"Hello, threads!\"); };";
	// Execute the script to create the function in the VM
	if (gm.ExecuteString( testscript, NULL, true ))
	{
		bool first = true;
		std::cout << gm.GetLog().GetEntry(first);
		return 1;
	}

	int new_threadId = 0;
	// Allocate a thread within the machine
	gm.CreateThread( gmVariable::s_null, gm.GetGlobals()->Get(&gm, "threadfunc"), &new_threadId );
	// Execute the machine
	gm.Execute(1);

	return 0;
}

