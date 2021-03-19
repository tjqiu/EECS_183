/**
 * Point.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a coordinate point in an image.
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;


class Point
{
public:
    /**
     * Requires: Nothing.
     * Modifies: x, y.
     * Effects:  Default contructor. Sets point to origin (0,0).
     */
    Point();

    /**
     * Requires: Nothing.
     * Modifies: x, y.
     * Effects:  Constructs a point and sets x and y coordinates.
     * Note: you will want to implement the private
     *    member function checkRange() before
     *    implementing this one
     */
    Point(int xVal, int yVal);

    /**
     * Requires: Nothing.
     * Modifies: x.
     * Effects:  Sets x coordinate.
     */
    void setX(int xVal);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns x coordinate.
     */
    int getX();

    /**
     * Requires: Nothing.
     * Modifies: y.
     * Effects:  Sets y coordinate.
     */
    void setY(int yVal);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns y coordinate.
     */
    int getY();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, x, y.
     * Effects:  Reads point in form (x,y).
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes point in form (x,y).
     */
    void write(ostream& outs);

private:
    int x;
    int y;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects:
     * Effects:  Returns val if val is in range [0,DIMENSION),
     *           otherwise returns the closest of 0 and DIMENSION - 1.
     */
    int checkRange(int val);

};

/**
 * Overloading >> and << for reading a Point from streams.
 * Example on how to use these:
 * Point pt;
 * cout << "Please enter a point using format (x,y) : ";
 * cin >> pt;
 * cout << "\nthe point you just entered is: ";
 * cout << pt << endl;
 */
istream& operator >> (istream& ins, Point& pt);
ostream& operator << (ostream& outs, Point pt);

#endif
