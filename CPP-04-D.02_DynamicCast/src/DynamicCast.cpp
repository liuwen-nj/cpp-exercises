///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-04-D.02 - Dynamic Cast Operator                                 //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


class A
{
public:
	string type;
	
	A() {type = "Class A";}
	// virtual ~A(void) {};
};



class B : public A
{
	int value;

public:
	B() : value(100) { type = "Class B";};
	void func() { cout << "B::func() called: " <<  value << endl << endl;};
};



class C : public B
{
public:
	C() { type = "Class C";};
};


void cast(A* a)
{	
	B* b = a; // error: invalid conversion from 'A*' to 'B*'
	//B* b = (B*)a;
	//B* b = dynamic_cast<B*>(a); // source type for dynamic_cast needs to be polymorphic
	cout << "Type: " << (*a).type << " Cast Result: " << b << endl;
	//cout << "Type: " << typeid(*a).name() << " Cast Result: " << b << endl;
	
	if (b!= 0) b->func();
}


int main()
{
	A* pA = new A;
	B* pB = new B;
	C* pC = new C;

	cast(pA);
	cast(pB);
	cast(pC);

	return 0;
}
