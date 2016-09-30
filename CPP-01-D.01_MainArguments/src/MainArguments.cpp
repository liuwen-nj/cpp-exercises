 ///////////////////////////////////////////////////////////////////////////////
 // Demo: CPP-01.01D - Reading Command-Line Arguments                         //
 ///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;


int main(int argc, char *argv[])
{
	cout << "Argument Count: " << argc << endl;

	for (int i=0; i<argc; i++)
	{
		cout << "Argument# " << i << ": " << argv[i] << endl; 
	}

	return 0;
}
