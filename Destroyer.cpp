#include "Destroyer.h"

#include<iostream>
#include<string>
using namespace std;


/*
Function Description:constructor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to Destroyer, contains functions setHullpoint and sets it to 3, and  setPlace() and sets it to false
*/
Destroyer::Destroyer()
{
    setName("Destroyer");
    setHullpoint(3);
    setPlace(false);
}


/*
Function Description:detractor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to " ", contains functions setHullpoint and sets it to -1 , and  setPlace() and sets it to false
*/

Destroyer::~Destroyer()
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

void Destroyer::fireWeapons()
{
    cout << "Launching depthcharges! Boom goes the dynamite!" << endl;
}


