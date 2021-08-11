#include "stdafx.h"
#include <iostream>
#include "gmThread.h"

#define GM_CHECK_THIS_NULL \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_NULL) { GM_EXCEPTION_MSG("expecting this as null"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_INT \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_INT) { GM_EXCEPTION_MSG("expecting this as int"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_FLOAT \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_FLOAT) { GM_EXCEPTION_MSG("expecting this as null"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_STRING \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_STRING) { GM_EXCEPTION_MSG("expecting this as string"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_TABLE \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_TABLE) { GM_EXCEPTION_MSG("expecting this as table"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_FUNCTION \
	 if(GM_THREAD_ARG->GetThis()->m_type != GM_FUNCTION) { GM_EXCEPTION_MSG("expecting this as function"); return GM_EXCEPTION; }

#define GM_CHECK_THIS_USER(TYPE) \
	 if(GM_THREAD_ARG->GetThis()->m_type != TYPE) { GM_EXCEPTION_MSG("expecting this as user type %d", TYPE); return GM_EXCEPTION; }


int GM_CDECL gmThisTest(gmThread *a_thread)
{
	GM_CHECK_THIS_STRING;
	std::cout << "'this' passed as " << a_thread->ThisString() << std::endl;
	return GM_OK;
}

int main(int argc, char* argv[])
{
	// Create gm virtual machine
	gmMachine	gm;
	// Bind the function to use by creating a gmFunctionObject
	gmFunctionObject *threadfunc = gm.AllocFunctionObject( gmThisTest );
	// Add function to the global table so scripts can access it
	gm.GetGlobals()->Set(&gm, "thistest", gmVariable(threadfunc) );
	// Call script to make callback, pass a variable containing "hello" as this
	const char *script = "text = \"hello\"; text:thistest( threadfunc );";
	gm.ExecuteString( script );
	return 0;
}

