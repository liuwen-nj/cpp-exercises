/*
 * Circle.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <FL/glut.H>

#include "../inc/Circle.h"
#include "../inc/Drawing.h"

using namespace std;


// CCircle //////////////////////////////////////

// static functions and variables

unsigned long CCircle::ulCount = 0;

void CCircle::listCount() {
  cout << "# CCircles: " << ulCount << endl;
}

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

CCircle::CCircle(CPoint p1, CPoint p2) {
  ulCount++;
  set(p1, p2);
}

// copy constructor

CCircle::CCircle(const CCircle& obj) {
  ulCount++;
  PM = obj.PM;
  R = obj.R;
}

// operator +: implemented as bounding box for both circles

CCircle CCircle::operator+(const CCircle& cCircle) {
	
	// Circle 1 = this
	// Circle 2 = cCircle

	// calculate distance between the two center points
	float X1X2 = cCircle.PM.X - this->PM.X;
	float Y1Y2 = cCircle.PM.Y - this->PM.Y;
	float dM1M2 = sqrt(pow(X1X2, 2) + pow(Y1Y2, 2));
	
	// calculate radius of bounding circle
	float R_bounding = (this->R + cCircle.R + dM1M2) / 2;

	// calculate coordinates of farest away point to circle 2 on circumference of cirlce 1
	float F_X = this->PM.X - this->R * (X1X2 / dM1M2);
	float F_Y = this->PM.Y - this->R * (Y1Y2 / dM1M2);

	// calculate coordinates of center point of bounding circle
	float PM_bounding_x = F_X + R_bounding * (X1X2 / dM1M2);
	float PM_bounding_y = F_Y + R_bounding * (Y1Y2 / dM1M2);

	return CCircle(CPoint(PM_bounding_x, PM_bounding_y), R_bounding);
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

void CCircle::set(CPoint p1, CPoint p2) {
  PM.set(p1.X, p1.Y);
  float dP1P2 = sqrt(pow(p2.X-p1.X, 2) + pow(p2.Y-p1.Y, 2));
  R = dP1P2;
}

void CCircle::list() {
  cout << "CCircle {" << endl;
  PM.list();
  cout << "R = " << R << endl;
  cout << "}" << endl;
}

void CCircle::draw() {
	glPushMatrix();
	glTranslatef((GLfloat)PM.X, (GLfloat)PM.Y, 0.0);
	gluDisk(gluNewQuadric(), R, R, 100, 1);
	glPopMatrix();
}
