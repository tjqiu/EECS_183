/**
 * birthdays.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Tianjie Qiu
 * tjqiu
 *
 * EECS 183: Project 2： Birthdays
 *
 * The project Birthdays will have two functions, one is take a date and determine the day of birth,
 * another one is take a year and output the next 10 leap years.
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 */
void print10LeapYears();

// This is the mian function
void birthdays() {
    int choice;
    printHeading();
    choice = getMenuChoice();
    // Determine which choice the user choose and start the certain choice.
    while (choice != 3) {
        // choice 1 goes to determine day of birth
        if (choice == 1) {
            determineDayOfBirth();
            choice = getMenuChoice();
        }
        // choice 2 goes to print next 10 leap years
        else if (choice == 2) {
            print10LeapYears();
            choice = getMenuChoice();
        }
    }
    // choice 3 will finish the program
    if (choice == 3) {
        printCloser();
    }
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}


void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    printMenu();
    int choice;
    // dtermine the case when a choice is invalid
    while (!(cin >> choice && (choice == 1 || choice == 2 || choice == 3))){
        cout << endl <<"Invalid menu choice";
        printMenu();
    }
    return choice;
}

bool isGregorianDate(int month, int day, int year) {
    // rule out cases when year is not Gregorian date, 1752 is the borderline
    if (year < 1752) {
        return false;
    }
    // rule out the case when year is 1752 and month and date not satisfy
    // Gregorian date
    else if (year == 1752) {
        return (month > 9 || (month == 9 && day > 13));
    }
    else {
        return true;
    }
}

bool isLeapYear(int year) {
    // if a year can be evenly divided by 400, it is a leap year
    if (year % 400 == 0) {
        return true;
    }
    // rule out case when year can be divided by 100
    else if (year % 100 == 0) {
        return false;
    }
    // after ruling out certain case, a year is a leap year if it can be
    // divided by 4
    else return (year % 4 == 0);
}


bool isValidDate(int month, int day, int year) {
    // a non-Gegorian date is invalid
    if (!isGregorianDate(month, day, year)) {
        return false;
    }
    // when month is not right, invalid
    else if (month > 12) {
        return false;
    }
    // for certain month, they have 31 days
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
             || month == 10 || month == 12) {
        return (day >= 1 && day <= 31);
    }
    // for certain month, they have 30 days
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return (day >= 1 && day <=30);
    }
    // Feb has 29 days if leap year, 28 days if not leap year
    else if (month == 2) {
        if (isLeapYear(year)) {
            return (day >= 1 && day <= 29);
        }
        else return (day >= 1 && day <= 28);
    }
    else {
        return false;
    }
}


int determineDay(int month, int day, int year) {
    // In Zeller's formula, Jan is conidered as the 13th month of the last year
    if (month == 1) {
        month = 13;
        year -= 1;
    }
    // In Zeller's formula, Feb is considered as the 14th month of last year
    else if (month == 2) {
        month = 14;
        year -= 1;
    }
    // get the last two digits of the year number
    int numYear = year % 100;
    // get the century number
    int numCentury = (year - numYear) / 100;
    // use Zeller's formula to get a number for the day
    int numDay = (int)(day + floor(13 * ((double)month + 1) / 5) + numYear +
                       floor((double)numYear / 4) +
                       floor((double)numCentury / 4) + 5 * numCentury) % 7;
    return numDay;
}


void printDayOfBirth(int day) {
    // convert the number obtained from Zeller's formula to actual days
    if (day == 0) {
        cout << "Saturday" << endl;
    }
    else if (day == 1) {
        cout << "Sunday" << endl;
    }
    else if (day == 2) {
        cout << "Monday" << endl;
    }
    else if (day == 3) {
        cout << "Tuesday" << endl;
    }
    else if (day == 4) {
        cout << "Wednesday" << endl;
    }
    else if (day == 5) {
        cout << "Thursday" << endl;
    }
    else if (day == 6) {
        cout << "Friday" << endl;
    }
}


void determineDayOfBirth() {
    int month;
    char slash;
    int day;
    int year;
    
    // prompt for the date of birth
    cout << endl << "Enter your date of birth" << endl;
    cout << "format: month / day / year  --> " << endl;
    cin >> month;
    // read the slash to get the number after it
    cin >> slash;
    cin >> day;
    cin >> slash;
    cin >> year;
    
    // check if it is a valid date
    if (!isValidDate(month, day, year)) {
        cout << "Invalid date" << endl;
    }
    else {
        // print out the result of the day
        cout << "You were born on a: ";
        printDayOfBirth(determineDay(month, day, year));
        cout << endl << "Have a great birthday!!!" << endl;
    }
}

void print10LeapYears() {
    int year;
    int count = 0;
    // prompt for the year
    cout << endl << "Enter year --> " << endl;
    cin >> year;
    // check whether a year is valid
    if (year >= 1752) {
        // determine whether 10 times leap year print has reached
        while (count < 10){
            if (isLeapYear(year + 1)) {
                cout << "Leap year is " << year + 1 << endl;
                // if a leap year is printed, add one to the count to store the
                // number of leap year printed
                ++count;
                ++year;
            }
            else {
                ++year;
            }
        }
    }
    return;
}
