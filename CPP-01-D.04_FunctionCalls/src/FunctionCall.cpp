///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-01.02D - Function Call by Value vs. by Reference                //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

void callByValue(string str)
{
	cout << "Input string   : " << str << endl; // out: GlobalString
	str = "CallByValue";
	cout << "Local string   : " << str << endl; // out: CallByValue
}

void callByPointerReference(string* str)
{
	cout << "Input string   : " << *str << endl; // out: GlobalString
	*str = "CallByPointerReference";
	cout << "Local string   : " << *str << endl; // out: CallByPointerReference
}

void callByReferenceReference(string& str)
{
	cout << "Input string   : " << str << endl; // out: CallByPointerReference
	str = "CallByReferenceReference";
	cout << "Local string   : " << str << endl; // out: CallByReferenceReference
}

int main()
{
	string   str = "GlobalString";
	
	cout << "Global string  : " << str << endl << endl; // out: GlobalString

	cout << "Call By Value  :" << endl;
	callByValue(str);
	cout << "Global string  : " << str << endl << endl; // out: GlobalString

	cout << "Call By Pointer Reference:" << endl;
	callByPointerReference(&str);
	cout << "Global string  : " << str << endl << endl; // out: CallByPointerReference

	cout << "Call By Reference Reference:" << endl;
	callByReferenceReference(str);
	cout << "Global string  : " << str << endl << endl; // out: CallByReferenceReference

	return 0;
}
