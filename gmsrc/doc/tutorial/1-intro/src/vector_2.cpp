#include <iostream>
#include "gmThread.h"

class Vector
{
public:
    Vector() : x(0), y(0), z(0) { }
    Vector( float a_x, float a_y, float a_z ) : x(a_x), y(a_y), z(a_z) { }

    float x, y, z;
    
};

namespace gmVector
{

// Declare a type ID
gmType   Type   = GM_NULL;
		
int GM_CDECL default_constructor( gmThread *a_thread )
{
	// Create a native object with default params
    Vector *p = new Vector();
    a_thread->PushNewUser( p, Type );
	return GM_OK;	
}

/// This is the constructor for passed data items
int GM_CDECL data_constructor( gmThread *a_thread )
{ 
	// Check for a valid number of parameters
    if (a_thread->GetNumParams() != 3 )
        return GM_EXCEPTION;
	
    // Loop through and grab the params, checking their types
    float v[3];
    for (int i = 0; i < 3; ++i)
    {
        switch (a_thread->Param(i).m_type)
        {
        case GM_INT:
            v[i] = a_thread->Param(i).m_value.m_int;
            break;
        case GM_FLOAT:
            v[i] = a_thread->Param(i).m_value.m_float;
            break;
        default:
            a_thread->GetMachine()->GetLog().LogEntry( "Vector: Param %d error - expected int or float", i );
            return GM_EXCEPTION;
        }
    }
    // Create a native object with default params    
    Vector *p = new Vector( v[0], v[1], v[2] );
 
    // Return to GM
    a_thread->PushNewUser( p, Type );
	return GM_OK;	
}
			
/// Entry point for the library; this is effectively the constructor 
int GM_CDECL libentry( gmThread *a_thread )
{
    // Delegate the appropriate call based on the arg count
    switch (a_thread->GetNumParams())
    {
    case 0:
        return default_constructor( a_thread );
    case 3:
        return data_constructor( a_thread );
    };
    
    // Not handled, log an error and return an exception
    a_thread->GetMachine()->GetLog().LogEntry( "Vector: Bad number of parameters passed" );
    return GM_EXCEPTION;
}
		

// Library entry point; this defines the constructor of the type
gmFunctionEntry lib[] =
{
	{ "Vector", libentry }
};

// Type lib; these functions become members of the type
gmFunctionEntry typeLib[] = 
{
	{ 0, 0 }
};


void BindLib( gmMachine *a_machine )
{
	// Register one function (the entry point)
    a_machine->RegisterLibrary( lib, 1 );
    Type = a_machine->CreateUserType( lib[0].m_name );
}


};      // end namespace gmVector

int main()
{
	gmMachine gm;

    // Bind the type
    gmVector::BindLib( &gm );

    gm.ExecuteString("v = Vector( 30, 40, 60.5 );" );
    
	return 0;
} 

