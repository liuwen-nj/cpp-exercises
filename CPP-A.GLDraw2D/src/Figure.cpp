
#include <iostream>

#include "../inc/Figure.h"

using namespace std;


unsigned long CFigure::ulCount = 0;

void CFigure::listCount() {
  cout << "# CFigures: " << CFigure::ulCount << endl;
}

// default constructor
CFigure::CFigure() {
  CFigure::ulCount++;
}

// copy constructor
CFigure::CFigure(const CFigure& object) {
  CFigure::ulCount++;
}

// destructor
CFigure::~CFigure() {
  CFigure::ulCount--;
}
