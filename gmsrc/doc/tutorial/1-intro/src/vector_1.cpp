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
				
/// Entry point for the library; this is effectively the constructor 
int GM_CDECL libentry( gmThread *a_thread )
{
	std::cout << "Vector:: libentry called from script\n";
    Vector *p = new Vector();
    a_thread->PushNewUser( p, Type );
    return GM_EXCEPTION;
}
		
// Library entry point; this defines the constructor of the type
gmFunctionEntry lib[] =
{
	{ "Vector", libentry }
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

    // A simple test
    gm.ExecuteString("v = Vector();" );
    
	return 0;
} 

