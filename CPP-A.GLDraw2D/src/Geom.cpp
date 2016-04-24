/*
 * Geom.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include "../inc/Geom.h"
using namespace std;

// CPoint //////////////////////////////////////

// constructors

CPoint::CPoint() {
  ulCount++;
  set(0, 0);
}

CPoint::CPoint(double coordinateX, double coordinateY) {
  ulCount++;
  set(coordinateX, coordinateY);
}

CPoint::CPoint(const CPoint& obj) {
  ulCount++;
  X = obj.X;
  Y = obj.Y;
}

// destructor

CPoint::~CPoint() {
  ulCount--;
}

// member functions

void CPoint::set(double coordinateX, double coordinateY) {
  X = coordinateX;
  Y = coordinateY;
}

void CPoint::list() {
  cout << "CPoint " << " [x=" << X << "; y=" << Y << "]" << endl;
}

// static functions and variables

unsigned long CPoint::ulCount = 0;

void CPoint::listCount() {
  cout << "# CPoints: " << ulCount << endl;
}

// CLine //////////////////////////////////////

//constructors

CLine::CLine() {
  ulCount++;
  set(0, 0, 0, 0);
}

CLine::CLine(double x1, double y1, double x2, double y2) {
  ulCount++;
  set(x1, y1, x2, y2);
}

CLine::CLine(CPoint p1, CPoint p2) {
  ulCount++;
  P1 = p1;
  P2 = p2;
}

// copy constructor

CLine::CLine(const CLine& obj) {
  ulCount++;
  P1 = obj.P1;
  P2 = obj.P2;
}

// assignment operator

CLine& CLine::operator=(const CLine& cLine) {
  P1 = cLine.P1;
  P2 = cLine.P2;
  return *this;
}

// + operator implemented as vector addition c = a + b; assumes that starting point of line c will be the same as starting point of line a

CLine CLine::operator+(const CLine& cLine) {
  // create points of new line
  CPoint C1, C2;

  // calculate delta values of line B to calculate new end point below
  float dx = cLine.P2.X - cLine.P1.X;
  float dy = cLine.P2.Y - cLine.P1.Y;

  // set coordinates of new points
  C1.set(this->P1.X, this->P1.Y); // new line will start from P1 of line A
  C2.set(this->P2.X + dx, this->P2.Y + dy);

  return CLine(C1, C2);
}

// destructor

CLine::~CLine() {
  ulCount--;
}

// member functions

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

// static functions and variables

unsigned long CLine::ulCount = 0;

void CLine::listCount() {
  cout << "# CLines: " << ulCount << endl;
}

// CRectangle //////////////////////////////////////

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
  P1 = p1;
  P2 = p2;
}

// copy constructor

CRectangle::CRectangle(const CRectangle& obj) {
  ulCount++;
  P1 = obj.P1;
  P2 = obj.P2;
}

// operator +: implemented as bounding box for both rectangles

CRectangle CRectangle::operator+(const CRectangle& cRectangle) {
  float minX = min({this->P1.X, this->P2.X, cRectangle.P1.X, cRectangle.P2.X});
  float maxX = max({this->P1.X, this->P2.X, cRectangle.P1.X, cRectangle.P2.X});
  float minY = min({this->P1.Y, this->P2.Y, cRectangle.P1.Y, cRectangle.P2.Y});
  float maxY = max({this->P1.Y, this->P2.Y, cRectangle.P1.Y, cRectangle.P2.Y});

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

void CRectangle::list() {
  cout << "CRectangle {" << endl;
  P1.list();
  P2.list();
  cout << "}" << endl;
}

// static functions and variables

unsigned long CRectangle::ulCount = 0;

void CRectangle::listCount() {
  cout << "# CRectangles: " << ulCount << endl;
}

// CCircle //////////////////////////////////////

// constructors

CCircle::CCircle() {
  ulCount++;
  set(0, 0, 0);
}

CCircle::CCircle(double x, double y, double radius) {
  ulCount++;
  set(x, y, radius);
}

CCircle::CCircle(CPoint m, double radius) {
  ulCount++;
  PM = m;
  R = radius;
}

// copy constructor

CCircle::CCircle(const CCircle& obj) {
  ulCount++;
  PM = obj.PM;
  R = obj.R;
}

// operator +: implemented as bounding box for both circles

CCircle CCircle::operator+(const CCircle& cCircle) {
  // calculate coordinates of new center point
  float M_X = (this->PM.X + cCircle.PM.X) / 2;
  float M_Y = (this->PM.Y + cCircle.PM.Y) / 2;

  // calculate distance between new center point and old center points
  float dM = sqrt(pow(this->PM.X - M_X, 2) + pow(this->PM.Y - M_Y, 2));

  // determine the larger of the 2 old radius
  float maxR = max(this->R, cCircle.R);

  return CCircle(CPoint(M_X, M_Y), dM+maxR);
}

// destructor

CCircle::~CCircle() {
  --ulCount;
}

// member functions

void CCircle::set(double x, double y, double radius) {
  PM.set(x, y);
  R = radius;
}

void CCircle::list() {
  cout << "CCircle {" << endl;
  PM.list();
  cout << "R = " << R << endl;
  cout << "}" << endl;
}

// static functions and variables

unsigned long CCircle::ulCount = 0;

void CCircle::listCount() {
  cout << "# CCircles: " << ulCount << endl;
}
