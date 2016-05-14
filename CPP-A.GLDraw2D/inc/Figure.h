#pragma once

#ifndef _FIGURE_H_
#define _FIGURE_H_

class CFigure {
private:
  static unsigned long ulCount;

public:
  static void listCount();

  CFigure();
  CFigure(const CFigure&);
  ~CFigure();

  virtual void list() = 0;
  virtual void draw() = 0;
};

#endif