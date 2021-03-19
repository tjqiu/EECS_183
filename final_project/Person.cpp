#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string input_string) : Person() {
    //TODO: Implement non-default constructor
    stringstream ss(input_string);
    char x;
    ss >> turn >> x >> currentFloor >> x >> targetFloor >> x >> angerLevel;
    
}

bool Person::tick(int currentTime) {
    //TODO: Implement tick
    bool ifAnger = false;
    if (currentTime % TICKS_PER_ANGER_INCREASE == 0) {
        ++angerLevel;
        if (angerLevel == MAX_ANGER) {
            ifAnger = true;
        }
        else {
            ifAnger = false;
        }
    }

    //Returning false to prevent compilation error
    return ifAnger;
}

void Person::print(ostream &outs) {    
    //TODO: Implement print
    outs << 'f' << currentFloor << 't' << targetFloor << 'a' << angerLevel;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person() {
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const {
    return turn;
}

int Person::getCurrentFloor() const {    
    return currentFloor;
}

int Person::getTargetFloor() const {    
    return targetFloor;
}

int Person::getAngerLevel() const {    
    return angerLevel;
}

ostream& operator<< (ostream& outs, Person p)
{
    p.print(outs);
    return outs;
}
