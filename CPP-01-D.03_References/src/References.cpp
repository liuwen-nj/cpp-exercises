///////////////////////////////////////////////////////////////////////////////
// CPP-01.02D: Definition und Verwendung von Referenzen                      //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
	int* p = 0;	// Definition eines Pointer p auf int, Adresse ist mit 0 initialisiert
	int  x;		// Definition der Variablen x
	int  i = 1;	// Definition und Initalisierung der Variablen i
	int& r = i;	// Definition einer Referenz r auf i, Notation int &r = i; würde auch gehen (nicht zu verwechseln mit dem Adress-Operator!)
	//int& r1;	// Compiler Fehler: references must be initialized

	x = r;		// x = 1
	r = 2;		// i = 2, r = 2, x bleibt 1 da x keine Referenz ist
	i++;		// i = 3, r = 3
	r++;		// i = 4, r = 4

	p = &r;		// Zuweisung der Adresse von r an p (&r == &i)
	(*p)++;		// i = 5, r = 5

	cout << "Value of i: " << i << endl;
	cout << "Value of r: " << r << endl;

	return 0;
}
