#include "Windows.h"
#include "stdafx.h"
#include <iostream>
#include "gmThread.h"

enum
{
	SIG_ZERO,
	SIG_ONE
};

int GM_CDECL gmBlockTest(gmThread *a_thread)
{
	gmVariable blocks[] = { gmVariable(SIG_ZERO), gmVariable(SIG_ONE) };
	int ret = a_thread->GetMachine()->Sys_Block( a_thread, 2, blocks );
	if (ret == -1)
	{
		return GM_SYS_BLOCK;
	}
	a_thread->Push(blocks[ret]);
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;

	gmFunctionObject *func = gm.AllocFunctionObject( gmBlockTest );
	gm.GetGlobals()->Set(&gm, "blocktest", gmVariable(func) );

	int threadid = 0;
	gm.ExecuteString(
		"r = blocktest();"
		"print(\"signal received\", r);"
		, &threadid
		);
	gm.Execute(0);
	// Signal the thread
	gm.Signal( gmVariable(SIG_ZERO), threadid, 0 );
	gm.Execute(0);
	return 0;
}

