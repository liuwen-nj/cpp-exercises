/*
 * Geom.h
 *
 *  Created on: 09.04.2016
 *      Author: cst
 */

#ifndef GEOM_H_
#define GEOM_H_

#include <string>
using namespace std;

class CPoint {
  private:
    double x;
    double y;

  public:
    CPoint(double, double);
    void set(double, double);
    string list();
};

class CLine {
  private:
    CPoint* pA;
    CPoint* pB;

  public:
    CLine(CPoint*, CPoint*);
    void set(CPoint*, CPoint*);
    string list();
};

class CRectangle {
  private:
    CPoint* pA;
    CPoint* pB;

  public:
    CRectangle(CPoint*, CPoint*);
    void set(CPoint*, CPoint*);
    string list();
};

class CCircle {
  private:
    CPoint* pM;
    double r;

  public:
    CCircle(CPoint*, double);
    void set(CPoint*, double);
    string list();
};

#endif /* GEOM_H_ */
