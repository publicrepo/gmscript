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


int GM_CDECL copy_constructor( gmThread *a_thread )
{ 
	// Check for a valid number of parameters
    if (a_thread->GetNumParams() != 1 )
        return GM_EXCEPTION;
	
    // Check if the type is the same as the Vector type registered
    if (a_thread->Param(0).m_type != Type)
        return GM_EXCEPTION;

    gmUserObject *usr = reinterpret_cast<gmUserObject*>(a_thread->Param(0).m_value.m_ref);
    Vector *cpy = reinterpret_cast<Vector*>(usr->m_user);  

    // Null pointer returned
    if (cpy == 0)
        return GM_EXCEPTION;

    // Create a native object using the default copy constructor
    Vector *p = new Vector( *cpy );
 
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
    case 1:
        return copy_constructor( a_thread );
    case 3:
        return data_constructor( a_thread );
    };
    
    // Not handled, log an error and return an exception
    a_thread->GetMachine()->GetLog().LogEntry( "Vector: Bad number of parameters passed" );
    return GM_EXCEPTION;
}


/// Effectively the destructor for the object
void GM_CDECL gc_destruct(gmMachine * a_machine, gmUserObject* a_object)
{
	std::cout << "Vector: destructing\n";
	GM_ASSERT(a_object->m_userType == Type);
    Vector* object = reinterpret_cast<Vector*>(a_object->m_user);
    delete object;
}

// Trace the objct in the mark phase
bool gc_trace( gmMachine * a_machine, gmUserObject* a_object, gmGarbageCollector* a_gc, const int a_workLeftToGo, int& a_workDone )
{
    // Make sure this is the correct type
    GM_ASSERT(a_object->m_userType == m_gmType);

    // If your object references other gmObjects, you should call GetNextObject for each one here

    // mark 'me' as done
    a_workDone++;
    return true;
}


void GM_CDECL OpGetDot(gmThread * a_thread, gmVariable * a_operands)
{
	GM_ASSERT(a_operands[0].m_type == Type);
    Vector* thisVec = reinterpret_cast<Vector*>(reinterpret_cast<gmUserObject*>(GM_OBJECT(a_operands[0].m_value.m_ref))->m_user);

    GM_ASSERT(a_operands[1].m_type == GM_STRING);
    gmStringObject* stringObj = reinterpret_cast<gmStringObject*>(GM_OBJECT(a_operands[1].m_value.m_ref));
    const char* propName = stringObj->GetString();

    // Resolve the member name
    if(::stricmp(propName, "x") == 0)
    {
      a_operands[0].SetFloat(thisVec->x);
    }
    else if(::stricmp(propName, "y") == 0)
    {
      a_operands[0].SetFloat(thisVec->y);
    }
    else if(::stricmp(propName, "z") == 0)
    {
      a_operands[0].SetFloat(thisVec->z);
    }
    else
    {
      a_operands[0].Nullify();
    }
}

void GM_CDECL OpSetDot(gmThread * a_thread, gmVariable * a_operands)
{
    GM_ASSERT(a_operands[0].m_type == Type);
    Vector* thisVec = reinterpret_cast<Vector*>(reinterpret_cast<gmUserObject*>(GM_OBJECT(a_operands[0].m_value.m_ref))->m_user);
    
    GM_ASSERT(a_operands[2].m_type == GM_STRING);
    gmStringObject* stringObj = reinterpret_cast<gmStringObject*>(GM_OBJECT(a_operands[2].m_value.m_ref));
    const char* propname = stringObj->GetString();
    
    // Create a variable to hold the data t assign
    // handle both ints and floats
    float newFloat = 0.0f;
    if(a_operands[1].m_type == GM_FLOAT)
    {
      newFloat = a_operands[1].m_value.m_float;
    }
    else if(a_operands[1].m_type == GM_INT)
    {
      newFloat = (float)a_operands[1].m_value.m_int;
    }
    
    // Assign the data
    if(::stricmp( propname, "x") == 0)
    {
      thisVec->x = newFloat;
    }
    else if(::stricmp( propname, "y") == 0)
    {
      thisVec->y = newFloat;
    }
    else if(::stricmp( propname, "z") == 0)
    {
      thisVec->z = newFloat;
    }
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
    
    // Register the 'Get Dot' operator
    a_machine->RegisterTypeOperator(Type, O_GETDOT, NULL, OpGetDot);
    a_machine->RegisterTypeOperator(Type, O_SETDOT, NULL, OpSetDot);
    
    // Register GC callbacks
    a_machine->RegisterUserCallbacks(Type, gc_trace, gc_destruct, NULL); 
}


};      // end namespace gmVector

int main()
{
	gmMachine gm;

    // Bind the type
    gmVector::BindLib( &gm );

    gm.ExecuteString("v = Vector( 30, 40, 60.5 ); v.y = v.x * 2; print( v.y );" );
    
	return 0;
} 

