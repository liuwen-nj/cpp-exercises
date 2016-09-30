///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-06-D.03: ASCII-Table Output - Manipulator Version               //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;


int main(void)
{
	const int min = 32;
	const int max = 255;
	int begin = min;
	int end = max;

	// get table begin parameter
	cout << "Enter ASCII Table Begin [" << min << ".." << max << "]: ";
	cin >> begin;

	// check for valid input range
	if ((begin < min) || (begin > max)) begin = min;

	// get table end parameter
	cout << "Enter ASCII Table End   [" << begin << ".." << max << "]: ";
	cin >> end;

	// check for valid input range
	if ((end < begin) || (end > max)) end = max;

	// output ascii table header
    cout << endl << "  CHAR   " << "DEC " << "HEX  " << "OCT" << endl;

	// show integer base prefix, using manipulator
	cout << showbase;

	// output ascii table characters
	for (int i = begin; i <= end; i++)
	{
		// output table horizontal line
		cout << " |-----|----|----|----|" << endl;
       
		// output char
        cout << " " << (char)124;
		cout << " '" << (char)i << "' ";

		// output decimal value
		cout << (char)124;
		cout << dec << setw(4) << right;
        cout << i;

		// output hex value
		cout << (char)124;
		cout << hex << setw(4) << left;
        cout << i;

		// output octal value
		cout << (char)124;
		cout << oct << setw(4) << left;
		cout << i << (char)124 << endl;
	}

	// output ascii table footer
    cout << " |-----|----|----|----|" << endl;

	return 0;
}
