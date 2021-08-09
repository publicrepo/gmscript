#include "gmThread.h"

int main()
{
    const char *myScript = "fruits = table ( \"apple\", \"pear\", \"orange\" );	foreach ( frt in fruits ) { print(frt);	} ";

	gmMachine gm;

	// Execute a simple script
	gm.ExecuteString( myScript );

	return 0;
} 
