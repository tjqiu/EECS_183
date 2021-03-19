/**
 * Circle.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a circle
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
using namespace std;

#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Graphics.h"

// Note:  radius must be >= 0

class Circle: public Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    Circle();

    /**
     * Requires: Nothing.
     * Modifies: center, radius, color.
     * Effects:  Overloaded contructor. Sets center, radius and single color.
     *           Radius of must be positive, so you must call checkRadius.
     */
    Circle(Point pt, int r, Color c);

    /**
     * Requires: Nothing.
     * Modifies: center.
     * Effects:  Sets center of circle.
     */
    void setCenter(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns center of circle.
     */
    Point getCenter();

    /**
     * Requires: Nothing.
     * Modifies: radius.
     * Effects:  Sets radius of circle. Radius of circle must be positive,
     *           so you must call checkRadius.
     */
    void setRadius(int r);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns radius of circle.
     */
    int getRadius();

    /**
     * Requires: Nothing.
     * Modifies: color.
     * Effects:  Sets color of circle.
     */
    void setColor(Color c);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns color of circle.
     */
    Color getColor();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, center, radius, color.
     * Effects:  Read circle in form center radius color
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes circle in form center radius color
     */
    void write(ostream& outs);

    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws circle onto drawer.
     */
    void draw(Graphics& drawer);

private:
    Point center;
    int radius;
    Color color;

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns absolute value of radius.
     */
    int checkRadius(int radius);

    /**
     * Helper functions for drawing triangle.
     */
    void plot8points(int x, int y, Color c, Graphics& drawer);
    void plot4points(int x, int y, Color c, Graphics& drawer);

};

/**
 * Overloading >> and << for reading and writing Circle to and from streams.
 */
istream& operator >> (istream& ins, Circle& circle);
ostream& operator << (ostream& outs, Circle circle);

#endif
