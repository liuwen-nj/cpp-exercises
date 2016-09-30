///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.04D: Global Initialization and Destruction                   //
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

class A
{
public:
	A() {cout << "\nInitialising global object" << endl;};
	~A(){cout << "Deleting global object\n" << endl; };
};

// global definition
A a;

int main()
{
	// begin of main
	cout << "--> Start of main()" << endl;

	// some code to execute
	cout << "--> Executing some code" << endl;

	// end of main
	cout << "--> End of main()" << endl;

	return 0;
}
