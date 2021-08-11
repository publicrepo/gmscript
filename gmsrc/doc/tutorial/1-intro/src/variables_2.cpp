#include <iostream>
#include "gmThread.h"

using namespace std;

int main()
{
	gmMachine gm;

    // Try setting your own variable here
    gmVariable var( gm.AllocStringObject("Hello, World") );

    switch (var.m_type)
    {
    case GM_NULL:
        cout << "Variable is NULL type" << endl;
        break;
    case GM_INT:
        cout << "Variable is INT type" << endl;
        cout << "Value:" << var.m_value.m_int << endl;
        break;
    case GM_FLOAT:
        cout << "Variable is FLOAT type" << endl;
        cout << "Value:" << var.m_value.m_float << endl;
        break;
    case GM_STRING:
        cout << "Variable is STRING type" << endl;
        cout << "Value:" << reinterpret_cast<gmStringObject *>(var.m_value.m_ref)->GetString() << endl;
        break;
    case GM_TABLE:
        cout << "Variable is TABLE type" << endl;
        cout << "Items:" << reinterpret_cast<gmTableObject *>(var.m_value.m_ref)->Count() << endl;
        break;
    case GM_FUNCTION:
        cout << "Variable is FUNCTION type" << endl;
        break;
    default:
        cout << "Variable is USER type" << endl;
        // retrieve native pointer from user object
        void *ptr = reinterpret_cast<gmUserObject *>(var.m_value.m_ref)->m_user;
        
    };
    
	return 0;
} 

