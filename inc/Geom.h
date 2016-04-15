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
    double X;
    double Y;

  public:
    void set(double, double);
    void list();
};

class CLine {
  private:
    CPoint P1;
    CPoint P2;

  public:
    void set(double, double, double, double);
    void list();
};

class CRectangle {
  private:
    CPoint P1;
    CPoint P2;

  public:
    void set(double, double, double, double);
    void list();
};

class CCircle {
  private:
    CPoint PM;
    double R;

  public:
    void set(double, double, double);
    void list();
};

#endif /* GEOM_H_ */
