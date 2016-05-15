/*
 * Rectangle.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include <algorithm>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/Rectangle.h"
#include "../inc/Drawing.h"

using namespace std;


// CRectangle //////////////////////////////////////

// static functions and variables

unsigned long CRectangle::ulCount = 0;

void CRectangle::listCount() {
  cout << "# CRectangles: " << CRectangle::ulCount << endl;
}

// constructors

CRectangle::CRectangle() {
  ulCount++;
  set(0, 0, 0, 0);
}

CRectangle::CRectangle(double x1, double y1, double x2, double y2) {
  ulCount++;
  set(x1, y1, x2, y2);
}

CRectangle::CRectangle(CPoint p1, CPoint p2) {
  ulCount++;
  set(p1, p2);
}

// copy constructor

CRectangle::CRectangle(const CRectangle& obj) {
  ulCount++;
  set(obj.P1, obj.P2);
}

// operator +: implemented as bounding box for both rectangles

CRectangle CRectangle::operator+(const CRectangle& cRectangle) {
  float minX = min(this->P1.X, min(this->P2.X, min(cRectangle.P1.X, cRectangle.P2.X)));
  float maxX = max(this->P1.X, max(this->P2.X, max(cRectangle.P1.X, cRectangle.P2.X)));
  float minY = min(this->P1.Y, min(this->P2.Y, min(cRectangle.P1.Y, cRectangle.P2.Y)));
  float maxY = max(this->P1.Y, max(this->P2.Y, max(cRectangle.P1.Y, cRectangle.P2.Y)));

  return CRectangle(CPoint(minX, maxY), CPoint(maxX, minY));
}

// destructor

CRectangle::~CRectangle() {
  ulCount--;
}

// member functions

void CRectangle::set(double x1, double y1, double x2, double y2) {
  P1.set(x1, y1);
  P2.set(x2, y2);
}

void CRectangle::set(CPoint p1, CPoint p2) {
  P1.set(p1.X, p1.Y);
  P2.set(p2.X, p2.Y);
}

void CRectangle::list() {
  cout << "CRectangle {" << endl;
  P1.list();
  P2.list();
  cout << "}" << endl;
}

void CRectangle::draw() {
	glRectf(P1.X, P1.Y, P2.X, P2.Y);
}
