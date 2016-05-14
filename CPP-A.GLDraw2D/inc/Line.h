/*
 * Line.h
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#ifndef LINE_H_
#define LINE_H_

#include "Figure.h"
#include "Point.h"

using namespace std;


class CLine : public CFigure {
  private:
    CPoint P1;
    CPoint P2;

  public:
    static unsigned long ulCount;
    static void listCount();

    CLine();
    CLine(double, double, double, double);
    CLine(CPoint, CPoint);
    CLine(const CLine&);
    CLine& operator=(const CLine&);
    CLine operator+(const CLine&);
    ~CLine();

    void set(double, double, double, double);
    void list();
	void draw();
};

#endif /* LINE_H_ */
