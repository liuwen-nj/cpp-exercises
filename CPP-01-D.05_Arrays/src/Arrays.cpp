///////////////////////////////////////////////////////////////////////////////
// CPP-01.05D - Arrays and C-Strings                                         //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
//#include <string.h>

using namespace std;

int main()
{
	// define and init arrays 
	//double myArray[] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0}; 
	int myArray[] = {0,10,20,30,40,50,60,70,80,90}; 
	//double* myArrayPointer = myArray;
	int* myArrayPointer = myArray;
	//myArray = myArrayPointer;
	

	cout << "Array Pointer: " << myArray << endl;
	cout << "Array Pointer: " << &myArray << endl;    // this is actually the same as myArray, it's not like an address of a pointer which differs in it's content (another address)
	cout << "Array Pointer: " << &myArray[0] << endl; // this is actually the same as myArray,
	cout << endl;

	for (int i = 0; i<10; i++)
	{
		cout << "ArrayElement[" << i << "] = " << myArray[i];
		cout << " Pointer: " <<  &myArray[i] << endl; // always increases 4 byte (size of an int) or 8 byte (in case of a double)
	}
	cout << endl;
	
	// does exactly the same as above
	for (int i = 0; i<10; i++)
	{
		cout << "ArrayElement[" << i << "] = " << *(myArray + i); // if I add 1 and it's a int array it adds 4 byte to the address, for double 1 => 8 byte
		cout << " Pointer: " <<  (myArray + i) << endl;
	}
	cout << endl;

	// does exactly the same as above
	for (int i = 0; i<10; i++ /*, myArrayPointer++ */)
	{
		cout << "ArrayElement[" << i << "] = " << *myArrayPointer;
		cout << " Pointer: " <<  myArrayPointer << endl;
		myArrayPointer = myArrayPointer + 1; // we could drop that and incrementing the pointer in the head of the for loop: myArrayPointer++
	}
	cout << endl;

	// testing of c-string arrays
	char myText[] = "This is my text for testing"; // implicit adding '\0' at the end (array length: 27 chars + null terminator = 28)

	//myText[14] = '\0'; // terminates the printing at: This is my tex

	/*
	char myText[5];
	myText[0] = 'T';
	myText[1] = 'e';
	myText[2] = 's';
	myText[3] = 't';
	myText[4] = '\0';
	// */

	int i= 0;
	while (myText[i] != '\0')
	{
		cout << myText[i];
		i++;
	}
	cout << endl;
	cout << myText;
	cout << endl;

	return 0;
}
