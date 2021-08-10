#include "stdafx.h"
#include <iostream>
#include "gmThread.h"

int GM_CDECL gmMyThreadFunc(gmThread *a_thread)
{
	std::cout << "Hello, threads!" << std::endl;
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// Bind the function to use by creating a gmFunctionObject
	gmFunctionObject *threadfunc = gm.AllocFunctionObject( gmMyThreadFunc );
	int new_threadId = 0;
	// Allocate a thread within the machine
	gm.CreateThread( gmVariable::s_null, gmVariable(threadfunc), &new_threadId );
	return 0;
}

