///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-03-D.02 - Usage of Template Classes (Stack)                     //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "../inc/stack.h"
#include "../inc/point.h"



int main() ///////////////////////////////////////////////////////////////
{
    // "static" definition
    CStack<int> IntStack(5);                 // stack of integers (size = 5)
    CStack<int>& rIntStack = IntStack;       // reference to stack of integers
    CStack<double> DoubleStack;              // stack of doubles (default size = 10)
    CStack<CPoint> PointStack(5);            // stack of CPoints

    // dynamic definition
    CStack<int>* pIntStack = new CStack<int>;     // pointer to stack of integers

    // typedef definition
    typedef CStack<int> IStack;
    IStack aIntStack[10];                         // array of int stacks

    // nested definition (space char!!)
	CStack< CStack<int> > IntStackStack(5);       // stack of int stacks
	CStack< CStack<CPoint> > PointStackStack(5);  // stack of CPoint stacks

    // push stacks
    for (int i=0; i<5; i++)
    {
        IntStack.Push(i);
        pIntStack->Push(i);
        aIntStack[0].Push(i*10);
        DoubleStack.Push(i + i * 0.1);
        PointStack.Push(CPoint(i,i));
        IntStackStack.Push(IntStack);
        PointStackStack.Push(PointStack);
    }

    // dump stack content
    IntStack.Dump();
    pIntStack->Dump();
    aIntStack->Dump();
    DoubleStack.Dump();
    PointStack.Dump();
    IntStackStack.Dump();
    PointStackStack.Dump();

    delete pIntStack;

    return 0;
}
