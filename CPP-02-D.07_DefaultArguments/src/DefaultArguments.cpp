///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.07D - Default Arguments                                      //
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;


void ShowNum(double d, int prec = 6, bool fix = true)
{
	cout.precision(prec); // sets the floating-point precision field for the stream

	if (fix)
	{
		cout << fixed; // write floating point values in fixed-point notation
	}
	else
	{
		cout << scientific; // write floating-point values in scientific notation
	}

	cout << "Value = " << d << endl;
}


/* Begin Test Function Overloading
// Test Function Overloading (error: call of overloaded 'ShowNum(double&, int)' is ambiguous (mehrdeutig))
void ShowNum(double d, int prec)
{
	cout.precision(prec);
	cout << "Double Value = " << d << endl;
}
// End Test Function Overloading */


int main()
{
	double num = 12345.123456789012345;

	ShowNum(num);
	ShowNum(num, 2);
	ShowNum(num, 10, false);
	ShowNum(num, false);

	return 0;
}