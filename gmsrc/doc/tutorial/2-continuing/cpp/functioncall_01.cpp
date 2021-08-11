#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"


int GM_CDECL gmFunctionTest(gmThread *a_thread)
{
	GM_CHECK_INT_PARAM( a_param1, 0 );
	GM_CHECK_INT_PARAM( a_param2, 1 );
	std::cout << "Param 1: " << a_param1 << std::endl;
	std::cout << "Param 2: " << a_param2 << std::endl;
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	int threadid = 0;
	gmThread *thread = gm.CreateThread(&threadid);
	thread->PushNull(); // Push 'this'
	thread->PushFunction( gm.AllocFunctionObject(gmFunctionTest) );	// push function to call
	thread->PushInt(50);
	thread->PushInt(100);
	thread->PushStackFrame(2);
	return 0;
}

