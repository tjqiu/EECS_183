/**
 * Graphics.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Represents a 100 x 100 image.
 */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
using namespace std;

#include "Color.h"
#include "utility.h"

class Graphics
{
public:

    /**
     * Requires: Nothing.
     * Modifies: pixelData.
     * Effects:  Default constructor. Sets all pixels to black.
     */
    Graphics();

    /**
     * Requires: Nothing.
     * Modifies: pixelData.
     * Effects:  Sets all pixels to black.
     * Note: you will want to implement the private
     *  member function initArray before implementing
     *  clear()
     */
    void clear();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Writes the BMP file to filename.
     */
    void writeFile(string fileName) const;

    /**
     * Requires: color is a valid Color
     * Modifies: pixelData.
     * Effects:  Sets the pixel at (x, y) to color
     *      if it is within the bounds.
     *      See the specification for how pixels are stored.
     */
    void setPixel(int x, int y, Color color);

private:
    /**
     * Requires: Nothing.
     * Modifies: pixelData.
     * Effects:  Initializes all pixels in pixelData to black.
     */
    void initArray();

    // Holds the color in the pixels
    Color pixelData[DIMENSION][DIMENSION];
};

#endif
