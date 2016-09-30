///////////////////////////////////////////////////////////////////////////////
// Demo: CPP-03.01D - Usage of Template Functions                            //
///////////////////////////////////////////////////////////////////////////////


// declaration of class CPoint ////////////////////////////////////////////////
class CPoint
{
    friend ostream& operator<<(ostream& stream, const CPoint& point);
private:
    int x;
    int y;

public:
    CPoint(int x=0, int y=0) : x(x), y(y) {};
    CPoint(const CPoint& source);
    CPoint& operator=(const CPoint& source);
    //bool operator>(const CPoint& source);
};



// declaration of global output operator for class CPoint /////////////////////
ostream& operator<<(ostream& stream, const CPoint& point);
