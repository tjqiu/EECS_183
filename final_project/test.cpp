#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Building.h"
#include "Elevator.h"
#include "Floor.h"
#include "Move.h"
#include "Person.h"

using namespace std;

// write your test functions here
void test();

int main() {
    test();
    // call your test functions here
}

void test() {
    int remove[] = {3,7,5,9,1};
    int num = 5;
    Person p1("7f4t8a3");
    Person p2("7f4t6a4");
    Person p3("7f4t7a2");
    Person p4("7f4t5a1");
    Person p5("7f4t9a5");
    Person p6("7f4t1a6");
    Person p7("7f4t2a7");
    Person p8("7f4t3a8");
    Person p9("7f4t10a9");
    Person p10("7f4t5a0");
    Floor f1;
    f1.addPerson(p1, 1);
    f1.addPerson(p2, 1);
    f1.addPerson(p3, 1);
    f1.addPerson(p4, 1);
    f1.addPerson(p5, 1);
    f1.addPerson(p6, -1);
    f1.addPerson(p7, -1);
    f1.addPerson(p8, -1);
    f1.addPerson(p9, 1);
    f1.addPerson(p10, 1);
    f1.removePeople(remove, num);
}
