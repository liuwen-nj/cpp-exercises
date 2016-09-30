///////////////////////////////////////////////////////////////////////////////
// CPP-01.03D - Pointers                                                     //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	// pointer to primitive types
	int myInt1 = 200;                 // int definition
	int myInt2 = 100;                  // int definition
	int* myIntPointer1;                // int pointer definition
	int* myIntPointer2;                // int pointer definition


	myIntPointer1 = &myInt1;           // address assignment
	cout << "Integer: " <<  myInt1 << endl;         // output int value
	cout << "Address: " <<  &myInt1 << endl;        // output int address (8 digit hex value, e.g.: 0xbffff5c4)
	cout << "Integer: " << *myIntPointer1 << endl;  // output int value (de-referenced)
	cout << "Address: " <<  myIntPointer1 << endl;  // output int address
	cout << "Pointer: " <<  &myIntPointer1 << endl; // output pointer address (address where the 4 byte (=32 bit) address of the value of myInt1 lies)
	cout << endl;

	*myIntPointer1 = *myIntPointer1 + 4; // you can also write: *myIntPointer1 += 4;
	//myIntPointer1 = myIntPointer1 + 4; // would add 4 to myIntPointer1's address (pointer arithmetic) and there could be any value
	cout << "Integer: " <<  myInt1 << endl;         // output int value
	cout << "Address: " <<  &myInt1 << endl;        // output int address
	cout << "Integer: " << *myIntPointer1 << endl;  // output int value
	cout << "Address: " <<  myIntPointer1 << endl;  // output int address
	cout << "Pointer: " <<  &myIntPointer1 << endl; // output pointer address
	cout << endl;

	myIntPointer1 = &myInt2;
	cout << "Integer: " <<  myInt1 << endl;         // output int value
	cout << "Address: " <<  &myInt1 << endl;        // output int address
	cout << "Integer: " << *myIntPointer1 << endl;  // output int value
	cout << "Address: " <<  myIntPointer1 << endl;  // output int address
	cout << "Pointer: " <<  &myIntPointer1 << endl; // output pointer address
	cout << endl;

	// pointer to struct/class types
	struct myStructType { int value1; int value2;};

	myStructType myStruct; // struct variable
	myStruct.value1 = 1000;
	myStruct.value2 = 2000;

	myStructType* myStructPointer = &myStruct; // struct pointer

	cout << "myStruct value1: " <<  myStruct.value1 << endl; // access via struct var with '.'
	cout << "myStruct value1: " <<  (*myStructPointer).value1 << endl; // access via dereferenced struct pointer with '.'
	cout << "myStruct value1: " <<  myStructPointer->value1 << endl; // access via struct pointer with '->'
	cout << "myStruct value2: " <<  myStruct.value2 << endl;
	cout << "myStruct value2: " <<  (*myStructPointer).value2 << endl;
	cout << "myStruct value2: " <<  myStructPointer->value2 << endl;

	// pointer comparison
	myIntPointer1 = &myInt1;
	myIntPointer2 = &myInt2;
	if (myIntPointer1 < myIntPointer2)
	{
		cout << "Comparison result: " << *myIntPointer1 << " < " << *myIntPointer2 << endl;
	}
	else
	{
		cout << "Comparison result: " << *myIntPointer1 << " > " << *myIntPointer2 << endl;
	}

	return 0;
}
