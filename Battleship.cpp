#include "Battleship.h"
#include<iostream>
#include<string>
using namespace std;


/*
Function Description:constructor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to Battleship, contains functions setHullpoint and sets it to 4, and  setPlace() and sets it to false
*/

Battleship::Battleship()
{
    setName("Battleship");
    setHullpoint(4);
    setPlace(false);
}


/*
Function Description:detractor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to " ", contains functions setHullpoint and sets it to -1 , and  setPlace() and sets it to false
*/


Battleship::~Battleship()
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
void Battleship::fireWeapons()
{
    cout << "Firing 16inch guns! This is gonna be loud !" << endl;
}



