///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-05-D.01: C++ Exception Examples                                 //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;




class TestClass
///////////////////////////////////////////////////////////////////////////////
{
private:
	int objnum;

public:
    TestClass(int num) : objnum(num) { cout << "Object" << objnum << " Constructor" << endl;};
    ~TestClass() { cout << " --> Object" << objnum << " Destructor" << endl;};

    void CreateAccessViolation();
    void ThrowIntException(int count, int handler = -1);
};
// class TestClass ////////////////////////////////////////////////////////////




void TestClass::CreateAccessViolation()
///////////////////////////////////////////////////////////////////////////////
{
    int* p = 0;
    cout << " --> Creating Access Violation" << endl;
    *p = 10; // causes an access violation
};
// TestClass::CreateAccessViolation() /////////////////////////////////////////



void TestClass::ThrowIntException(int count, int handler)
///////////////////////////////////////////////////////////////////////////////
{
    int level = count;

    cout << "Level " << level << " Enter: ";
    TestClass obj(level);

    if (count > 0)
    {
        if (level == handler)
        {
            // install exception handler on this level
            try
            {   // do a recursive function call
                ThrowIntException(--count, handler);
            }
            catch(int err)
            {
                cout << "Level " << level << " Catch: "  << "int Exception " << err << endl;
            }
        }
        else
        {
            // do not install an exception handler, just do a recursive function call
            ThrowIntException(--count, handler);
        }
    }
    /* begin: throw int exception
    else
    {
        cout << "Level " << level << " Exit : ";
        //cout << "Calling exit() Function" << endl; exit(1);
	//cout << "Throwing Exception" << endl; throw 111;
    }
    // end: throw int exception */

    cout << "Level " << level << " Leave:";

};
// TestClass::ThrowIntException() /////////////////////////////////////////////




int main()
///////////////////////////////////////////////////////////////////////////////
{
    TestClass  object10(10);
    TestClass* pobject20 = 0;

    try
    {
        pobject20 = new TestClass(20);

        //object10.CreateAccessViolation();
        //object10.ThrowIntException(8);

        delete pobject20;
        pobject20 = 0;
    }
    catch(int err)
    {
        cout << "Catching int Exception " << err << " (Default Handler)" << endl;
        delete pobject20;
        pobject20 = 0;
        //throw;
    }
    /* begin: top level exception handler
    catch(...)
    {
        cout << "Catching Unknown Exception" << endl;
        delete pobject20;
        pobject20 = 0;
    }
    // end: top level exception handler */

	return 0;
}

