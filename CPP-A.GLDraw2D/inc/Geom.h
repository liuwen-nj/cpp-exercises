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

class CLine;
class CRectangle;
class CCircle;

class CPoint {
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

class CLine {
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

class CRectangle {
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
    void list();
	void draw();
};

class CCircle {
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



#endif /* GEOM_H_ */
