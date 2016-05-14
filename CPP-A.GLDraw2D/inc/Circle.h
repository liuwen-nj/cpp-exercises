/*
 * Circle.h
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Figure.h"
#include "Point.h"

using namespace std;


class CCircle : public CFigure {
  private:
    CPoint PM;
    double R;

  public:
    static unsigned long ulCount;
    static void listCount();

    CCircle();
    CCircle(double, double, double);
    CCircle(CPoint, double);
    CCircle(const CCircle&);
    CCircle operator+(const CCircle&);
    ~CCircle();

    void set(double, double, double);
    void list();
	void draw();
};


#endif /* CIRCLE_H_ */
