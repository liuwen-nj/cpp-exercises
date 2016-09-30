///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-07-D.01 - Standard Template Library Usage Examples              //
///////////////////////////////////////////////////////////////////////////////

#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;



void showVector(vector<int> &vec)
///////////////////////////////////////////////////////////////////////////////
{
    cout << "Vector Elements: [ ";

    // first see if there's anything in the vector
    if (vec.empty())
    {
        cout << "empty ]" << endl;
        return;
    }

    // iterator is used to loop through the vector.
    vector<int>::iterator theIterator;

    // output contents of vec.
    for (theIterator = vec.begin(); theIterator != vec.end(); theIterator++)
    {
        cout << *theIterator;
        if (theIterator != vec.end()-1) cout << ", ";
    }
    cout << " ]" << endl;
}



bool isEven (int element)
///////////////////////////////////////////////////////////////////////////////
{
    return element % 2 == 0;
}



int main()
///////////////////////////////////////////////////////////////////////////////
{

    // definition of int set
	int iCounter = 0;
	set<int> iSet;

    // fill set
    for ( iCounter = 1; iCounter <= 10; iCounter++ )
    {
	    iSet.insert( iCounter );	// set 1st fill
    }


    // fill set - with partially equal values
    for ( iCounter = 6; iCounter <= 15; iCounter++ )
    {
	    iSet.insert( iCounter );	// set 2nd fill
    }


    // read set with forward iterator
    set<int>::iterator fpos;

    cout << "Set Elements (forward): ";
    for ( fpos = iSet.begin(); fpos != iSet.end(); fpos++ )
    {
        cout << *fpos << ' ';
    }
    cout << endl;


    // read set with reverse iterator
    set<int>::reverse_iterator rpos;

    cout << "Set Elements (reverse): ";
    for ( rpos = iSet.rbegin(); rpos != iSet.rend(); rpos++ )
    {
	    cout << *rpos << ' ';
    }
    cout << endl << endl << endl;




    /* begin: demo STL algorithms
    vector<int> int_vector;
    int num = 0;

    showVector(int_vector);


	// init rand() function
	srand((unsigned)time(0));


    // insert elements into vector
    for (int i=1; i<=10; i++)
	{
        int_vector.push_back(rand() % 100);
    }
    showVector(int_vector);


	// sort vector elements
	sort(int_vector.begin(), int_vector.end());
    showVector(int_vector);


    // output count of elements with value 4
    num = count(int_vector.begin(), int_vector.end(), 4);
    cout << endl << "Number of elements with value 4 : " << num << endl;


    // output even elements
    num = count_if(int_vector.begin(), int_vector.end(), &isEven);
    cout << "Number of even elements    : " << num << endl;

    // end: demo STL algorithms */

	return 0;
}
