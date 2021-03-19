/**
 * Line.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a line.
 */

#ifndef LINE_H
#define LINE_H

#include <iostream>
using namespace std;

#include "Color.h"
#include "Point.h"
#include "Graphics.h"
#include "Shape.h"


class Line: public Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    Line();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Overloaded contructor. Sets color, start to pt1, end to pt2.
     */
    Line(Point pt1, Point pt2, Color color);

    /**
     * Requires: Nothing.
     * Modifies: start.
     * Effects:  Sets start point of line.
     */
    void setStart(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns start point of line.
     */
    Point getStart();

    /**
     * Requires: Nothing.
     * Modifies: end.
     * Effects:  Sets end point of line.
     */
    void setEnd(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns end point of line.
     */
    Point getEnd();

    /**
     * Requires: Nothing.
     * Modifies: lineColor.
     * Effects:  Sets color of line.
     */
    void setColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns color of line.
     */
    Color getColor();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, start, end, lineColor.
     * Effects:  Reads line in form startPoint  endPoint  color
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes line in form startPoint  endPoint  color
     */
    void write(ostream& outs);

    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws line onto drawer.
     */
    void draw(Graphics& drawer);

private:
    Point start;
    Point end;
    Color lineColor;
};

/**
 * Overloading >> and << for reading and writing Line to and from streams.
 */
istream& operator >> (istream& ins, Line& line);
ostream& operator << (ostream& outs, Line line);

#endif
