/*
 * Rectangle.h
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Figure.h"
#include "Point.h"

using namespace std;


class CRectangle : virtual public CFigure {
  private:
    CPoint P1;
    CPoint P2;

  public:
    static unsigned long ulCount;
    static void listCount();

    CRectangle();
    CRectangle(double, double, double, double);
    CRectangle(CPoint, CPoint);
    CRectangle(const CRectangle&);
    CRectangle operator+(const CRectangle&);
    ~CRectangle();

    void set(double, double, double, double);
    void list(void);
	  void draw(void);
};



#endif /* RECTANGLE_H_ */
