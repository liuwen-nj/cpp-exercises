///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-02.05D - Static Members (Example: Object Counter)               //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class CPoint
///////////////////////////////////////////////////////////////////////////////
{
private: // data member
    static int iCount;      // count of used Objects
    int        iX;          // x coordinate of point
    int        iY;          // y coordinate of point

public: // data member
    static bool	bVisible;   // visibility of all points

public: // function member
   CPoint() {iCount++;};
   ~CPoint() {iCount--;};

   static int GetCount() {return iCount;};

   static void ShowVisibility();
   void SetVisibility(bool flag) {bVisible = flag;};
};


// init static members ////////////////////////////////////////////////////////
int CPoint::iCount = 0;
bool CPoint::bVisible = true;


void CPoint::ShowVisibility()
///////////////////////////////////////////////////////////////////////////////
{
    // try to access non static class members
    //CPoint::iX = 0;
    //SetVisibility(true);

    // show visibility of points
    cout << "Visibility: " << CPoint::bVisible << endl;
}




int main()
///////////////////////////////////////////////////////////////////////////////
{
    // define pointer to point
    CPoint *pPoint;

    // show count of points
    cout << "\nCount: " << CPoint::GetCount() << " (no object created)" << endl;

    // create static point and show current count
    CPoint P1;
    cout << "Count: " << CPoint::GetCount() << " (static object created)" << endl;

    // create dynamic point and show current count
    pPoint = new CPoint;
    cout << "Count: " << CPoint::GetCount() << " (dynamic object created)" << endl;
    cout << "Count: " << P1.GetCount() << endl;
    cout << "Count: " << pPoint->GetCount() << endl;

    // delete dynamic created point and show current count
    delete pPoint;
    cout << "Count: " << CPoint::GetCount() << " (dynamic object deleted)" << endl << endl;

    // show and set visibility flag (static class member function calls)
    CPoint::ShowVisibility();
    P1.SetVisibility(false);
    P1.ShowVisibility();


    /* begin array demo
    // create dynamic point array and show current count
    pPoint = new CPoint[100];
    cout << "\nCount: " << CPoint::GetCount() << " (dynamic array created)" << endl;

    // delete dynamic created point array and show current count
    delete[] pPoint;
    cout << "Count: " << CPoint::GetCount() << " (dynamic array deleted)" << endl;

    // end array demo */

    return 0;
}

