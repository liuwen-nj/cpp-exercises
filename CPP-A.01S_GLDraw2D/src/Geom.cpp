/*
 * Geom.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include "Geom.h"

CPoint::CPoint(double coordinateX, double coordinateY) {
  set(coordinateX, coordinateY);
}

void CPoint::set(double coordinateX, double coordinateY) {
  x = coordinateX;
  y = coordinateY;
}

string CPoint::list() {
  return "[x=" + to_string(x) + "; y=" + to_string(y) + "]";
}

CLine::CLine(CPoint* pointA, CPoint* pointB) {
  set(pointA, pointB);
}

void CLine::set(CPoint* pointA, CPoint* pointB) {
  pA = pointA;
  pB = pointB;
}

string CLine::list() {
  return "[A=" + (*pA).list() + "; B=" + (*pB).list() + "]";
}

CRectangle::CRectangle(CPoint* pointA, CPoint* pointB) {
  set(pointA, pointB);
}

void CRectangle::set(CPoint* pointA, CPoint* pointB) {
  pA = pointA;
  pB = pointB;
}

string CRectangle::list() {
  return "[A=" + (*pA).list() + "; B=" + (*pB).list() + "]";
}

CCircle::CCircle(CPoint* pointM, double radius) {
  set(pointM, radius);
}

void CCircle::set(CPoint* pointM, double radius) {
  pM = pointM;
  r = radius;
}

string CCircle::list() {
 return "[M=" + (*pM).list() + "; r=" + to_string(r) + "]";
}
