/**
 * start.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183, Fall 2020
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include <iostream>
#include <string>

using namespace std;

//********************************************************
// Function declarations. 
// Function definitions are in pics.cpp and test.cpp
//********************************************************
void coolPics();
void startTests();

int main() {
    
    cout << "-------------------------------" << endl
         << "EECS 183 Project 4 Menu Options" << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute coolPics() function to make pics" << endl;    
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1) {
        startTests();
    }
    else if (choice == 2) {
        coolPics();
    }
    
    return 0;
}
