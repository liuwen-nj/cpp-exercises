///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-03-D.02 - Usage of Template Classes (Stack)                     //
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

#include "../inc/point.h"


// implementation of CPoint member functions //////////////////////////////////
CPoint::CPoint(const CPoint &source)
///////////////////////////////////////////////////////////////////////////////
{
    x = source.x;
    y = source.y;
}


CPoint& CPoint::operator=(const CPoint &source)
///////////////////////////////////////////////////////////////////////////////
{
    x = source.x;
    y = source.y;
    return *this;
}


bool CPoint::operator>(const CPoint &source)
///////////////////////////////////////////////////////////////////////////////
{
    return ((x*x + y*y) > (source.x*source.x + source.y*source.y));
}


// implementation of global output operator for class CPoint //////////////////
// (this function is friend of CPoint and can access private class members directly)
ostream& operator<<(ostream& stream, const CPoint& point)
///////////////////////////////////////////////////////////////////////////////
{
    stream << "Point(" << point.x << "," << point.y << ")";
    return stream;
}

