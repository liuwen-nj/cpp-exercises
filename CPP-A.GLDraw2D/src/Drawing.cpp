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
#include <fstream> 

using namespace std;



// application includes ///////////////////////////////////////////////////////
#include "../inc/Exceptions.h"
#include "../inc/Drawing.h"
#include "../inc/Point.h"
#include "../inc/Line.h"
#include "../inc/Rectangle.h"
#include "../inc/Circle.h"



// static data definitions ////////////////////////////////////////////////////
int CDrawing::WIDTH = 800;
int CDrawing::HEIGTH = 600;

// member variables
bool initializedRandomFigures = false;
vector<CFigure*> figures;
vector<CFigure*>::iterator pos;
string fileID = "GLDraw2DFileID";


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
  if (!initializedRandomFigures) {
    addRandomFigures();
    initializedRandomFigures = true;
  }
  
  switch (mode) {
  
  case VIEW_DRAWING:
    // draw figures
    for (pos = figures.begin(); pos != figures.end(); ++pos) {
      (*pos)->draw();
    }

    // list total amount of generated figures
    CFigure::listCount();
    CPoint::listCount();
    CLine::listCount();
    CRectangle::listCount();
    CCircle::listCount();
    break;

  case VIEW_LISTING:
    for (pos = figures.begin(); pos != figures.end(); ++pos) {
      (*pos)->list();
    }
    break;
  }

}
// CDrawing::displayDrawing() /////////////////////////////////////////////////

void CDrawing::addRandomFigures(void) {
  const int pointAmount = 30;
  const int lineAmount = 10;
  const int rectangleAmount = 5;
  const int circleAmount = 5;

  const int maxLineLength = 100;
  const int maxRectangleSideLength = 100;
  const int maxCircleRadius = 100;

  srand(time(nullptr));

  // add random points to vector
  for (int i = 0; i < pointAmount; i++) {
    double x = static_cast<double>(rand() % CDrawing::WIDTH);
    double y = static_cast<double>(rand() % CDrawing::HEIGTH);
    CPoint* p = new CPoint(x, y);
    figures.push_back(p);
  }

  // add random lines to vector
  for (int i = 0; i < lineAmount; i++) {
    double x1 = static_cast<double>(rand() % CDrawing::WIDTH);
    double y1 = static_cast<double>(rand() % CDrawing::HEIGTH);

    double x2, y2, lineLength;

    do {
      x2 = static_cast<double>(rand() % CDrawing::WIDTH);
      y2 = static_cast<double>(rand() % CDrawing::HEIGTH);
      lineLength = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    } while (lineLength > maxLineLength);

    CPoint p1{ x1, y1 };
    CPoint p2{ x2, y2 };
    CLine* l = new CLine(p1, p2);

    figures.push_back(l);
  }

  // add random rectangles to vector
  for (int i = 0; i < rectangleAmount; i++) {
    double x1 = static_cast<double>(rand() % CDrawing::WIDTH);
    double y1 = static_cast<double>(rand() % CDrawing::HEIGTH);
    CPoint p1{ x1, y1 };

    float x2, y2;
    do {
      x2 = static_cast<double>(rand() % CDrawing::WIDTH);
    } while (abs(x1 - x2) > maxRectangleSideLength);

    do {
      y2 = static_cast<double>(rand() % CDrawing::HEIGTH);
    } while (abs(y1 - y2) > maxRectangleSideLength);

    CPoint p2{ x2, y2 };
    CRectangle* r = new CRectangle(p1, p2);

    figures.push_back(r);
  }

  // add random circles to vector
  for (int i = 0; i < circleAmount; i++) {
    int radius = rand() % maxCircleRadius;
    double x, y;

    do {
      x = static_cast<double>(rand() % (CDrawing::WIDTH - radius));
      y = static_cast<double>(rand() % (CDrawing::HEIGTH - radius));
    } while (x - radius < 0 || y - radius < 0);

    CPoint pM{ x, y };
    CCircle* c = new CCircle(pM, radius);

    figures.push_back(c);
  }
}

///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing( void ) {
  // delete figures
  for (pos = figures.begin(); pos != figures.end(); ++pos) {
    delete (*pos);
  }
  figures.clear();
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
    figures.push_back(new CPoint(p1));
    break;

  case FIG_LINE:
    figures.push_back(new CLine(p1, p2));    
    break;

  case FIG_RECT:
    figures.push_back(new CRectangle(p1, p2));
    break;

  case FIG_CIRCLE:
    figures.push_back(new CCircle(p1, p2));
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
  if (!figures.empty()) {
    delete figures.back();
    figures.pop_back();
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

  ifstream ifs(filename);
  string line;

  getline(ifs, line);
  if (line != fileID) {
    throw CErrorFileID();
  }

  clearDrawing();

  while (getline(ifs, line)) {
    // skip semicolon
    if (line == ";")  continue;

    // read code
    int code = stoi(line);

    CFigure* fig = nullptr;
    switch(code) {
    case FIG_POINT:
      fig = new CPoint();
      break;
    case FIG_LINE:
      fig = new CLine();
      break;
    case FIG_RECT:
      fig = new CRectangle();
      break;
    case FIG_CIRCLE:
      fig = new CCircle();
      break;
    default:
      throw CErrorFigureType();
    }
    fig->load(&ifs);
    figures.push_back(fig);
  }
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
   // set deviation to file
  streambuf* strm_buffer = cout.rdbuf();
  ofstream ofs (filename);
  cout.rdbuf(ofs.rdbuf());

  // write file ID as first output line
  cout << fileID << endl;

  // save data to file
  for (pos = figures.begin(); pos != figures.end(); ++pos) {
    (*pos)->save(&cout);
    cout << ";" << endl;
  }

  // reset deviation
  cout.rdbuf(strm_buffer);
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
