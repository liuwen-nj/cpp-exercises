/*
 * Point.h
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#ifndef POINT_H_
#define POINT_H_

#include "Figure.h"

using namespace std;

class CLine;
class CRectangle;
class CCircle;

class CPoint : public CFigure {
  friend class CLine;
  friend class CRectangle;
  friend class CCircle;

  private:
    double X;
    double Y;

  public:
    static unsigned long ulCount;
    static void listCount();

    CPoint();
    CPoint(double, double);
    CPoint(const CPoint&);
	  CPoint operator+(const CPoint&);
	  CPoint operator-(const CPoint&);
    ~CPoint();

    void set(double, double);
    void list();
	void draw();
};

#endif /* POINT_H_ */
