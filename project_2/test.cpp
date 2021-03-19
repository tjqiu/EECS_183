/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Tianjie Qiu
 * tjqiu
 *
 * EECS 183: Project 2
 *
 * Testing functions for your birthdays.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

// main function
void startTests()
{
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
}

void test_getMenuChoice()
{
    // test good working case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    // test positive number that out of range
    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    // test negative numbers
    cout << "Please enter -1 then 2:";
    int choice3 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Test result: expected: \"Invalid menu choice\", then 2" << endl;
    cout << "Actual: " << choice3 << endl;
}

void test_isGregorianDate()
{
    cout << "Now testing function isGregorianDate()\n";
    // test good case
    cout << "9/2/2019:  Expected: 1, Actual: " << isGregorianDate(9, 2, 2019)
    << endl;
    // test bad year
    cout << "1/31/1001:  Expected: 0, Actual: " << isGregorianDate(1, 31, 1001)
    << endl;
    // test borderline case
    cout << "9/13/1752:  Expected: 0, Actual: " << isGregorianDate(9, 13, 1752)
    << endl;
    cout << "9/14/1752:  Expected: 1, Actual: " << isGregorianDate(9, 14, 1752)
    << endl;
}

void test_isLeapYear()
{
    cout << "Now testing function isLeapYear())\n";
    // test normal case
    cout << "1768:  Expected: 1, Actual: " << isLeapYear(1768) << endl;
    // test case divided evenly by 400
    cout << "2000:  Expected: 1, Actual: " << isLeapYear(2000) << endl;
    // test case divided evenly by 100 but not 400
    cout << "1800:  Expected: 0, Actual: " << isLeapYear(1800) << endl;
}

void test_isValidDate()
{
    cout << "Now testing function isValidDate())\n";
    // test good case
    cout << "9/27/2020:  Expected: 1, Actual: " << isValidDate(9, 27, 2020)
    << endl;
    // test bad month
    cout << "13/20/2000:  Expected: 0, Actual: " << isValidDate(13, 20, 2000)
    << endl;
    // test bad day for 31-day month
    cout << "1/32/2000:  Expected: 0, Actual: " << isValidDate(1, 32, 2000)
    << endl;
    // test bad day for 30-day month
    cout << "4/31/2000:  Expected: 0, Actual: " << isValidDate(4, 31, 2000)
    << endl;
    // test for bad year
    cout << "5/20/1300:  Expected: 0, Actual: " << isValidDate(5, 20, 1300)
    << endl;
    // test for 29-day Feb
    cout << "2/29/2020:  Expected: 1, Actual: " << isValidDate(2, 29, 2020)
    << endl;
    cout << "2/30/2020:  Expected: 0, Actual: " << isValidDate(2, 30, 2020)
    << endl;
    // test for 28-day Feb
    cout << "2/29/2019:  Expected: 0, Actual: " << isValidDate(2, 29, 2019)
    << endl;
    // test for 0 case
    cout << "2/0/2019:  Expected: 0, Actual: " << isValidDate(2, 0, 2019)
    << endl;
}

void test_determineDay()
{
    cout << "Now testing function determineDay())\n";
    // test for cases with different day
    cout << "9/27/2020:  Expected: 1, Actual: " << determineDay(9, 27, 2020)
    << endl;
    cout << "1/1/2020:  Expected: 4, Actual: " << determineDay(1, 1, 2020)
    << endl;
    cout << "2/1/2020:  Expected: 0, Actual: " << determineDay(2, 1, 2020)
    << endl;
    
}

void test_printDayOfBirth()
{
    cout << "Now testing function printDayOfBirth()\n";
    // test for Sunday
    cout << "1: Expected: Sunday, Actual: ";
    printDayOfBirth(1);
    cout << endl;

    // test for Saturday
    cout << "0: Expected: Saturday, Actual: ";
    printDayOfBirth(0);
    cout << endl;
}

void test_determineDayOfBirth()
{
    cout << "Now testing function determineDayofBirth()\n";
    // test for normal case
    cout << "Please enter 9/27/2020: , Expected : You were born on a:"
    << "Sunday\nHave a great birthday!!!\nActual: " << endl;
    determineDayOfBirth();
    // test for bad year
    cout << "Please enter 9/27/1000: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
    // test for bad day for 29-day Feb
    cout << "Please enter 2/30/2020: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
    // test for bad month
    cout << "Please enter 13/20/2000: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
    // test bad day for 31-day month
    cout << "Please enter 1/32/2000: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
    // test bad day for 28-day Feb
    cout << "Please enter 2/29/2019: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
    // test bad day for 30-day month
    cout << "Please enter 2/31/2000: , Expected : \"Invalid date\", Actual: "
    << endl;
    determineDayOfBirth();
}

void test_print10LeapYears()
{
    cout << "Now testing function print10LeapYears()\n";
    // test for one case
    cout << "Please enter 2020: , Expected : Leap year is 2024\nLeap year is"
    << "2028\nLeap year is 2032\nLeap year is 2036\nLeap year is 2040\nLeap"
    << "year is 2044\nLeap year is 2048\nLeap year is 2052\nLeap year is"
    << "2056\nLeap year is 2060\n=Leap year is 2064\n, Actual: " << endl;
    print10LeapYears();
    cout << "Please enter 1000: , Expected : \nActual: " << endl;
    print10LeapYears();
}
