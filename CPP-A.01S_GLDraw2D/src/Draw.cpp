/*
 * Draw.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include "Geom.h"
using namespace std;

CPoint createPoint() {
  double x, y;
  cout << "Please enter X coordinate: ";
  cin >> x;
  cout << "Please enter Y coordinate: ";
  cin >> y;

  CPoint point;
  point.set(x,y);
  return point;
}

CLine createLine() {
  double x1, y1, x2, y2;
  cout << "Please enter X coordinate of first point: ";
  cin >> x1;
  cout << "Please enter Y coordinate of first point: ";
  cin >> y1;
  cout << "Please enter X coordinate of second point: ";
  cin >> x2;
  cout << "Please enter Y coordinate of second point: ";
  cin >> y2;

  CLine line;
  line.set(x1,y1,x2,y2);
  return line;
}

CRectangle createRectangle() {
  double x1, y1, x2, y2;
  cout << "Please enter X coordinate of first point: ";
  cin >> x1;
  cout << "Please enter Y coordinate of first point:";
  cin >> y1;
  cout << "Please enter X coordinate of second point: ";
  cin >> x2;
  cout << "Please enter Y coordinate of second point: ";
  cin >> y2;

  CRectangle rectangle;
  rectangle.set(x1, y1, x2, y2);
  return rectangle;
}

CCircle createCircle() {
  double x, y, r;
  cout << "Please enter X coordinate of center point: ";
  cin >> x;
  cout << "Please enter Y coordinate of center point: ";
  cin >> y;
  cout << "Please enter value for radius: ";
  cin >> r;

  CCircle circle;
  circle.set(x, y, r);
  return circle;
}

int main() {

  bool quit = false;

  while (!quit) {
    int i;
    cout
        << "Please input: draw point (1), draw line (2), rectangle (3) or circle (4) ? Quit (0)."
        << endl;
    cin >> i;

    switch (i) {
    case 0:
      quit = true;
      break;
    case 1: {
      CPoint point = createPoint();
      point.list();
    }
      break;
    case 2: {
      CLine line = createLine();
      line.list();
    }
      break;
    case 3: {
      CRectangle rectangle = createRectangle();
      rectangle.list();
    }
      break;
    case 4: {
      CCircle circle = createCircle();
      circle.list();
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

