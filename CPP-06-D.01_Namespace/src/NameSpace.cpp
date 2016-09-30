///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-06-D.01: Namespace Definition and Scope Operator                //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

namespace N1
{
	int n = 10;							// Namespace Definition 1
}

namespace N2
{
	int n = 20;							// Namespace Definition 2
}
//using namespace N1;

int n = 0;								// globale Definition

int main()
{
    cout << "n=" << n << endl;			// Ausgabe: n=0

	int n = 1;							// lokale Definition
    cout << "n=" << n << endl;			// Ausgabe: n=1

	cout << "n=" << ::n << endl;		// Ausgabe: n=0

    cout << "n=" << N1::n << endl;		// Ausgabe: n=10
    cout << "n=" << N2::n << endl;		// Ausgabe: n=20

    return 0;
}
