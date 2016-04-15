/*
 * Geom.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
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

CLine::CLine(const CLine& obj) {
  ulCount++;
  P1 = obj.P1;
  P2 = obj.P2;
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

CRectangle::CRectangle(const CRectangle& obj) {
  ulCount++;
  P1 = obj.P1;
  P2 = obj.P2;
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

CCircle::CCircle(const CCircle& obj) {
  ulCount++;
  PM = obj.PM;
  R = obj.R;
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
