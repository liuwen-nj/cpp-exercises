/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures
         of a drawing. This includes functions to display, append, remove
         and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <time.h>
#include <vector>

using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/Point.h"
#include "../inc/Line.h"
#include "../inc/Rectangle.h"
#include "../inc/Circle.h"



// static data definitions ////////////////////////////////////////////////////
int CDrawing::WIDTH = 800;
int CDrawing::HEIGTH = 600;

// member variables
vector<CFigure*> randomFigures;
vector<CFigure*> userFigures;
vector<CFigure*>::iterator pos;


void CDrawing::reportWindowSize(int width, int height) {
  CDrawing::WIDTH = max(width, 200);
  CDrawing::HEIGTH = max(height, 200);
}

///////////////////////////////////////////////////////////////////////////////
// function: displayDrawing()
// purpose:  This function is called, if the GLUT window handler decides to
//           draw or redraw the window. This happens for instance if the user
//           draws a new figure or resizes or min/maximizes the window.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::displayDrawing( EViewMode mode )
///////////////////////////////////////////////////////////////////////////////
{
  
  
  /* // testing from here

  CPoint p1 { 5.3, 5.4 };

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();
  
  CPoint p2;
  p2 = p1;

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();

  CPoint p3 = p1;

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();

  CLine l1{ CPoint{1, 2}, CPoint(3, 4) };

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();

  CLine l2;
  l2.set(5, 6, 7, 8);

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();

  CLine l3 = l1 + l2;

  CFigure::listCount();
  CPoint::listCount();
  CLine::listCount();
  CRectangle::listCount();
  CCircle::listCount();

  // to here */
  
  const int pointAmount = 30;
  const int lineAmount = 10;
  const int rectangleAmount = 5;
  const int circleAmount = 5;

  const int maxLineLength = 100;
  const int maxRectangleSideLength = 100;
  const int maxCircleRadius = 100;

  srand(time(NULL));

  // add random points to vector
  for (int i = 0; i < pointAmount; i++) {
    double x = (double)(rand() % CDrawing::WIDTH);
    double y = (double)(rand() % CDrawing::HEIGTH);
    CPoint* p = new CPoint(x, y);
    randomFigures.push_back(p);
  }

  // add random lines to vector
  for (int i = 0; i < lineAmount; i++) {
    float x1 = (float)(rand() % CDrawing::WIDTH);
    float y1 = (float)(rand() % CDrawing::HEIGTH);

    float x2, y2, lineLength;

    do {
      x2 = (float)(rand() % CDrawing::WIDTH);
      y2 = (float)(rand() % CDrawing::HEIGTH);
      lineLength = sqrt( pow(x1-x2,2) + pow(y1-y2,2) );
    } while ( lineLength > maxLineLength );

    CPoint p1{ x1, y1 };
    CPoint p2{ x2, y2 };
    CLine* l = new CLine(p1, p2);

    randomFigures.push_back(l);
  }

  // add random rectangles to vector
  for (int i = 0; i < rectangleAmount; i++) {
    float x1 = (float) (rand() % CDrawing::WIDTH);
    float y1 = (float) (rand() % CDrawing::HEIGTH);
    CPoint p1{ x1, y1 };

    float x2, y2;
    do {
      x2 = (float) (rand() % CDrawing::WIDTH);
    } while (abs(x1 - x2) > maxRectangleSideLength);

    do {
      y2 = (float)(rand() % CDrawing::HEIGTH);
    } while (abs(y1 - y2) > maxRectangleSideLength);

    CPoint p2{ x2, y2 };
    CRectangle* r = new CRectangle(p1, p2);

    randomFigures.push_back(r);
  }

  // add random circles to vector
  for (int i = 0; i < circleAmount; i++) {
    int radius = rand() % maxCircleRadius;
    float x, y;

    do {
      x = (float)(rand() % (CDrawing::WIDTH - radius));
      y = (float)(rand() % (CDrawing::HEIGTH - radius));
    } while (x - radius < 0 || y - radius < 0);
    
    CPoint pM{ x, y };
    CCircle* c = new CCircle(pM, radius);

    randomFigures.push_back(c);
  }

  
  switch (mode) {
  
  case VIEW_DRAWING:
    // draw user generated figures
    for (pos = userFigures.begin(); pos != userFigures.end(); pos++) {
      (*pos)->draw();
    }
    // draw random figures
    for (pos = randomFigures.begin(); pos != randomFigures.end(); pos++) {
      (*pos)->draw();
    }
    // list total amount of generated figures
    CFigure::listCount();
    CPoint::listCount();
    CLine::listCount();
    CRectangle::listCount();
    CCircle::listCount();
    break;

  case CDrawing::VIEW_LISTING:
    for (pos = randomFigures.begin(); pos != randomFigures.end(); pos++) {
      (*pos)->list();
    }
    break;
  }

  // delete dynamically created figures and empty vector
  for (pos = randomFigures.begin(); pos != randomFigures.end(); pos++) {
    delete (*pos);
  }
  randomFigures.clear();

}
// CDrawing::displayDrawing() /////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing( void ) {
  // TODO
}
// CDrawing::clearDrawing() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: appendFigure()
// purpose:  This function is called, if the user starts drawing a new
//           figure in the window. For lines, rectangles and circles this
//           function is constantly called, until the user stops drawing by
//           releasing the left mouse button.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::appendFigure(EFigType figtype, const CPoint& p1, const CPoint& p2)
///////////////////////////////////////////////////////////////////////////////
{

  switch (figtype) {
  case FIG_POINT:
    userFigures.push_back(new CPoint(p1));
    break;

  case FIG_LINE:
    userFigures.push_back(new CLine(p1, p2));    
    break;

  case FIG_RECT:
    userFigures.push_back(new CRectangle(p1, p2));
    break;

  case FIG_CIRCLE:
    userFigures.push_back(new CCircle(p1, p2));
    break;
  }
}
// CDrawing::appendFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: removeFigure()
// purpose:  This function is called, to remove temporary figures while the
//           user is interactively drawing lines, rectangles or circles.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::removeFigure( void )
///////////////////////////////////////////////////////////////////////////////
{
  if (!userFigures.empty()) {
    delete userFigures.back();
    userFigures.pop_back();
  }

}
// CDrawing::removeFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: loadDrawingFile()
// purpose:  This function is called, if the user loads a figure drawing
//           file from external storage. The read data will be used to re-
//           instantiate the corresponding figure objects.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::loadDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add drawing file reading code here
}
// CDrawing::loadDrawingFile() ////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: saveDrawingFile()
// purpose:  This function is called, if the user saves a figure drawing
//           file to external storage. The filename parameter contains the
//           user selected file path of the drawing file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::saveDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: add drawing file writing code here
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
