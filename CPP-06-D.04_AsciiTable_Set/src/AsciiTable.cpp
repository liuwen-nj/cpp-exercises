///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-06-D.04: ASCII-Table Output - setf() Version                    //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
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
    
	// show integer base prefix, using setf() function
	cout.setf(ios::showbase);
    
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
        cout.width(4);
		cout.setf(ios::right, ios::adjustfield);
        cout.setf(ios::dec, ios::basefield);
        cout << i;
        
		// output hex value
		cout << (char)124;
        cout.width(4);
		cout.setf(ios::left, ios::adjustfield);
        cout.setf(ios::hex, ios::basefield);
        cout << i;
        
		// output octal value
		cout << (char)124;
        cout.width(4);
		cout.setf(ios::left, ios::adjustfield);
        cout.setf(ios::oct, ios::basefield);
        cout << i << (char)124 << endl;
	}
    
	// output ascii table footer
	cout << " |-----|----|----|----|" << endl;
    
	return 0;
}