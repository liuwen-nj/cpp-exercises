///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-04-D.01 - Inheritance Demonstration                             //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


class ClassA
{
protected:
    string test;

public:
    ClassA(string txt = "Text") : test(txt) { cout << "Constructor ClassA" << endl;};

    //virtual ~ClassA() = 0;
    ~ClassA();
    //virtual void List() = 0;
    void List();
};

// pure virtual functions can not be implemented implizit inline (mac)
ClassA::~ClassA() {cout << "Destructor ClassA" << endl;}
void ClassA::List() {cout << "ClassA::List()   : test = " << test << endl;}


// class ClassB : private ClassA
class ClassB : public ClassA
{
protected:
    int test;

public:
    ClassB() : test(10) {cout << "Constructor ClassB" << endl;};
    ~ClassB() {cout << "Destructor ClassB" << endl;};

    void List() { cout << "ClassB::List()   : test = " << test << endl;}
};


class ClassC : public ClassB
{
public:
    ClassC() { cout << "Constructor ClassC" << endl;};
    ~ClassC() {cout << "Destructor ClassC" << endl;};

    // void List(bool flag) { cout << "ClassC::List()   : test = " << test << endl;}
};



int main()
{
    cout << "Create dynamic Object A:" << endl;
    ClassA* pA = new ClassA("Text");
    cout << endl << "Create dynamic Object B:" << endl;
    ClassB* pB = new ClassB;
    cout << endl << "Create static Object C:" << endl;
    ClassC C;


    // Assignment Demo
    // pA = pB;
    // pB = pA;


    /* Begin: List() Output Demo
    cout << endl << endl << "List Output Demo:" << endl;
    pA->List();
    pB->List();
    C.List();
    // End: List() Output Demo */


    /* Begin: Virtual Demo
    cout << endl << endl << "Virtual Demo:" << endl;
    ClassA* pX = new ClassC;
    pX->List();
    cout << endl << "Delete dynamic Object X:" << endl;
    delete pX;
    // End: Virtual Demo */


    cout << endl << endl << "Delete dynamic Object A:" << endl;
    delete pA;
    cout << endl << "Delete dynamic Object B:" << endl;
    delete pB;
    cout << endl << "Delete static Object C:" << endl;

    return 0;
}
