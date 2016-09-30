///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-06-D.02: Standard Library Strings Usage Examples                //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



int main()
{

	//* basic string operations
	string s = "Test0";
	cout << "String='" << s << "'" << " Size=" << s.size()
		 << " Capacity=" <<  s.capacity() << " MaxSize=" << s.max_size()
		 << endl << endl;


	s = "Test1";
	cout << "String='" << s << "'" << " Size=" << s.size()
		 << " Capacity=" <<  s.capacity() << endl;

	for (int i=0; i<31; i++)
	{
		s += ".";
		cout << "String='" << s << "'" << " Size=" << s.size()
			 << " Capacity=" <<  s.capacity() << endl;
	}

	// reserve 100 chars
	cout << endl << " --> Reserve 100 Chars	" << endl;
	s.reserve(100);
	cout << "String='" << s << "'" << " Size=" << s.size()
		 << " Capacity=" <<  s.capacity() << endl;

	// erase string
	cout << endl << " --> Erase String" << endl;
	s.erase();
	cout << "String='" << s << "'" << " Size=" << s.size()
		 << " Capacity=" <<  s.capacity() << endl;

	// resize 10 chars
	cout << endl << " --> Resize 10 Chars" << endl;
	s.resize(10, ' ');
	cout << "String='" << s << "'" << " Size=" << s.size()
		 << " Capacity=" << s.capacity() << endl << endl << endl;
	// basic string operations */




	/* begin string example: word extraction
	int count = 0;
	string::size_type start = 0;
	string::size_type end = 0;
	string text;
	string word;
	string whitespace = " \t,.;-()";
	string default_text = "Ein Textbeispiel mit (Klammern) und \t Tabulator.";

	// get input or use default text
	cout << "Input  : ";
	getline(cin, text);
	if (text.empty()) text = default_text;

	cout << "Text   = '" << text << "'" << endl << endl;

	// do word extraction
	while ((start = text.find_first_not_of(whitespace, start)) != string::npos)
	{
		end = text.find_first_of(whitespace, start);
		word.assign(text, start, end - start);
		cout << "Word " << count++ << " = '" << word << "'" << endl;

		start = end;
	}
	// end string example: word extraction */

	return 0;
}
