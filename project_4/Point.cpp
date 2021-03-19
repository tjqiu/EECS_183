/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a file for all the definition of Point class function.
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// default constructor
Point::Point() {
    x = 0;
    y = 0;
}

// non-default constructor
Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

// set x coordinate
void Point::setX(int xVal) {
    x = checkRange(xVal);
}

// get x coordinate
int Point::getX() {
    return x;
}

// set y coordinate
void Point::setY(int yVal) {
    y = checkRange(yVal);
}

// get y coordinate
int Point::getY() {
    return y;
}

// read in points
void Point::read(istream& ins) {
    // noNum is used to store parentheses and commas in the form of (x,y)
    char noNum;
    int xVal;
    int yVal;
    ins >> noNum;
    ins >> xVal;
    x = checkRange(xVal);
    ins >> noNum;
    ins >> yVal;
    y = checkRange(yVal);
    ins >> noNum;
}

// write out point
void Point::write(ostream& outs) {
    outs << "(" << x << "," << y << ")";
}

// return a value which is within the range
int Point::checkRange(int val) {
    // within the range
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    // out of range
    else {
        if (val < 0) {
            return 0;
        }
        else {
            return DIMENSION - 1;
        }
    }
}

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
