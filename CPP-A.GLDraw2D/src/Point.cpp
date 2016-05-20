/*
 * Point.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/Point.h"
#include "../inc/Drawing.h"

using namespace std;


// CPoint //////////////////////////////////////

// static functions and variables

unsigned long CPoint::ulCount = 0;

void CPoint::listCount() {
  cout << "# CPoints: " << CPoint::ulCount << endl;
}

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

// operator +

CPoint CPoint::operator+(const CPoint& obj) const
{
	float x = this->X + obj.X;
	float y = this->Y + obj.Y;

	return CPoint(x, y);
}

// operator -

CPoint CPoint::operator-(const CPoint& obj) const
{
	float x = this->X - obj.X;
	float y = this->Y - obj.Y;

	return CPoint(x, y);
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

void CPoint::draw(void) {
	// define the size of cross
	static const float crosslength = 5;

	// draw the cross using two lines
	glBegin(GL_LINES);
	glVertex2f(X - crosslength, Y);
	glVertex2f(X + crosslength + 1, Y);
	glVertex2f(X, Y - (crosslength + 1));
	glVertex2f(X, Y + crosslength);
	glEnd();
}

void CPoint::load(istream* stream) {
  string x, y;
  getline(*stream, x);
  getline(*stream, y);

  set(stod(x), stod(y));
}

void CPoint::save(std::ostream* stream) {
  CDrawing::EFigType myType = CDrawing::FIG_POINT;
  (*stream) << myType << endl;
  (*stream) << X << endl;
  (*stream) << Y << endl;
}
