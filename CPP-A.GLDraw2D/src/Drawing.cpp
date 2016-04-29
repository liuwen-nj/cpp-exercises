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
#include <time.h>
#include <vector>
using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/Geom.h"



// static data definitions ////////////////////////////////////////////////////
int CDrawing::WIDTH = 800;
int CDrawing::HEIGTH = 600;

void CDrawing::reportWindowSize(int width, int height) {
  CDrawing::WIDTH = width;
  CDrawing::HEIGTH = height;
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
  srand(time(NULL));

  const int pointAmount = 30;
  CPoint points[pointAmount];

  for (int i = 0; i < pointAmount; i++) {
    points[i].set((double)(rand() % CDrawing::WIDTH), (double)(rand() % CDrawing::HEIGTH));
  }

  const int lineAmount = 10;
  const int maxLineLength = 100;
  vector<CLine> lines;

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

    lines.push_back(CLine{ p1, p2 });
  }

  const int rectangleAmount = 5;
  const int maxSideLength = 100;
  vector<CRectangle> rectangles;

  for (int i = 0; i < rectangleAmount; i++) {
    float x1 = (float) (rand() % CDrawing::WIDTH);
    float y1 = (float) (rand() % CDrawing::HEIGTH);
    CPoint p1{ x1, y1 };

    float x2, y2;
    do {
      x2 = (float) (rand() % CDrawing::WIDTH);
    } while (abs(x1 - x2) > maxSideLength);

    do {
      y2 = (float)(rand() % CDrawing::HEIGTH);
    } while (abs(y1 - y2) > maxSideLength);

    CPoint p2{ x2, y2 };

    rectangles.push_back(CRectangle{ p1, p2 });
  }

  const int circleAmount = 5;
  const int maxRadius = 100;
  vector<CCircle> circles;

  for (int i = 0; i < circleAmount; i++) {
    int radius = rand() % maxRadius;
    float x, y;

    do {
      x = (float)(rand() % (CDrawing::WIDTH - radius));
      y = (float)(rand() % (CDrawing::HEIGTH - radius));
    } while (x - radius < 0 || y - radius < 0);
    
    CPoint pM{ x, y };

    circles.push_back(CCircle(pM, radius));
  }

  switch (mode) {
  case VIEW_DRAWING:
    for (int i = 0; i < pointAmount; i++) {
      points[i].draw();
    }
    for (int i = 0; i < lineAmount; i++) {
      lines[i].draw();
    }
    for (int i = 0; i < rectangleAmount; i++) {
      rectangles[i].draw();
    }
    for (int i = 0; i < circleAmount; i++) {
      circles[i].draw();
    }
    cout << endl << "Amount of points: ";
    CPoint::listCount();
    cout << endl << "Amount of lines: ";
    CLine::listCount();
    cout << endl << "Amount of rectangles: ";
    CRectangle::listCount();
    cout << endl << "Amount of circles: ";
    CCircle::listCount();
    break;

  case CDrawing::VIEW_LISTING:
    for (int i = 0; i < pointAmount; i++) {
      points[i].list();
    }
    for (int i = 0; i < lineAmount; i++) {
      lines[i].list();
    }
    for (int i = 0; i < rectangleAmount; i++) {
      rectangles[i].list();
    }
    for (int i = 0; i < circleAmount; i++) {
      circles[i].list();
    }
    break;
  }
}
// CDrawing::displayDrawing() /////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing( void )
///////////////////////////////////////////////////////////////////////////////
{
	// TODO: insert code to clear drawing data
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
	// TODO: add code to append figure to list
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
	// TODO: add code to remove figure from list
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
