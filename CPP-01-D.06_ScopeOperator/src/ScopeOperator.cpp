///////////////////////////////////////////////////////////////////////////////
// CPP-01.02D: Variable Scope and Global Scope Resolution Operator           //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int n = 0;                              // globale Definition

int main()
{
    cout << "n=" << n << endl;          // Ausgabe: n=0

    int n = 1;                          // lokale Definition 1
    cout << "n=" << n << endl;          // Ausgabe: n=1

    {
        int n = 2;                      // lokale Definition 2 (Lokaler Block)
        cout << "n=" << n << endl;      // Ausgabe: n=2
    }

    cout << "n=" << n << endl;          // Ausgabe: n=1
    cout << "n=" << ::n << endl;        // Ausgabe: n=0 (Globaler Scope)

    return 0;
}
