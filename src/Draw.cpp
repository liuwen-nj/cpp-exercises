/*
 * Draw.cpp
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#include <iostream>
#include "../inc/Geom.h"
using namespace std;

CPoint createPoint() {
  double x, y;
  cout << "Please enter X coordinate: ";
  cin >> x;
  cout << "Please enter Y coordinate: ";
  cin >> y;

  CPoint point;
  point.set(x, y);
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
  line.set(x1, y1, x2, y2);
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

void listNumbers() {
  cout << endl;
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();
  cout << endl;
}

void getAndHandleUserInput() {
  bool quit = false;

  while (!quit) {
    int i;
    cout
        << "Please input: draw point (1), draw line (2), rectangle (3) or circle (4) ? List numbers (9). Quit (0)."
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
    case 9:
      listNumbers();
      break;
    default:
      cout << "Not a valid input!" << endl;
      break;
    }
  }
}

int main() {

  CLine L1(10, 10, 20, 20);
  CLine* pL2 = new CLine(CPoint(5, 5), CPoint(55, 55));

  L1.list();
  (*pL2).list();
  listNumbers();

  CRectangle R1(4, 5, 1, 9);
  R1.list();
  listNumbers();

  delete pL2;
  listNumbers();

  {
    CCircle C1(CPoint(10, 15), 30);
    C1.list();
    listNumbers();

    CCircle* C2 = new CCircle();
    (*C2).list();
    listNumbers();
  }

  listNumbers();

  CRectangle R2(R1);
  R2.list();
  listNumbers();

  CRectangle R3(12, 45, 67, 67);
  R3.list();
  listNumbers();

  CCircle C3(1, 6, 30);
  CCircle C4 = C3;

  C3.set(2, 12, 15);

  C3.list();
  listNumbers();

  C4.list();
  listNumbers();

  // getAndHandleUserInput();

  cout << "Quitting program..";
  return 0;
}

