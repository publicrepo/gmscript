#include <iostream>
#include "gmThread.h"

int main()
{
	gmMachine gm;

    // Allocate a string from the machine and set it as a variable
    gmVariable stringVar( gm.AllocStringObject("Hello, World") );
    // Allocate a variable containing an int and a float
    // note it doesn't need to be created from the machine
    gmVariable intVar( 100 );
    gmVariable floatVar( 1.5f );
    
    // Create a variable with a newly created table
    gmVariable tableVar( gm.AllocTableObject() );
    
    // Reset table var as an int, losing the table data it contained
    tableVar.SetInt( 200 );
    
    // Variable copying
    intVar = floatVar;
    
    // Make 'null'
    stringVar.Nullify();
    
	return 0;
} 

