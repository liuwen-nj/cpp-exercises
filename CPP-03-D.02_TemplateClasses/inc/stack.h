///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-03.02D - Stack Template Class Implementation                    //
///////////////////////////////////////////////////////////////////////////////





// template class stack declaration ///////////////////////////////////////////
template <class T>
class CStack
///////////////////////////////////////////////////////////////////////////////
{
	template <class U> friend ostream& operator<<(ostream& stream, const CStack<U>& stack);
private:
	int _iSize;
	int _iCount;
	T*  _Elements;

public:
	~CStack();							// destructor
	CStack(int size = 10);				// constructor
	CStack(const CStack&);				// copy constructor
	CStack& operator=(const CStack&);	// assignment operator

	void Push(T);						// push element on stack
	T Pop();							// pop element from stack
	void Dump();						// dump stack elements
};



// template class stack implementation ////////////////////////////////////////


// stack constructor //////////////////////////////////////////////////////////
template <class T>
CStack<T>::CStack(int size)
:_iSize(size), _iCount(0), _Elements(new T[_iSize])
///////////////////////////////////////////////////////////////////////////////
{}



// stack destructor ///////////////////////////////////////////////////////////
template <class T>
CStack<T>::~CStack()
///////////////////////////////////////////////////////////////////////////////
{
	delete[] _Elements;
}



// stack copy constructor /////////////////////////////////////////////////////
template <class T>
CStack<T>::CStack(const CStack& stack)
:_iSize(stack._iSize), _iCount(stack._iCount), _Elements(new T[stack._iSize])
///////////////////////////////////////////////////////////////////////////////
{
	for (int i=0; i<stack._iCount; i++)
	{
		_Elements[i] = stack._Elements[i];
	}
}



// stack assignment operator //////////////////////////////////////////////////
template <class T>
CStack<T>& CStack<T>::operator=(const CStack& stack)
///////////////////////////////////////////////////////////////////////////////
{
	// check for assignment to self
	if (this == &stack) return *this;

	// delete current stack elements
	delete[] _Elements;
	_iSize = stack._iSize;
	_iCount = stack._iCount;
	_Elements = new T[stack._iSize];

	for (int i=0; i<stack._iCount; i++)
	{
		_Elements[i] = stack._Elements[i];
	}

	return *this;
}




// push stack element /////////////////////////////////////////////////////////
template <class T>
void CStack<T>::Push(T x)
///////////////////////////////////////////////////////////////////////////////
{
	_Elements[_iCount++] = x;
}



// pop stack element //////////////////////////////////////////////////////////
template <class T>
T CStack<T>::Pop()
///////////////////////////////////////////////////////////////////////////////
{
	return _Elements[--_iCount];
}



// dump stack elements using Pop() function ///////////////////////////////////
template <class T>
void CStack<T>::Dump()
///////////////////////////////////////////////////////////////////////////////
{
	int count = _iCount;

	cout << "Stack Template Parameter Type: " << typeid(*this).name() << endl;
	if (count == 0)
	{
		cout << "[Empty Stack]" << endl;
	}
	else
	{
		for (int i=0; i<count; i++)
		{
			cout << "[Stack Element" << count-1 - i << ": " << Pop() << "]" << endl;
		}
	}
	cout << endl;
}



// implementation of global output operator for class Stack<T> ////////////////
template <class T>
ostream& operator<<(ostream& stream, const CStack<T>& stack)
///////////////////////////////////////////////////////////////////////////////
{
	int count = stack._iCount;

	if (count == 0)
	{
		stream << "  [Empty Stack]" << endl;
	}
	else
	{
		stream << endl;
		for (int i=0; i<count; i++)
		{
			stream << "  [Stack Element" <<  i << ": "
				<< stack._Elements[i] << "]" << endl;
		}
	}
	return stream;
}
