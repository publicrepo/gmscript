#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"


int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// Create a global scripted function
	gm.ExecuteString(
		"global func = function(a, b) { print(\"Param 1:\", a); print(\"Param 2:\", b); };"
		);
	gmFunctionObject *func = gm.GetGlobals()->Get(&gm, "func").GetFunctionObjectSafe();
	int threadid = 0;
	gmThread *thread = gm.CreateThread(&threadid);
	thread->PushNull(); // Push 'this'
	thread->PushFunction( func );	// push function to call
	thread->PushInt(50);
	thread->PushInt(100);
	thread->PushStackFrame(2);
	thread->Sys_Execute();
	return 0;
}

