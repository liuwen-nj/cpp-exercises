///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-03-D.01 - Usage of Template Functions                           //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "../inc/point.h"


// template function implementation ///////////////////////////////////////////
template <class T>
T Max(T a, T b)
///////////////////////////////////////////////////////////////////////////////
{
	cout << "Max() Template Parameter Type: " << typeid(a).name() << endl;
    return ((a > b) ? a : b);
}



// template function overloads ////////////////////////////////////////////////

/*
char* Max(char* a, char* b)
///////////////////////////////////////////////////////////////////////////////
{
    cout << "Overloaded Max() Template Parameter Type: " << typeid(a).name() << endl;
    return ((strcmp(a, b) < 0) ? a : b);
}
//*/


/*
long Max(int a, long b)
///////////////////////////////////////////////////////////////////////////////
{
    cout << "Overloaded Max() Template Parameter Types: "
         << typeid(a).name() << ", " << typeid(b).name() << endl;
    return ((a > b) ? a : b);
}
//*/





int main(void) ///////////////////////////////////////////////////////////////
{
    int i1=10, i2=20;
    cout << "Max(" << i1 << "," << i2 << ") = " << Max(i1,i2) << endl << endl;

    long l1=100, l2=200;
    cout << "Max(" << l1 << "," << l2 << ") = " << Max(l1,l2) << endl << endl;

    double d1=10.1, d2=20.2;
    cout << "Max(" << d1 << "," << d2 << ") = " << Max(d1,d2) << endl << endl;

    char *s1 = "AAAA", *s2 = "BBBB";
    cout << "Max(" << s1 << "," << s2 << ") = " << Max(s1,s2) << endl << endl;


    //cout << "Max(" << i1 << "," << l2 << ") = " << Max(i1,l2) << endl << endl;

    //CPoint p1(10,10), p2(20,20);
    //cout << "Max(" << p1 << "," << p2 << ") = " << Max(p1,p2) << endl << endl;

	return 0;
}
