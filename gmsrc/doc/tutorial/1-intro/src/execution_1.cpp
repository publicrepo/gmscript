#include <cstdlib>
#include "gmThread.h"

int main()
{
	gmMachine gm;

	// Compile a simple script without running it
	gm.ExecuteString( "print( `Hello, world!` );", 0, false );

	// The text wasn't printed!

	// Wait for a keypress
    getchar();
    
	// The script will now execute!
    gm.Execute( 0 );

	return 0;
} 
