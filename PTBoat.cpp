#include "PTBoat.h"



#include<iostream>
#include<string>
using namespace std;


/*
Function Description:constructor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to PTBoat, contains functions setHullpoint and sets it to 2, and  setPlace() and sets it to false
*/
PTBoat::PTBoat()
{
    setName("PTBoat");
    setHullpoint(2);
    setPlace(false);
}

/*
Function Description:detractor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to " ", contains functions setHullpoint and sets it to -1 , and  setPlace() and sets it to false
*/

PTBoat::~PTBoat()
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
void PTBoat::fireWeapons()
{
    cout << "Full Speed Ahead! Firing torpedos! " << endl;
}
