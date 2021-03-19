/**
 * focaccia.cpp
 *
 * Tianjie Qiu
 * tjqiu
 *
 * EECS 183: Project 1
 * Fall 2020
 * 
 * Project UID: 302fa9f14bd8266589c43c3129048565d11aa124
 *
 * Project Description: This program will ask how many people will attend the party and output one shopping list for focaccia bread accordingly
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//pluralrize choose to use singular or plural
string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}

//numLoaf counts the number of Focaccia
int numLoaf(int numPeople) {
    
    return ceil(static_cast<double>(numPeople) / 4);
}

//numFlourBag counts the number of bags of flour
int numFlourBag(int numFocaccia) {
    
    int numCup = 0;
    
    numCup = 5 * numFocaccia;
    
    return ceil(static_cast<double>(numCup) * 5 / 20 / 5);
}

//numYeastPackage counts the number of packages of yeast
int numYeastPackage(int numFocaccia) {
    
    double numYeastSpoon = 0;
    
    numYeastSpoon = 1.75 * numFocaccia;
    
    return ceil(numYeastSpoon / 2.25);
}

//numSaltCanister counts the number of canisters of salt
int numSaltCanister(int numFocaccia) {
    
    double numSaltTeaspoon = 0;
    
    numSaltTeaspoon = 1.875 * numFocaccia;
    
    return ceil(numSaltTeaspoon * 5 / 30);
}

//numOilBottle counts the number of bottles of oil
int numOilBottle(int numFocaccia) {
    
    int numOilTablespoon = 0;
    
    numOilTablespoon = 2 * numFocaccia;
    
    return ceil(numOilTablespoon * 14.8 / 500);
}

//numPrice connts the price of the shopping list
double numPrice(int numFlour, int numYeast, int numSalt, int numOil) {
    
    const double FLOUR_PRICE = 2.69;
    const double YEAST_PRICE = 0.4;
    const double SALT_PRICE = 0.49;
    const double OIL_PRICE = 6.39;
    
    return FLOUR_PRICE * numFlour + YEAST_PRICE * numYeast + SALT_PRICE * numSalt + OIL_PRICE * numOil;
}

//toPrint prints the final shopping list
void toPrint(int numOfFocaccia, int numOfFlour, int numOfYeast, int numOfSalt, int numOfOil, double totalPrice) {
    
    cout << "You need to make: " << numOfFocaccia <<" " << pluralize("loaf","loaves",numOfFocaccia) <<" of focaccia" <<endl <<endl;
    cout << "Shopping List for Focaccia Bread" <<endl << "--------------------------------" <<endl;
    cout << numOfFlour << " " << pluralize("bag","bags",numOfFlour) << " of flour" <<endl;
    cout << numOfYeast << " " << pluralize("package","packages",numOfYeast) << " of yeast" <<endl;
    cout << numOfSalt << " " << pluralize("canister","canisters",numOfSalt) << " of salt" <<endl;
    cout << numOfOil << " " << pluralize("bottle","bottles",numOfOil) << " of olive oil" <<endl <<endl;
    cout<<"Total expected cost of ingredients: $" <<totalPrice <<endl <<endl <<"Have a great socially-distanced party!" <<endl;
}

int main() {
    
    int people;
    int numFocaccia = 0;
    int numFlour = 0;
    int numYeast = 0;
    int numSalt = 0;
    int numOil = 0;
    double Price = 0;
    
    //prompt to get the number of people
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    numFocaccia = numLoaf(people);
    numFlour = numFlourBag(numFocaccia);
    numYeast = numYeastPackage(numFocaccia);
    numSalt = numSaltCanister(numFocaccia);
    numOil = numOilBottle(numFocaccia);
    Price = numPrice(numFlour, numYeast, numSalt, numOil);
    //print the final shopping list
    toPrint(numFocaccia, numFlour, numYeast, numSalt, numOil, Price);

    return 0;
}
