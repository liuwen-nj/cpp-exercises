
#include <iostream>

#include "../inc/Figure.h"

using namespace std;


unsigned long CFigure::ulCount = 0;

void CFigure::listCount() {
  cout << "# CFigures: " << ulCount << endl;
}

// default constructor
CFigure::CFigure() {
  ulCount++;
}

// copy constructor
CFigure::CFigure(const CFigure& object) {
  ulCount++;
}

// destructor
CFigure::~CFigure() {
  ulCount--;
}
