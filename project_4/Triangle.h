/**
 * Triangle.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a triangle
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <cmath>
#include <iostream>
using namespace std;

#include "Point.h"
#include "Color.h"
#include "Graphics.h"
#include "Shape.h"
#include "utility.h"

class Triangle: public Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Default contructor.
     */
    Triangle();

    /**
     * Requires: Nothing.
     * Modifies: vertexOne, vertexTwo, vertexThree,
     *           vertexOneColor, vertexTwoColor, vertexThreeColor.
     * Effects:  Overloaded constructor. Sets three vertices and sets all three
     *           colors to one single color.
     */
    Triangle(Point pt1, Point pt2, Point pt3, Color color);

    /**
     * Requires: nothing
     * Modifies: vertexOne, vertexTwo, vertexThree,
     *           vertexOneColor, vertexTwoColor, vertexThreeColor.
     * Effects:  Overloaded constructor. Sets three vertices and three colors.
     */
    Triangle(Point pt1, Color color1,
             Point pt2, Color color2,
             Point pt3, Color color3);

    /**
     * Requires: Nothing.
     * Modifies: vertexOneColor, vertexTwoColor, vertexThreeColor.
     * Effects:  Sets all three colors of triangle.
     */
    void setColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: vertexOne.
     * Effects:  Sets vertex one of triangle.
     */
    void setVertexOne(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns vertex one of triangle.
     */
    Point getVertexOne();

    /**
     * Requires: Nothing.
     * Modifies: vertexOneColor.
     * Effects:  Sets color of vertex one of triangle.
     */
    void setVertexOneColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns color of vertex one of triangle.
     */
    Color getVertexOneColor();

    /**
     * Requires: Nothing.
     * Modifies: vertexTwo.
     * Effects:  Sets vertex two of triangle.
     */
    void setVertexTwo(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns vertex two of triangle.
     */
    Point getVertexTwo();

    /**
     * Requires: Nothing.
     * Modifies: vertexTwoColor.
     * Effects:  Sets color of vertex two of triangle.
     */
    void setVertexTwoColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns color of vertex two of triangle.
     */
    Color getVertexTwoColor();

    /**
     * Requires: Nothing.
     * Modifies: vertexThree.
     * Effects:  Sets vertex three of triangle.
     */
    void setVertexThree(Point pt);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns vertex three of triangle.
     */
    Point getVertexThree();

    /**
     * Requires: Nothing.
     * Modifies: vertexThreeColor.
     * Effects:  Sets color of vertex three of triangle.
     */
    void setVertexThreeColor(Color color);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns color of vertex three of triangle.
     */
    Color getVertexThreeColor();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, vertexOne, vertexTwo, vertexThree,
     *           vertexOneColor, vertexTwoColor, vertexThreeColor.
     * Effects:  Reads triangle in forms
     *           v1 v2 v3 color
     *           v1 v1Color v2 v2Color v3 v3Color
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes triangle in form
     *           v1 v1Color v2 v2Color v3 v3Color
     */
    void write(ostream& outs);

    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws triangle onto drawer.
     */
    void draw(Graphics& drawer);

private:
    Point vertexOne;
    Point vertexTwo;
    Point vertexThree;
    Color vertexOneColor;
    Color vertexTwoColor;
    Color vertexThreeColor;

    /**
     * Helper functions for drawing triangle.
     */
    int evalFunc(int x, int y, int a, int b, int c);
    float triArea(int xa, int ya, int xb, int yb, int xref, int yref);
    int checkRange(int val);
};

/**
 * Overloading >> and << for reading and writing Triangle to and from streams.
 */
istream& operator >> (istream& ins, Triangle& triangle);
ostream& operator << (ostream& outs, Triangle triangle);

#endif
