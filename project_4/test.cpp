/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * Tianjie Qiu
 * tjqiu
 *
 * Contains functions for testing classes in the project. 
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Graphics();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Line();
    test_Circle();
    test_Color();
    test_Rectangle();
    test_Triangle();
    // call other test functions here
    
    return;
}

void test_Point() {
        // test of default constructor
    Point p1;
    cout << p1 << endl;
    
    // test of the non-default constructor
    Point p2(3, 9);
    cout << p2 << endl;

    // test of member function: setX()
    p1.setX(5);
    // test of member function: setY()
    p1.setY(3);

    // test of member functions getX() and getY()
    cout << "( " << p1.getX()
         << ", " << p1.getY()
         << " )" << endl;
    
    // you can also do cin >> p1;
    p1.read(cin);
    cout << p1 << endl;
    
    return;
}

void test_Line() {
    Line line1;
    cout << line1 << endl;
    Point start1(1,2);
    Point end1(96,99);
    Color color1(1,2,255);
    Line line2(start1,end1,color1);
    cout << line2 << endl;
    cout << line2.getStart() << endl;
    Point point1(1,3);
    line2.setEnd(point1);
    cout << line2 <<endl;
    line2.write(cout);
}

void test_Circle() {
    Circle circle1;
    cout << circle1;
    Point pt(3,3);
    int r = -9;
    Color c(27,27,27);
    Circle circle2(pt,r,c);
    cout << circle2;
    Point pt2(9,9);
    circle2.setCenter(pt2);
    cout << circle2;
    int r2 = -3;
    circle2.setRadius(r2);
    cout << circle2;
}

void test_Color() {
    int r = 3;
    int g = 9;
    int b = 13;
    Color c(r,g,b);
    cout << c.getBlue();
    cout << c.getGreen();
    int b2 = 338;
    c.setBlue(b2);
    cout << c;
}

void test_Rectangle() {
    Rectangle r0;
    cout << r0;
    Point pt1(3,3);
    Point pt2(9,9);
    Color c1(3,9,13);
    Rectangle r1(pt1,pt2,c1);
    cout << r1;
    Color c2(2,3,5);
    Color c3(34,54,2);
    Color c4(32,5,77);
    Rectangle r2(pt1,pt2,c1,c2,c3,c4);
    cout << r2;
    cout << r2.getEnd();
    Color c5(3,3,3);
    r2.setColor(c5);
    cout << r1;
    Point pt3(45,23);
    r2.setStart(pt3);
    cout << r2;
}

void test_Triangle() {
    Triangle t1;
    cout << t1;
    Point pt1(3,3);
    Point pt2(9,9);
    Point pt3(13,13);
    Color c1(3,9,13);
    Triangle t2(pt1,pt2,pt3,c1);
    cout << t2;
    Color c2(2,3,5);
    Color c3(34,54,2);
    Triangle t3(pt1,c1,pt2,c2,pt3,c3);
    cout << t3;
    cout << t3.getVertexOne();
    cout << t3.getVertexTwo();
    cout << t3.getVertexThree();
    cout << t3.getVertexOneColor();
    cout << t3.getVertexTwoColor();
    cout << t3.getVertexThreeColor();
    Point pt4(35,33);
    Point pt5(92,39);
    Point pt6(53,73);
    t3.setVertexOne(pt4);
    cout << t3;
    t3.setVertexTwo(pt5);
    cout << t3;
    t3.setVertexThree(pt6);
    cout << t3;
    t3.write(cout);
}
