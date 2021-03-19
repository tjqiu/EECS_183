/**
 * Line.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Tianjie Qiu
 * tjqiu
 *
 * This is a file for all of the definition of Line class function
 */

#include "Line.h"
#include "Graphics.h"

// default constructor
Line::Line() {
}

// non-default constructor
Line::Line(Point pt1, Point pt2, Color color) {
    start = pt1;
    end = pt2;
    lineColor = color;
}

// set the start point
void Line::setStart(Point pt) {
    start = pt;
}

// get the start point
Point Line::getStart() {
    return start;
}

// set the end point
void Line::setEnd(Point pt) {
    end = pt;
}

// get the end point
Point Line::getEnd() {
    return end;
}

// set the color
void Line::setColor(Color color) {
    lineColor = color;
}

// get the color
Color Line::getColor() {
    return lineColor;
}

// read in the line information
void Line::read(istream& ins) {
    ins >> start;
    ins >> end;
    ins >> lineColor;
}

// write out the line information
void Line::write(ostream& outs) {
    outs << start;
    outs << end;
    outs << lineColor;
}

istream& operator >> (istream& ins, Line& line)
{
    line.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Line line)
{
    line.write(outs);
    return outs;
}

void Line::draw(Graphics &drawer)
{
    /**
     * This function is based on the Bresenham's line algorithm and is highly
     * optimized to be able to draw lines very quickly. There are no floating
     * point arithmetic, no multiplications, and no divisions involved.
     * Additionally, subtraction and bit shifting are used.
     * More info: http://en.wikipedia.org/wiki/Bresenham's_line_algorithm
     */
    int p1x = getStart().getX();
    int p1y = getStart().getY();
    int p2x = getEnd().getX();
    int p2y = getEnd().getY();

    int red = getColor().getRed();
    int blue = getColor().getBlue();
    int green = getColor().getGreen();

    int F, x, y;

    if (p1x > p2x)  // Swap points if p1 is on the right of p2
    {
        swap(p1x, p2x);
        swap(p1y, p2y);
    }

    // Handle trivial cases separately for algorithm speed up.
    // Trivial case 1: m = +/-INF (Vertical line)
    if (p1x == p2x)
    {
        if (p1y > p2y)  // Swap y-coordinates if p1 is above p2
        {
            swap(p1y, p2y);
        }

        x = p1x;
        y = p1y;
        while (y <= p2y)
        {
            drawer.setPixel(x, y, Color(red, green, blue));
            y++;
        }
        return;
    }
    // Trivial case 2: m = 0 (Horizontal line)
    else if (p1y == p2y)
    {
        x = p1x;
        y = p1y;

        while (x <= p2x)
        {
            drawer.setPixel(x, y, Color(red, green, blue));
            x++;
        }
        return;
    }


    int dy            = p2y - p1y;  // y-increment from p1 to p2
    int dx            = p2x - p1x;  // x-increment from p1 to p2
    int dy2           = (dy << 1);  // dy << 1 == 2*dy  i.e., bit shifting
    int dx2           = (dx << 1);
    int dy2_minus_dx2 = dy2 - dx2;  // precompute constant for speed up
    int dy2_plus_dx2  = dy2 + dx2;


    if (dy >= 0)    // m >= 0
    {
        // Case 1: 0 <= m <= 1 (Original case)
        if (dy <= dx)
        {
            F = dy2 - dx;    // initial F

            x = p1x;
            y = p1y;
            while (x <= p2x)
            {
                drawer.setPixel(x, y, Color(red, green, blue));
                if (F <= 0)
                {
                    F += dy2;
                }
                else
                {
                    y++;
                    F += dy2_minus_dx2;
                }
                x++;
            }
        }
        // Case 2: 1 < m < INF (Mirror about y=x line
        // replace all dy by dx and dx by dy)
        else
        {
            F = dx2 - dy;    // initial F

            y = p1y;
            x = p1x;
            while (y <= p2y)
            {
                drawer.setPixel(x, y, Color(red, green, blue));
                if (F <= 0)
                {
                    F += dx2;
                }
                else
                {
                    x++;
                    F -= dy2_minus_dx2;
                }
                y++;
            }
        }
    }
    else    // m < 0
    {
        // Case 3: -1 <= m < 0 (Mirror about x-axis, replace all dy by -dy)
        if (dx >= -dy)
        {
            F = -dy2 - dx;    // initial F

            x = p1x;
            y = p1y;
            while (x <= p2x)
            {
                drawer.setPixel(x, y, Color(red, green, blue));

                if (F <= 0)
                {
                    F -= dy2;
                }
                else
                {
                    y--;
                    F -= dy2_plus_dx2;
                }
                x++;
            }
        }
        // Case 4: -INF < m < -1 (Mirror about x-axis and mirror
        // about y=x line, replace all dx by -dy and dy by dx)
        else
        {
            F = dx2 + dy;    // initial F

            y = p1y;
            x = p1x;
            while (y >= p2y)
            {
                drawer.setPixel(x, y, Color(red, green, blue));

                if (F <= 0)
                {
                    F += dx2;
                }
                else
                {
                    x++;
                    F += dy2_plus_dx2;
                }
                y--;
            }
        }
    }
}
