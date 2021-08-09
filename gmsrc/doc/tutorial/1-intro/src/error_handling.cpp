#include <iostream>
#include "gmThread.h"

void handleErrors( gmMachine &a_machine )
{
	gmLog &log = a_machine.GetLog();
    // Get the first error
    bool firstError = true;
	const char *err = log.GetEntry( firstError );
	while ( err )
	{
		std::cout << "Compilation error: -" << err << std::endl;
		err = log.GetEntry( firstError );
	}
}

int main()
{
    const char *myScript = "fruits = table ( \"apple\", \"pear\", \"orange\" );	foreach ( frt in fruits ) { print(frt);	} ";

	gmMachine gm;

	// Execute a simple script
	int ret = gm.ExecuteString( myScript );
    if ( ret )
    {
        // There were errors in the script, exit gracefully
        handleErrors( gm );
        return 1;
    } 

	return 0;
}

