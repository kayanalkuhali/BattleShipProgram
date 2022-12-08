#include "Submarine.h"
#include<iostream>
#include<string>
using namespace std;



/*
Function Description:constructor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to Submarine, contains functions setHullpoint and sets it to 3, and  setPlace() and sets it to false
*/


Submarine::Submarine()
{
    setName("Submarine");
    setHullpoint(3);
    setPlace(false);
}

/*
Function Description:detractor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to " ", contains functions setHullpoint and sets it to -1 , and  setPlace() and sets it to false
*/
Submarine::~Submarine()
{
    setName(" ");
    setHullpoint(-1);
    setPlace(false);
}

/*
Function Description: void function
Pre-Condition:takes no parameters
Post-condition: outputs a message
*/
void Submarine::fireWeapons()
{
    cout << "Bearing, set , match :Firing torpedos !" << endl;
}




