/**
 * Color.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a color in RGB mode.
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

class Color
{
public:
    /**
     * Requires: Nothing.
     * Modifies: red, green, blue.
     * Effects:  Default contructor. Sets color to black (0,0,0).
     */
    Color();

    /**
     * Requires: Nothing.
     * Modifies: red, green, blue.
     * Effects:  Constructor that sets RGB values. If values are ouside of
     *           [0,255], assigns to the closest of 0 and 255.
     * NOTE: you should implement the 'private' member funtion
     *     checkRange() before you implement this function
     */
    Color(int redVal, int greenVal, int blueVal);

    /**
     * Requires: Nothing.
     * Modifies: red.
     * Effects:  Sets red value. If redVal is ouside of [0,255],
     *           assigns to the closest of 0 and 255.
     */
    void setRed(int redVal);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns red value.
     */
    int getRed();

    /**
     * Requires: Nothing.
     * Modifies: green.
     * Effects:  Sets green value. If greenVal is ouside of [0,255],
     *           assigns to the closest of 0 and 255.
     */
    void setGreen(int greenVal);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns green value.
     */
    int getGreen();

    /**
     * Requires: Nothing.
     * Modifies: blue.
     * Effects:  Sets blue value. If blueVal is ouside of [0,255],
     *           assigns to the closest of 0 and 255.
     */
    void setBlue(int blueVal);

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns blue value.
     */
    int getBlue();

    /**
     * Requires: ins is in good state.
     * Modifies: ins, red, green, blue.
     * Effects:  Reads color in form red green blue.
     *     format of a color is:  red  green  blue
     *     Example:  100  255  125
     */
    void read(istream& ins);

    /**
     * Requires: outs is in good state.
     * Modifies: outs.
     * Effects:  Writes color in form red  green  blue
     * Example:  100  255  125
     */
    void write(ostream& outs);

private:
    int red;
    int green;
    int blue;

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns val if val is in range [0,255],
     *           otherwise returns the closest of 0 and 255.
     */
    int checkRange(int val);

};

/**
 * Overloading >> and << for reading and writing Color to and from streams.
 */
istream& operator >> (istream& ins, Color& color);
ostream& operator << (ostream& outs, Color color);

#endif
