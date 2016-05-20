/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures 
         of a drawing. This includes functions to display, append, remove 
         and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
/////////////////////////////////////////////////////////////////////////////*/


#ifndef _DRAWING_H_
#define _DRAWING_H_

// system includes ////////////////////////////////////////////////////////////
#include <string>
#include "Point.h"
using namespace std;



class CDrawing
///////////////////////////////////////////////////////////////////////////////
{
public: // types
	enum EViewMode { VIEW_DRAWING, VIEW_LISTING };
	enum EFigType { FIG_POINT=0x10, FIG_LINE=0x20, FIG_RECT=0x30, FIG_CIRCLE=0x40 };
  static int WIDTH, HEIGTH;

public: // functions
  static void reportWindowSize(int width, int height);
	static void displayDrawing( EViewMode mode =  VIEW_DRAWING );
  static void addRandomFigures(void);
	static void clearDrawing( void );
	static void appendFigure( EFigType figtype, const CPoint& p1, const CPoint& p2 );
	static void removeFigure( void );
	static void loadDrawingFile(const string& filename);
	static void saveDrawingFile(const string& filename);
};

#endif // _DRAWING_H_ /////////////////////////////////////////////////////////
