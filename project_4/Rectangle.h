/**
 * Rectangle.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a rectangle.
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Graphics.h"

class Rectangle: public Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    Rectangle();

    /**
     * Requires: Nothing.
     * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
     *           colorBottomLeft.
     * Effects:  Overloaded contructor. Sets start, end and single color.
     */
    Rectangle(Point pt1, Point pt2, Color color);

    /**
     * Requires: Nothing.
     * Modifies: start, end, colorTopLeft, colorTopRight, colorBottomRight,
     *           colorBottomLeft.
     * Effects:  Overloaded contructor. Sets start, end and four colors.
     */
    Rectangle(Point pt1, Point pt2, Color cTopLeft, Color cTopRight,
              Color cBottomRight, Color cBottomLeft);

    /**
     * Requires: Nothing.
     * Modifies: start.
     * Effects:  Sets start point (top left) of rectangle.
     */
    void setStart(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns start point of rectangle.
     */
    Point getStart();

    /**
     * Requires: Nothing.
     * Modifies: end.
     * Effects:  Sets end point (bottom right) of rectangle.
     */
    void setEnd(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns end point of rectangle.
     */
    Point getEnd();

    /**
     * Requires: Nothing.
     * Modifies: colorTopLeft, colorTopRight, colorBottomRight, colorBottomLeft.
     * Effects:  Sets the four colors of rectangle to color.
     */
    void setColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: colorTopLeft.
     * Effects:  Sets top left color of rectangle.
     */
    void setColorTopLeft(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns top left color of rectangle.
     */
    Color getColorTopLeft();

    /**
     * Requires: Nothing.
     * Modifies: colorTopRight.
     * Effects:  Sets top right color of rectangle.
     */
    void setColorTopRight(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns top right color of rectangle.
     */
    Color getColorTopRight();

    /**
     * Requires: Nothing.
     * Modifies: colorBottomRight.
     * Effects:  Sets bottom rihgt color of rectangle.
     */
    void setColorBottomRight(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns bottom right color of rectangle.
     */
    Color getColorBottomRight();

    /**
     * Requires: Nothing.
     * Modifies: colorBottomLeft.
     * Effects:  Sets bottom left color of rectangle.
     */
    void setColorBottomLeft(Color c);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns bottom left color of rectangle.
     */
    Color getColorBottomLeft();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, start, end, colorTopLeft, colorTopRight,
     *           colorBottomRight, colorBottomLeft.
     * Effects:  Reads rectangle in forms
     *           start end color
     *           start end cTopLeft cTopRight cBottomRight cBottomLeft
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes rectangle in form
     *           start end cTopLeft cTopRight cBottomRight cBottomLeft
     */
    void write(ostream& outs);

    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws rectangle onto drawer.
     */
    void draw(Graphics& drawer);

private:
    Point start;
    Point end;
    Color colorTopLeft;
    Color colorTopRight;
    Color colorBottomRight;
    Color colorBottomLeft;
};

/**
 * Overloading >> and << for reading and writing Rectangle to and from streams.
 */
istream& operator >> (istream& ins, Rectangle& rectangle);
ostream& operator << (ostream& outs, Rectangle rectangle);

#endif
