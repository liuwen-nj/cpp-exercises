#ifndef _FIGURE_H_
#define _FIGURE_H_

class CFigure {
private:
  static unsigned long ulCount;

public:
  static void listCount();

  CFigure();
  CFigure(const CFigure&);
  virtual ~CFigure();

  virtual void list(void) = 0;
  virtual void draw(void) = 0;
};

#endif