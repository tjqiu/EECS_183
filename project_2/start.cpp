/**
 * start.cpp
 * Project UID d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 *
 * EECS 183: Project 2
 *
 * main() function for Project 2 Birthdays
 * selects between executing your test cases
 * and the birthdays application.
 * 
 * You do not need to make any changes to this file or
 * submit it to the autograder.
 */

#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Function declarations. Function definitions are in birthdays.cpp and test.cpp
//************************************************************************
void birthdays();
void startTests();

int main()
{

    cout << "-------------------------------" << endl
         << "EECS 183 Project 2 Menu Options" << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute birthdays() function in birthdays.cpp" << endl;
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    if (choice == 1)
    {
        startTests();
    }
    else if (choice == 2)
    {
        birthdays();
    }

    return 0;
}
