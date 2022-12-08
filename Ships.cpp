#include "Ships.h"


/*
Function Description:parameterized constructor
Pre-Condition:takes in a string , int , and bool
Post-condition:sets the variables equal to the appropriate private variables
*/


Ships::Ships(string n, int hp, bool p)
{
    name = n;
    hullPoints = hp;
    placed = p;
}

/*
Function Description:destructor
Pre-Condition:takes no parameters
Post-condition: returns nothing
*/


Ships::~Ships()
{

}




/*
Function Description:parameterized mutator
Pre-Condition:contains a string
Post-condition:sets the string equal to the private variable name
*/
void Ships::setName(string n)
{
    name = n;

}


/*
Function Description:parameterized mutator
Pre-Condition:contains a int
Post-condition:sets the int equal to the private variable hullPoints
*/
void Ships::setHullpoint(int hp)
{
    hullPoints = hp;
}


/*
Function Description:parameterized mutator
Pre-Condition:contains a bool
Post-condition:sets the bool equal to the private variable placed
*/


void Ships::setPlace(bool p)
{
    placed = p;
}


/*
Function Description: accessors
Pre-Condition:contains no parameters
Post-condition:returns name
*/
const string Ships::getName()
{
    return name;
}

/*
Function Description: accessors
Pre-Condition:contains no parameters
Post-condition:returns hullpoints
*/

const int Ships::getHullpoint()
{
    return hullPoints;
}



/*
Function Description: void function
Pre-Condition:contains no parameters
Post-condition:decrements hull point by one
*/
void Ships::hit()
{
    hullPoints = hullPoints - 1;

}

/*
Function Description: accessors
Pre-Condition:contains no parameters
Post-condition:returns placed
*/
const bool Ships::getPlace()
{
    return placed;
}
