#include "gmThread.h"

int main()
{
	gmMachine gm;

	// Execute a simple script
	gm.ExecuteString( "print( \"Hello, world!\" );" );

	return 0;
} 
