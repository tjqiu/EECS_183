/**
 * Shape.h
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Base class for all shapes.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include "Graphics.h"

class Shape
{
public:
    /**
     * Requires: Nothing.
     * Modifies: drawer.
     * Effects:  Draws the shape.
     */
	virtual void draw(Graphics &drawer);
};

#endif
