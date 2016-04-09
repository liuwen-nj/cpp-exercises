/*
 * Draw.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include "Geom.h"
using namespace std;

namespace helper {
  CLine* createLine() {
    double xA, yA, xB, yB;
    cout << "Please enter X coordinate of first point: ";
    cin >> xA;
    cout << "Please enter Y coordinate of first point: ";
    cin >> yA;
    CPoint* pA = new CPoint(xA, yA);

    cout << "Please enter X coordinate of second point: ";
    cin >> xB;
    cout << "Please enter Y coordinate of second point: ";
    cin >> yB;
    CPoint* pB = new CPoint(xB, yB);

    return new CLine(pA, pB);
  }

  CRectangle* createRectangle() {
    double xA, yA, xB, yB;
    cout << "Please enter X coordinate of first point: ";
    cin >> xA;
    cout << "Please enter Y coordinate of first point:";
    cin >> yA;
    CPoint* pA = new CPoint(xA, yA);

    cout << "Please enter X coordinate of second point: ";
    cin >> xB;
    cout << "Please enter Y coordinate of second point: ";
    cin >> yB;
    CPoint* pB = new CPoint(xB, yB);

    return new CRectangle(pA, pB);
  }

  CCircle* createCircle() {
    double xM, yM, r;
    cout << "Please enter X coordinate of center point: ";
    cin >> xM;
    cout << "Please enter Y coordinate of center point: ";
    cin >> yM;
    CPoint* pM = new CPoint(xM, yM);

    cout << "Please enter value for radius: ";
    cin >> r;

    return new CCircle(pM, r);
  }
}

int main() {

  bool quit = false;

  while (!quit) {
    int i;
    cout
        << "Please input: draw line (1), rectangle (2) or circle (3) ? Quit (0)." << endl;
    cin >> i;

    switch (i) {
    case 0:
      quit = true;
      break;
    case 1: {
      CLine* line = helper::createLine();
      cout << "You created the line " + (*line).list() << endl;
      break;
    }
    case 2: {
      CRectangle* rectangle = helper::createRectangle();
      cout << "You created the rectangle " + (*rectangle).list() << endl;
    }
    break;
    case 3: {
      CCircle* circle = helper::createCircle();
      cout << "You created the circle " + (*circle).list() << endl;
    }
    break;
    default:
      cout << "Not a valid input!" << endl;
      break;
    }
  }

  cout << "Quitting program..";
  return 0;
}

