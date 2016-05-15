/*
 * Line.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/Line.h"
#include "../inc/Drawing.h"

using namespace std;



// CLine //////////////////////////////////////

// static functions and variables

unsigned long CLine::ulCount = 0;

void CLine::listCount() {
  cout << "# CLines: " << CLine::ulCount << endl;
}

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

void CLine::draw() {
	glBegin(GL_LINES);
	glVertex2f(P1.X, P1.Y);
	glVertex2f(P2.X, P2.Y);
	glEnd();
}
