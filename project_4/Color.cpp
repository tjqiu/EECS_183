/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a file for all of the definition of Color class function.
 */

#include "Color.h"

// return a value which is within the range
int Color::checkRange(int val) {
    // within range
    if (val >= 0 && val < 255) {
        return val;
    }
    // out of range
    else {
        if (val < 0) {
            return 0;
        }
        else {
            return 255;
        }
    }
}

// default constructor
Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

// non-default constructor
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// set red value
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// get red value
int Color::getRed() {
    return red;
}

// set green value
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

// get green value
int Color::getGreen() {
    return green;
}

// set blue value
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// get blue value
int Color::getBlue() {
    return blue;
}

// read in the value for three colors
void Color::read(istream& ins) {
    int redVal;
    int greenVal;
    int blueVal;
    ins >> redVal >> greenVal >> blueVal;
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// write out three colors
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
}

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
