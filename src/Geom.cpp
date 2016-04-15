/*
 * Geom.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include "../inc/Geom.h"
using namespace std;

void CPoint::set(double coordinateX, double coordinateY) {
  X = coordinateX;
  Y = coordinateY;
}

void CPoint::list() {
  cout << "CPoint " << " [x=" << X << "; y=" << Y << "]" << endl;
}

void CLine::set(double x1, double y1, double x2, double y2) {
  P1.set(x1, y1);
  P2.set(x2, y2);
}

void CLine::list() {
  cout << "CLine {" << endl;
  P1.list();
  P2.list();
  cout << "}" << endl;
}

void CRectangle::set(double x1, double y1, double x2, double y2) {
  P1.set(x1, y1);
  P2.set(x2, y2);
}

void CRectangle::list() {
  cout << "CRectangle {" << endl;
  P1.list();
  P2.list();
  cout << "}" << endl;
}

void CCircle::set(double x, double y, double radius) {
  PM.set(x, y);
  R = radius;
}

void CCircle::list() {
  cout << "CLine {" << endl;
  PM.list();
  cout << "R = " << R << endl;
  cout << "}" << endl;
}
