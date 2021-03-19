#include "Floor.h"
#include <sstream>

using namespace std;

int Floor::tick(int currentTime) {
    //TODO: Implement tick
    int numExplode = 0;
    string explodeIndice = "";
    for (int i = 0; i < numPeople; ++i) {
        bool ifExplode = false;
        ifExplode = people[i].tick(currentTime);
        if (ifExplode) {
            stringstream ss;
            ++numExplode;
            string str;
            ss << i;
            ss >> str;
            explodeIndice += str;
            explodeIndice += 'x';
        }
    }
    int remove[numExplode];
    stringstream ss(explodeIndice);
    int oneIndice;
    char split;
    for (int i = 0; i < numExplode; ++i) {
        ss >> oneIndice;
        remove[i] = oneIndice;
        ss >> split;
    }
    removePeople(remove, numExplode);
    //returning 0 to prevent compilation error
    return numExplode;
}

void Floor::addPerson(Person p, int request) {
    //TODO: Implement addPerson
    if (numPeople < MAX_PEOPLE_PER_FLOOR) {
        people[numPeople] = p;
        ++numPeople;
    if (request > 0) {
        hasUpRequest = true;
    }
    else if (request < 0) {
        hasDownRequest = true;
    }
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    //TODO: Implement removePeople
    /*Person p;
     for (int i = 0; i < numPeopleToRemove; ++i) {
     people[indicesToRemove[i]] = p;
     for (int j = indicesToRemove[i] + 1; j < MAX_PEOPLE_PER_FLOOR; ++j) {
     people[j - 1] = people[j];
     }
     for (int k = 0; k < numPeopleToRemove; ++k) {
     if (indicesToRemove[k] >= indicesToRemove[i]) {
     indicesToRemove[k] -= 1;
     }
     }
     }
     numPeople -= numPeopleToRemove;
     for (int i = numPeople; i < MAX_PEOPLE_PER_FLOOR; ++i) {
     people[i] = p;
     }
     resetRequests();*/
    bool b[MAX_PEOPLE_PER_FLOOR];
    Person p[MAX_PEOPLE_PER_FLOOR];
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i) {
        b[i] = true;
    }
    int place = 0;
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i) {
        for (int j = 0; j < numPeopleToRemove; ++j) {
            if (indicesToRemove[j] == i) {
                b[i] = false;
            }
        }
    }
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i) {
        if (b[i]) {
            p[place] = people[i];
            ++place;
        }
    }
    for (int i = 0; i < MAX_PEOPLE_PER_FLOOR; ++i) {
        people[i] = p[i];
    }
    numPeople -= numPeopleToRemove;
    resetRequests();
    
}

void Floor::resetRequests() {
    //TODO: Implement resetRequests
    hasUpRequest = false;
    hasDownRequest = false;
    for (int i = 0; i < numPeople; ++i) {
        if (people[i].getTargetFloor() - people[i].getCurrentFloor() > 0) {
            hasUpRequest = true;
        }
        if (people[i].getTargetFloor() - people[i].getCurrentFloor() < 0) {
            hasDownRequest = true;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
    string up = "U";
    outs << (hasUpRequest ? up : " ") << " ";
    for (int i = 0; i < numPeople; ++i){
        outs << people[i].getAngerLevel();
        outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
    }
    outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
    string down = "D";
    outs << (hasDownRequest ? down : " ") << " ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "o   ";
    }
    outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
    cout << endl;
    outs << "Select People to Load by Index" << endl;
    outs << "All people must be going in same direction!";
    /*  O   O
    // -|- -|-
    //  |   |
    // / \ / \  */
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " O   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "-|-  ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " |   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "/ \\  ";
    }
    outs << endl << "INDEX:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << i << "   ";
    }
    outs << endl << "ANGER:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getAngerLevel() << "   ";
    }
    outs << endl << "TARGET FLOOR: ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getTargetFloor() << "   ";
    }
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
    return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
    return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
