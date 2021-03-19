/**
 * Rectangle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a file for all the definition of Rectangle class function
 */

#include "Rectangle.h"
#include "Line.h"
#include "Triangle.h"
#include "Graphics.h"
#include <algorithm>
using namespace std;

// default constructor
Rectangle::Rectangle() {
}

// non-default contructor with one color
Rectangle::Rectangle(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// non-default constructor with three color
Rectangle::Rectangle(Point pt1, Point pt2, Color cTopLeft,
                     Color cTopRight, Color cBottomRight, Color cBottomLeft) {
    start = pt1;
    end = pt2;
    colorTopLeft = cTopLeft;
    colorTopRight = cTopRight;
    colorBottomRight = cBottomRight;
    colorBottomLeft = cBottomLeft;
}

// set the start point
void Rectangle::setStart(Point pt) {
    start = pt;
}

// return start point
Point Rectangle::getStart() {
    return start;
}

// set the end point
void Rectangle::setEnd(Point pt) {
    end = pt;
}

// get end point
Point Rectangle::getEnd() {
    return end;
}

// set four colors to one color
void Rectangle::setColor(Color color) {
    colorTopLeft = color;
    colorTopRight = color;
    colorBottomRight = color;
    colorBottomLeft = color;
}

// Sets top left color
void Rectangle::setColorTopLeft(Color color) {
    colorTopLeft = color;
}

// Returns top left color
Color Rectangle::getColorTopLeft() {
    return colorTopLeft;
}

// Sets top right color
void Rectangle::setColorTopRight(Color color) {
    colorTopRight = color;
}

// Returns top right color
Color Rectangle::getColorTopRight() {
    return colorTopRight;
}

// Sets bottom rihgt color
void Rectangle::setColorBottomRight(Color color) {
    colorBottomRight = color;
}

// Returns bottom right color
Color Rectangle::getColorBottomRight() {
    return colorBottomRight;
}

// Sets bottom left color
void Rectangle::setColorBottomLeft(Color color) {
    colorBottomLeft = color;
}

// Returns bottom left color
Color Rectangle::getColorBottomLeft() {
    return colorBottomLeft;
}

// read in rectangle information in two forms
void Rectangle::read(istream& ins) {
    ins >> start >> end >> colorTopLeft;
    // judge which form is read in
    if (ins >> colorTopRight) {
        ins >> colorBottomRight >> colorBottomLeft;
    }
    else {
        ins.clear();
        colorTopRight = colorTopLeft;
        colorBottomRight = colorTopLeft;
        colorBottomLeft = colorTopLeft;
    }
}

// write out rectangle information
void Rectangle::write(ostream& outs) {
    outs << start << end << colorTopLeft << colorTopRight
    << colorBottomRight << colorBottomLeft;
}

istream& operator >> (istream& ins, Rectangle& rectangle)
{
    rectangle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Rectangle rectangle)
{
    rectangle.write(outs);
    return outs;
}

void Rectangle::draw(Graphics & drawer)
{
    // four points of rectangles
    Point topLeft = start;
    Point topRight(end.getX(), start.getY());
    Point bottomRight = end;
    Point bottomLeft(start.getX(), end.getY());

    // center point and color by averaging
    Point center((start.getX() + end.getX()) / 2,
                 (start.getY() + end.getY()) / 2);
    Color colorCenter((colorTopLeft.getRed() + colorTopRight.getRed() +
                       colorBottomRight.getRed() +
                       colorBottomLeft.getRed()) / 4,
                      (colorTopLeft.getGreen() + colorTopRight.getGreen() +
                       colorBottomRight.getGreen() +
                       colorBottomLeft.getGreen()) / 4,
                      (colorTopLeft.getBlue() + colorTopRight.getBlue() +
                       colorBottomRight.getBlue() +
                       colorBottomLeft.getBlue()) / 4);

    // four triangles to represent rectangle
    Triangle top(topLeft, colorTopLeft, topRight, colorTopRight,
                 center, colorCenter);
    Triangle bottom(bottomLeft, colorBottomLeft, bottomRight, colorBottomRight,
                    center, colorCenter);
    Triangle left(topLeft, colorTopLeft, bottomLeft, colorBottomLeft,
                  center, colorCenter);
    Triangle right(topRight, colorTopRight, bottomRight, colorBottomRight,
                   center, colorCenter);
    top.draw(drawer);
    bottom.draw(drawer);
    left.draw(drawer);
    right.draw(drawer);
}
