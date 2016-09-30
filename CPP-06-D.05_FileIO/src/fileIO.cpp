///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-06-D.05 - File Streams Input/Output Example                     //
///////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	// create test file
	ofstream outfile("fileIO.txt");
	outfile << "This is Line 1 of Test File." << endl;
	outfile << "This is Line 2 of Test File." << endl;
	outfile << "This is Line 3 of Test File." << endl;
	outfile << "This is Line 4 of Test File." << endl;
	outfile << "This is Line 5 of Test File." << endl;

	// read/write test file
	fstream iofile("fileIO.txt");
	int i = 0;
	char text[100];

	// output test file
	while (iofile.good())
	{
		iofile.getline(&text[0], 100);
		i++;
		cout << "Output" << i << ": " << text << " (" << iofile.tellg() << ")" << endl;
	}
	cout << endl;

	// read line 2
	iofile.clear(); // reset failbit
	iofile.seekg(30, ios::beg);
	iofile.getline(&text[0], 100);
	i++;
	cout << "Output" << i << ": " << text << " (" << iofile.tellg() << ")" << endl;

	// read next word (ignores whitespace)
	string str;
	iofile >> str;
	i++;
	cout << "Output" << i << ": " << str << " (" << iofile.tellg() << ")" << endl;

	// read next word (ignores whitespace)
	iofile >> str;
	i++;
	cout << "Output" << i << ": " << str << " (" << iofile.tellg() << ")" << endl;

	// rewrite line 4
	iofile.seekp(90, ios::beg);
	iofile << "New TextLine 4 of Test File." << endl;


	// output test file
	cout << endl;
	iofile.seekg(0);
	while (iofile.good())
	{
		iofile.getline(&text[0], 100);
		i++;
		cout << "Output" << i << ": " << text << " (" << iofile.tellg() << ")" << endl;
	}

	return 0;
}
