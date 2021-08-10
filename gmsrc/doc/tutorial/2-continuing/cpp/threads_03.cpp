#include "stdafx.h"
#include <iostream>
#include "gmThread.h"

int GM_CDECL gmMyThreadFunc(gmThread *a_thread)
{
	GM_ASSERT( a_thread->GetThis()->m_type == GM_STRING );
	gmStringObject *thisstr = reinterpret_cast<gmStringObject *>(a_thread->GetThis()->m_value.m_ref);
	std::cout << "'this' passed as " << thisstr->GetString() << std::endl;
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// Bind the function to use by creating a gmFunctionObject
	gmFunctionObject *threadfunc = gm.AllocFunctionObject( gmMyThreadFunc );
	// Add function to the global table so scripts can access it
	gm.GetGlobals()->Set(&gm, "threadfunc", gmVariable(threadfunc) );
	// Call script to make callback, pass a variable containing "hello" as this
	const char *script = "text = \"hello\"; text:thread( threadfunc );";
	gm.ExecuteString( script );
	return 0;
}

