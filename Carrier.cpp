#include "Carrier.h"
#include<iostream>
#include<string>
using namespace std;



/*
Function Description:constructor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to Carrier, contains functions setHullpoint and sets it to 5 , and  setPlace() and sets it to false
*/

Carrier::Carrier()
{
    setName("Carrier");
    setHullpoint(5);
    setPlace(false);
}

/*
Function Description:detractor
Pre-Condition:takes no parameters
Post-condition: contains the function setName and sets it to " ", contains functions setHullpoint and sets it to -1 , and  setPlace() and sets it to false
*/
Carrier::~Carrier()
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
void Carrier::fireWeapons()
{
    cout << "Launching planes for air strike !" << endl;
}
