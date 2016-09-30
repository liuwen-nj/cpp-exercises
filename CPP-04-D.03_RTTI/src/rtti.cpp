///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-04-D.03 - Runtime Type Information (RTTI)                       //
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <typeinfo>
using namespace std;

 

// at least one virtual function is needed for polymorphic class behavior!
class A {
public:
	//virtual ~A() {}; // virtual destructor
/*
private:
	int inta;
	
public:
	A () {inta = 10;};
	A (int a) {inta = a;};
	virtual int test() {return inta;}; // virtual function
//*/
};



class B : public A {
/*
private:
	int intb;

public:
	B () {intb = 20;};
	B (int b) {intb = b;};
	virtual int test() {return intb;}; // virtual function
//*/
};



void ShowDiagnostics(A* a)
{
	if (typeid(*a) == typeid(A))
	{
		cout << "base class A" << endl;
	}
	else
	{		
		cout << typeid(*a).name() << endl;
	}
}



int main()
{
	A a;
	B* b = new B;

	//cout << "b->A::test()=" << b->A::test() << endl;
	//cout << "b->B::test()=" << b->B::test() << endl;

	cout << "Typename = ";
	ShowDiagnostics(&a);

	cout << "Typename = ";
	ShowDiagnostics(b);

	delete b;

	return 0;
}
