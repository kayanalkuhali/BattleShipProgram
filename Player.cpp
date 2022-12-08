#include "Player.h"
#include "PTBoat.h"
#include "Submarine.h"
#include "Destroyer.h"
#include <iostream>
#include "Carrier.h"
#include "Battleship.h"
#include "Types.h"
#include "Ships.h"



using namespace std;


/*
Function Description:Parameterized constructor for name
Pre-Condition:sets the string name to n.
Post-condition: initializes score to zero and sets each position in the array to ' '


*/
Player::Player(string n)
{

    name = n;
    score = 0;
    ships = 0;
    tacNuke = true;


    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)

        {
            enemy[row][column] = ' ';
            fleet[row][column] = '  ';

        }


        cout << "     ";

    }



}


/*
Function Description:mutator for ship
Pre-Condition:takes no parameters
Post-condition: decrements ship by 1

*/
void Player::setShip()
{
    ships = ships - 1;
}



/*
Function Description: gets called at the end of the program
Pre-Condition: contains name , score , fleet array and enemy array
Post-condition: initializes score to -1 and sets each position in the fleet and enemy array to ' ' and initializes name to " "


*/


Player::~Player()
{
    name = "  ";
    score = -1;
    ships = -1;
    tacNuke = false;

    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)

        {
            enemy[row][column] = ' ';
        }
    }


    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)

        {
            fleet[row][column] = '  ';
        }
    }


}




/*
Function Description: Accessor method which returns enemy ptr
Pre-Condition: returns a reference to ptr.
Post-condition: sets enemy ptr to the reference

*/


ptr_to_array Player::getenemy()
{

    ptr_to_array ptr;
    return  enemy;

    //return ptr;
}


/*
Function Description: Accessor method which returns fleet ptr
Pre-Condition: returns a reference to ptr.
Post-condition: sets fleet ptr to the reference

*/

ptr_to_array Player::getfleet()
{

    ptr_to_array ptr;
    return fleet;

}



/*
Function Description: Parameterized accessor that contains two integer values
Pre-Condition: takes in two integers
Post-condition: returns a character

*/

char Player::getLocationStatus(int row, int  column)
{

    return fleet[row][column];

}


/*
Function Description: Parameterized function  that contains a character array
Pre-Condition: takes in a char 2D-array of size [10][10
Post-condition: prints board chart and name and score with player along with hull points of each ship

*/


void Player::printBoard(char Board[10][10])


{

    cout << "Player's Name: " << name << " Score: " << score << endl;


    cout << "   A    B   C    D    E    F    G    H    I    J  " << endl << endl;

    for (int i = 0; i < 10; i++)  //column loop
    {
        cout << "---------------------------------------------------" << endl;
        for (int j = 0; j < 10; j++)  //row loop
        {

            if (j == 0)
            {
                cout << i << "|"; //print row number and spaces before new row
            }
            if (Board[i][j] != ' ')  //if the space is a hit, print it
            {
                cout << Board[i][j];
            }

            else
            {
                cout << "  ";  //otherwise, just print a 0
            }


            cout << " | ";


        }

        cout << endl; //new line at end of column
    }
    cout << "---------------------------------------------------" << endl << endl << endl;



    cout << name << " ship status:   " << "CV: " << carrier_ship.getHullpoint() << "    BB: " << battle_ship.getHullpoint() << "    DD :" << destroyer_ship.getHullpoint() << endl;

    cout << "                     SUB: " << submarine_ship.getHullpoint() << "            PT: " << patrol_ship.getHullpoint() << endl;



}



/*
Function Description:  Parameterized function that contains two integer values that represent array placement and an int value for the size of a ship and a char that contains the directions of the ship placement
Pre-Condition: takes the ship size and location the user wants to place them along with the direction
Post-condition: makes sure that the space desired is empty and

*/



bool Player::checkEmpty(int size1/*hullpt*/, int x, int y, char direction)
{




    if (direction == 'V')


    {

        for (int i = 0; i < size1; i++)

        {



            if (fleet[x + i][y] == ' ')
            {
                return true;
            }


            else
            {
                cout << "You won't have enough space!" << endl;
                return false;
            }


            size1--;

        }
    }


    else if (direction == 'H')
    {




        for (int i = 0; i < size1; i++)

        {



            if (fleet[x][y + i] == ' ')
            {
                return true;
            }


            else
            {
                cout << "You won't have enough space!" << endl;

                return false;
            }


        }




    }


}





/*"""""""""""""
Function Description:  Parameterized function that contains two integer values that represent array placement and an int value for the size of a ship and a char that contains the directions of the ship placement
Pre-Condition: takes the ship size and location the user wants to place them along with the direction
Post-condition: makes sure that the space desired is empty and

"""""""""""""*/


bool Player::validPlacement(char ship, int x, int y, char direction)
{

    if (ship == 'C' && direction == 'V')
    {
        if ((10 - x) < 5)
        {
            return false;
        }


        else
        {
            return checkEmpty(5, x, y, direction);
        }
    }



    if (ship == 'C' && direction == 'H')
    {
        if ((10 - y) < 5)
        {
            return false;
        }


        else
        {
            return checkEmpty(5, x, y, direction);
        }
    }



    if (ship == 'B' && direction == 'V')
    {
        if ((10 - x) < 4)
        {
            return false;
        }


        else
        {
            return checkEmpty(4, x, y, direction);
        }
    }



    if (ship == 'B' && direction == 'H')
    {
        if ((10 - y) < 4)
        {
            return false;
        }


        else
        {
            return checkEmpty(4, x, y, direction);
        }
    }





    if (ship == 'D' && direction == 'V')
    {
        if ((10 - x) < 3)
        {
            return false;
        }


        else
        {
            return checkEmpty(3, x, y, direction);
        }
    }



    if (ship == 'D' && direction == 'H')
    {
        if ((10 - y) < 3)
        {
            return false;
        }


        else
        {
            return checkEmpty(3, x, y, direction);
        }
    }





    if (ship == 'S' && direction == 'V')
    {
        if ((10 - x) < 3)
        {
            return false;
        }


        else
        {
            return checkEmpty(3, x, y, direction);
        }
    }



    if (ship == 'S' && direction == 'H')
    {
        if ((10 - y) < 3)
        {
            return false;
        }


        else
        {
            return checkEmpty(3, x, y, direction);
        }
    }



    if (ship == 'P' && direction == 'V')
    {
        if ((10 - x) < 3)
        {
            return false;
        }


        else
        {
            return checkEmpty(2, x, y, direction);
        }
    }



    if (ship == 'P' && direction == 'H')
    {
        if ((10 - y) < 2)
        {
            return false;
        }


        else
        {
            return checkEmpty(2, x, y, direction);
        }
    }


}



/*
Function Description:  Parameterized function that contains two integer values that represent array placement and an int value for the size of a ship and a char that contains the directions of the ship placement and another char for ship name
Pre-Condition: takes the ship location , first letter of ship and direction for an operation
Post-condition: sets the array location equal to ship first letter
*/



void Player::markship(char ship, int x, int y, char direction)
{
    //carrier
    if (direction == 'V' && ship == 'C')
    {

        for (int i = 0; i < 5; i++)
        {


            fleet[x + i][y - 65] = ship;

        }

    }



    else if (direction == 'H' && ship == 'C')
    {

        for (int i = 0; i < 5; i++)

        {


            fleet[x][(y - 65) + i] = ship;

        }


    }



    //BattleShip

    else if (direction == 'H' && ship == 'B')
    {

        for (int i = 0; i < 4; i++)
        {


            fleet[x][(y - 65) + i] = ship;

        }

    }



    else if (direction == 'V' && ship == 'B')
    {

        for (int i = 0; i < 4; i++)
        {


            fleet[x + i][y - 65] = ship;

        }

    }



    //Destroyer
    else if (direction == 'V' && ship == 'D')
    {

        for (int i = 0; i < 3; i++)

        {


            fleet[x + i][y - 65] = ship;

        }


    }




    else if (direction == 'H' && ship == 'D')
    {

        for (int i = 0; i < 3; i++)

        {


            fleet[x][(y - 65) + i] = ship;

        }

    }




    //Submarine
    if (direction == 'V' && ship == 'S')
    {

        for (int i = 0; i < 3; i++)
        {





            fleet[x + i][y - 65] = ship;

        }

    }



    else if (direction == 'H' && ship == 'S')
    {

        for (int i = 0; i < 3; i++)

        {


            fleet[x][(y - 65) + i] = ship;

        }


    }






    //PT BOAT

    if (direction == 'V' && ship == 'P')
    {

        for (int i = 0; i < 2; i++)
        {


            fleet[x + i][y - 65] = ship;

        }


    }



    else if (direction == 'H' && ship == 'P')
    {

        for (int i = 0; i < 2; i++)
        {



            fleet[x][(y - 65) + i] = ship;

        }


    }





    printBoard(fleet);

}



/*
Function Description:  Parameterized function that contains a char of the first name of ship
Pre-Condition: takes the char of ship and converts it to an integer
Post-condition: returns the equivalent num of the charter
*/


int Player::convertInttoLetter(char letter)

{



    switch (letter)
    {
    case 'A':


    {



        return 0;
    }


    break;


    case 'B':


    {


        return 1;



    }
    break;

    case 'C':



    {



        return 2;



    }

    break;

    case 'D':



    {




        return 3;





    }

    break;

    case 'E':



    {




        return 4;








    }
    break;



    case 'F':


    {



        return 5;



    }
    break;

    case 'G':



    {




        return 6;


    }
    break;

    case 'H':

    {




        return 7;


    }
    break;

    case 'I':


    {




        return 8;


    }
    break;

    case 'J':


    {



        return 9;

    }
    break;

    default:
        cout << "option not valid" << endl;


        return -1;


    }


}


/*
Function Description: function that interacts with user to have the user place a ship
Pre-Condition: asks the user to enter ship location and directions and calls the validPlacement function to ensure the placement is empty if the validPlacement function returns true the function will call markFunction to mark the array else it will ask the user to enter valid placement
Post-condition: calls mark function to mark board ,marks ship filed true after completion and increments player's ship filed
*/


void Player::placeShips()
{

    int ship_order;
    int ammount = 0;



    cout << "Players name: " << name << endl;


    cout << "Which ship would you like to place [1-Carrier , 2-Battleship, 3-Destroyer , 4-Submarine , 5-PTBoat] " << endl;

    cin >> ship_order;


    while ((ship_order != 1) && (ship_order != 2) && (ship_order != 3) && (ship_order != 4) && (ship_order != 5))
    {
        cout << "Enter a valid placement " << endl;
        cin >> ship_order;
    }


    cout << "Enter location of ship" << endl;

    int row;
    char column;
    char direction;
    int num;//stores value of converted letter


    char airCraft = 'C';
    char battle = 'B';
    char destroyer = 'D';
    char sub_Ship = 'S';
    char pt = 'P';


    int carrier_choice = 0;
    int battleShip_choice = 0;
    int destroyer_choice = 0;
    int submarine_choice = 0;
    int pt_choice = 0;




    do {


        ammount = ammount + 1;


        //air craft carrier
        if (ship_order == 1 && carrier_choice == 0)
        {





            cout << endl << endl << endl << endl;

            cout << "You are hiding the Air craft carrier you have " << carrier_ship.getHullpoint() << " spots to fill" << endl << endl;





            cout << "Enter row [0-9]" << endl;
            cin >> row;

            while ((row > 9) || (row < 0))
            {
                cout << "Error" << endl;
                cin >> row;
            }
            cout << endl;
            cout << "Enter column [A-J]" << endl;
            cin >> column;
            num = convertInttoLetter(column);

            while ((num > 9) || (num < 0))
            {
                cout << "Error Column" << endl;
                cin >> column;
                num = convertInttoLetter(column);
            }


            cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
            cin >> direction;

            while ((direction != 'V') && (direction != 'H'))

            {
                cout << "Error direction" << endl;
                cin >> direction;
            }



            for (int i = 5; i > 0; i--)
            {
                checkEmpty(i, row, num, direction);
                while (checkEmpty(i, row, num, direction) == false)
                {
                    cout << "NOT Empty" << endl;
                    cout << "Enter row [0-9]" << endl;
                    cin >> row;
                    cout << "Enter column [A-J]" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                    cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                    cin >> direction;
                    checkEmpty(i, row, num, direction);

                }

            }





            while (validPlacement(airCraft, row, num, direction) == false)
            {
                cout << "This will create hangover" << endl;

                cout << "Enter row [0-9]" << endl;
                cin >> row;

                while ((row > 9) || (row < 0))
                {
                    cout << "Error" << endl;
                    cin >> row;
                }
                cout << endl;
                cout << "Enter column [A-J]" << endl;
                cin >> column;
                num = convertInttoLetter(column);

                while ((num > 9) || (num < 0))
                {
                    cout << "Error Column" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                }


                cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                cin >> direction;

                while ((direction != 'V') && (direction != 'H'))

                {
                    cout << "Error direction" << endl;
                    cin >> direction;
                }





                validPlacement(airCraft, row, num, direction);




            }

            //check if valid placement


            markship(airCraft, row, column, direction); //mark it

            carrier_choice = carrier_choice + 1;//indicates that carrier ship has already been placed

            carrier_ship.setPlace(true);
            carrier_ship.getPlace();
            ships = ships + 1;

        }



        //validate that carrier ship has only been called once


        if (carrier_choice != 0)

        {
            cout << "Carrier ship has already been placed.. place another ship [2-Battleship, 3-Destroyer , 4-Submarine , 5-PTBoat] " << endl;


        }



        //Battleship

        cout << endl << endl;

        if (ship_order == 2 && battleShip_choice == 0)
        {




            cout << "You are hiding  the Battle ship you have " << battle_ship.getHullpoint() << " spots to fill" << endl;








            cout << "Enter row [0-9]" << endl;
            cin >> row;

            while ((row > 9) || (row < 0))
            {
                cout << "Error" << endl;
                cin >> row;
            }
            cout << endl;
            cout << "Enter column [A-J]" << endl;
            cin >> column;
            num = convertInttoLetter(column);

            while ((num > 9) || (num < 0))
            {
                cout << "Error Column" << endl;
                cin >> column;
                num = convertInttoLetter(column);
            }


            cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
            cin >> direction;

            while ((direction != 'V') && (direction != 'H'))

            {
                cout << "Error direction" << endl;
                cin >> direction;
            }






            for (int i = 4; i > 0; i--)
            {
                checkEmpty(i, row, num, direction);
                while (checkEmpty(i, row, num, direction) == false)
                {
                    cout << "NOT Empty" << endl;
                    cout << "Enter row [0-9]" << endl;
                    cin >> row;
                    cout << "Enter column [A-J]" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                    cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                    cin >> direction;
                    checkEmpty(i, row, num, direction);

                }

            }


            while (validPlacement(battle, row, num, direction) == false)
            {
                cout << "This will create hangover" << endl;

                cout << "Enter row [0-9]" << endl;
                cin >> row;

                while ((row > 9) || (row < 0))
                {
                    cout << "Error" << endl;
                    cin >> row;
                }
                cout << endl;
                cout << "Enter column [A-J]" << endl;
                cin >> column;
                num = convertInttoLetter(column);

                while ((num > 9) || (num < 0))
                {
                    cout << "Error Column" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                }


                cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                cin >> direction;

                while ((direction != 'V') && (direction != 'H'))

                {
                    cout << "Error direction" << endl;
                    cin >> direction;
                }





                validPlacement(battle, row, num, direction);




            }

            //check if valid placement


            markship(battle, row, column, direction); //mark it
            battleShip_choice = battleShip_choice + 1;//indicates battle ship has been placed

            battle_ship.setPlace(true);
            battle_ship.getPlace();
            ships = ships + 1;




        }



        if (battleShip_choice != 0)

        {
            cout << "Battleship ship has already been placed.. place another ship [1-Carrier, 3-Destroyer , 4-Submarine , 5-PTBoat] " << endl;

        }


        //Destroyer


        if (ship_order == 3 && destroyer_choice == 0)
        {


            cout << endl << endl;

            cout << "You are hiding  the Destroyer you have " << destroyer_ship.getHullpoint() << " spots to fill" << endl;


            cout << "Enter row [0-9]" << endl;
            cin >> row;

            while ((row > 9) || (row < 0))
            {
                cout << "Error" << endl;
                cin >> row;
            }
            cout << endl;
            cout << "Enter column [A-J]" << endl;
            cin >> column;
            num = convertInttoLetter(column);

            while ((num > 9) || (num < 0))
            {
                cout << "Error Column" << endl;
                cin >> column;
                num = convertInttoLetter(column);
            }


            cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
            cin >> direction;

            while ((direction != 'V') && (direction != 'H'))

            {
                cout << "Error direction" << endl;
                cin >> direction;
            }



            for (int i = 3; i > 0; i--)
            {
                checkEmpty(i, row, num, direction);
                while (checkEmpty(i, row, num, direction) == false)
                {
                    cout << "NOT Empty" << endl;
                    cout << "Enter row [0-9]" << endl;
                    cin >> row;
                    cout << "Enter column [A-J]" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                    cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                    cin >> direction;
                    checkEmpty(i, row, num, direction);

                }

            }



            while (validPlacement(destroyer, row, num, direction) == false)
            {
                cout << "This will create hangover" << endl;

                cout << "Enter row [0-9]" << endl;
                cin >> row;

                while ((row > 9) || (row < 0))
                {
                    cout << "Error" << endl;
                    cin >> row;
                }
                cout << endl;
                cout << "Enter column [A-J]" << endl;
                cin >> column;
                num = convertInttoLetter(column);

                while ((num > 9) || (num < 0))
                {
                    cout << "Error Column" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                }


                cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                cin >> direction;

                while ((direction != 'V') && (direction != 'H'))

                {
                    cout << "Error direction" << endl;
                    cin >> direction;
                }



                validPlacement(destroyer, row, num, direction);


            }


            //check if valid placement

            markship(destroyer, row, column, direction); //mark it
            destroyer_choice = destroyer_choice + 1;//indicates destroyer ship has been placed


            destroyer_ship.setPlace(true);
            destroyer_ship.getPlace();
            ships = ships + 1;

        }


        if (destroyer_choice != 0)
        {

            cout << "Destroyer ship has already been placed.. place another ship [1-Carrier, 2-Battleship , 4-Submarine , 5-PTBoat] " << endl;
        }



        //Submarine


        if (ship_order == 4 && submarine_choice == 0)
        {


            cout << endl << endl;
            cout << "You are hiding the Submarine  you have " << submarine_ship.getHullpoint() << " spots to fill" << endl;

            cout << "Enter row [0-9]" << endl;
            cin >> row;

            while ((row > 9) || (row < 0))
            {
                cout << "Error" << endl;
                cin >> row;
            }
            cout << endl;
            cout << "Enter column [A-J]" << endl;
            cin >> column;
            num = convertInttoLetter(column);

            while ((num > 9) || (num < 0))
            {
                cout << "Error Column" << endl;
                cin >> column;
                num = convertInttoLetter(column);
            }


            cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
            cin >> direction;

            while ((direction != 'V') && (direction != 'H'))

            {
                cout << "Error direction" << endl;
                cin >> direction;
            }


            for (int i = 3; i > 0; i--)
            {
                checkEmpty(i, row, num, direction);
                while (checkEmpty(i, row, num, direction) == false)
                {
                    cout << "NOT Empty" << endl;
                    cout << "Enter row [0-9]" << endl;
                    cin >> row;
                    cout << "Enter column [A-J]" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                    cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                    cin >> direction;
                    checkEmpty(i, row, num, direction);

                }

            }


            while (validPlacement(sub_Ship, row, num, direction) == false)
            {
                cout << "This will create hangover" << endl;

                cout << "Enter row [0-9]" << endl;
                cin >> row;

                while ((row > 9) || (row < 0))
                {
                    cout << "Error" << endl;
                    cin >> row;
                }
                cout << endl;
                cout << "Enter column [A-J]" << endl;
                cin >> column;
                num = convertInttoLetter(column);

                while ((num > 9) || (num < 0))
                {
                    cout << "Error Column" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                }


                cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                cin >> direction;

                while ((direction != 'V') && (direction != 'H'))

                {
                    cout << "Error direction" << endl;
                    cin >> direction;
                }


                validPlacement(sub_Ship, row, num, direction);


            }

            //check if valid placement


            markship(sub_Ship, row, column, direction); //mark it


            submarine_choice = submarine_choice + 1;//indicates that submarine has been placed


            submarine_ship.setPlace(true);
            submarine_ship.getPlace();
            ships = ships + 1;

        }



        if (submarine_choice != 0)
        {


            cout << "Submarine ship has already been placed.. place another ship [1-Carrier, 2-Battleship , 3-Destroyer , 5-PTBoat] " << endl;
        }

        //Patrol boat


        if (ship_order == 5 && pt_choice == 0)
        {


            cout << endl << endl;
            cout << "You are hiding the  Patrol Boat   you have " << patrol_ship.getHullpoint() << " spots to fill" << endl;


            cout << "Enter row [0-9]" << endl;
            cin >> row;

            while ((row > 9) || (row < 0))
            {
                cout << "Error" << endl;
                cin >> row;
            }
            cout << endl;
            cout << "Enter column [A-J]" << endl;
            cin >> column;
            num = convertInttoLetter(column);

            while ((num > 9) || (num < 0))
            {
                cout << "Error Column" << endl;
                cin >> column;
                num = convertInttoLetter(column);
            }


            cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
            cin >> direction;

            while ((direction != 'V') && (direction != 'H'))

            {
                cout << "Error direction" << endl;
                cin >> direction;
            }


            for (int i = 2; i > 0; i--)
            {
                checkEmpty(i, row, num, direction);
                while (checkEmpty(i, row, num, direction) == false)
                {
                    cout << "NOT Empty" << endl;
                    cout << "Enter row [0-9]" << endl;
                    cin >> row;
                    cout << "Enter column [A-J]" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                    cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                    cin >> direction;
                    checkEmpty(i, row, num, direction);

                }

            }


            while (validPlacement(pt, row, num, direction) == false)
            {
                cout << "This will create hangover" << endl;

                cout << "Enter row [0-9]" << endl;
                cin >> row;

                while ((row > 9) || (row < 0))
                {
                    cout << "Error" << endl;
                    cin >> row;
                }
                cout << endl;
                cout << "Enter column [A-J]" << endl;
                cin >> column;
                num = convertInttoLetter(column);

                while ((num > 9) || (num < 0))
                {
                    cout << "Error Column" << endl;
                    cin >> column;
                    num = convertInttoLetter(column);
                }


                cout << "What direction would you like to place your fleet (Horizontal:H or Vertical:V )" << endl;
                cin >> direction;

                while ((direction != 'V') && (direction != 'H'))

                {
                    cout << "Error direction" << endl;
                    cin >> direction;
                }


                validPlacement(pt, row, num, direction);

            }

            //check if valid placement


            markship(pt, row, column, direction); //mark it
            pt_choice = pt_choice + 1;//indicates pt boat has been placed

            patrol_ship.setPlace(true);
            patrol_ship.getPlace();

            ships = ships + 1;


        }

        if (pt_choice != 0)
        {


            cout << "PatrolBoat ship has already been placed.. place another ship [1-Carrier, 2-Battleship , 3-Destroyer , 4-Submarine] " << endl;
        }



        cout << "Which ship would you like to place next [1-Carrier , 2-Battleship, 3-Destroyer , 4-Submarine , 5-PTBoat] " << endl;
        cin >> ship_order;



        while ((ship_order != 1) && (ship_order != 2) && (ship_order != 3) && (ship_order != 4) && (ship_order != 5))
        {
            cout << "Enter a valid placement " << endl;
            cin >> ship_order;
        }

    } while (ammount <= 5);

}//end of function




/*
Function Description: Parameterized function that contain two integer values to make sure users input valid shots
Pre-Condition:  its in the values and uses an if statement to make sure that they are within the bound of the board
Post-condition: returns 1/true if shot if valid and false /-1 if shot is not valid
*/


bool Player::validshot(int x, int y)

{

    if (x >= 0 && x <= 9 && y >= 0 && y <= 9)
    {



        if (enemy[x][y] == ' ')
        {
            return 1;

        }

        else
        {
            return -1;
        }





    }


    else
    {

        return  -1;
    }







}


/*
Function Description: Parameterized function that contain two integer values and a reference to Player marks an X if player shots an enemy array and increments score or marks an o if player misses
Pre-Condition:  uses an if statement to make sure that the enemy array is empty then if user choses the passed it fleet array spot it marks it and increments the score .
Post-condition: lets user know if they the place they chose has already been fried and asks user to pick another place to fire finally increments score and lets user know if they hit or missed a;so calls in players mutator method to decrement their ship by one
*/
void Player::markResult(int x, int y, Player& p)
{
    if (enemy[x][y] == ' ')
    {



        if (p.fleet[x][y] == 'C')
        {




            enemy[x][y] = 'X';
            cout << "********Hit!*****" << endl;
            p.carrier_ship.hit();
            //*************** p.setShip();
            score = score + 10;
            if (p.carrier_ship.getHullpoint() == 0)
            {
                cout << "Enemy ******" << carrier_ship.getName() << " sunk! " << endl;

                setShip();


            }



        }


        else if (p.fleet[x][y] == 'B')
        {
            enemy[x][y] = 'X';
            cout << "Hit!" << endl;
            p.battle_ship.hit();


            score = score + 10;
            if (p.battle_ship.getHullpoint() == 0)
            {
                cout << "Enemy " << battle_ship.getName() << " sunk! " << endl;
                setShip();
            }




        }





        else if (p.fleet[x][y] == 'D')
        {
            enemy[x][y] = 'X';
            cout << "Hit!" << endl;

            p.destroyer_ship.hit();
            score = score + 10;
            if (p.destroyer_ship.getHullpoint() == 0)
            {
                cout << "Enemy " << destroyer_ship.getName() << " sunk! " << endl;
                setShip();

            }


        }




        else if (p.fleet[x][y] == 'S')
        {
            enemy[x][y] = 'X';
            cout << "Hit!" << endl;
            p.submarine_ship.hit();
            score = score + 10;
            if (p.submarine_ship.getHullpoint() == 0)
            {
                cout << "Enemy " << submarine_ship.getName() << " sunk! " << endl;
                setShip();

            }



        }






        else if (p.fleet[x][y] == 'P')
        {
            enemy[x][y] = 'X';
            cout << "Hit!" << endl;
            p.patrol_ship.hit();
            score = score + 10;
            if (p.patrol_ship.getHullpoint() == 0)
            {
                cout << "Enemy " << patrol_ship.getName() << " sunk! " << endl;
                setShip();

            }


        }




        else if (p.fleet[x][y] == ' ')
        {
            cout << "****MISS!*****" << endl;
            enemy[x][y] = 'O';
        }








    }
    else
    {

        cout << "this spot is already taken try another spot" << endl;
        fire(p);


    }





}


/*
Function Description: function that returns true if a player wins
Pre-Condition:  compares if user score reaches 170
Post-condition: returns true if user score is 170 or false if it's not 170
*/

bool Player::checkwin()
{

    if (score == 170)
    {
        cout << "~~~~~~~Player " << name << " is victorious!~~~~~~~" << endl;
        return true;
    }

    else
    {
        return false;
    }






}

/*
Function Description: Parameterized function that contains passed in player and has user enter a valid shot and marks enemy array
Pre-Condition:  makes sure that the user enters a valid shot by using validshot function that contains parameterized integers return true if valid and call mark function to mark the board else has the user reenter a valid shot
Post-condition: marks board
*/



/*
Function Description:Makes sure all positions are with the confines of the playing board and no hangover
Pre-Condition:takes in the row in column the user wishes to place the nuke
Post-condition: return 1 (true) if there's no hangover and -1(false)otherwise


*/
bool Player::checkNuke(int x, int y)
{


    if (x >= 2 && x <= 7 && y >= 2 && y <= 7)//Makes sure all positions are with the confines of the playing board and no hangover
    {



        if (enemy[x][y] == ' ')
        {
            return 1;

        }



        else
        {

            return -1;
        }


    }





    else
    {

        return -1;
    }





}

/*
Function Description:makes sure that user enters a valid nuke place
Pre-Condition:checks if all positions of the nuke is within the confines of playing board.
Post-condition:returns true if coordinates are valid or false if invalid

*/
void Player::detonate(int x, int y, Player& p)


{




    if (p.enemy[x][y] == ' ')
    {
        markResult(x, y, p);

    }




    if (p.enemy[x - 1][y - 1] == ' ')
    {
        int newx = x - 1;
        int newy = y - 1;
        markResult(newx, newy, p);
    }


    if (p.enemy[x - 1][y + 1] == ' ')
    {
        int newx = x - 1;
        int newy = y + 1;
        markResult(newx, newy, p);
    }

    if (p.enemy[x + 1][y - 1] == ' ')
    {
        int newx = x + 1;
        int newy = y - 1;
        markResult(newx, newy, p);
    }

    if (p.enemy[x + 1][y + 1] == ' ')
    {
        int newx = x + 1;
        int newy = y + 1;
        markResult(newx, newy, p);
    }

    if (p.enemy[x - 2][y - 2] == ' ')
    {
        int newx = x - 2;
        int newy = y - 2;
        markResult(newx, newy, p);
    }


    if (p.enemy[x - 2][y - 0] == ' ')
    {
        int newx = x - 2;
        int newy = y - 0;
        markResult(newx, newy, p);
    }


    if (p.enemy[x - 2][y + 2] == ' ')
    {
        int newx = x - 2;
        int newy = y + 2;
        markResult(newx, newy, p);
    }


    if (p.enemy[x + 2][y - 2] == ' ')
    {
        int newx = x + 2;
        int newy = y - 2;
        markResult(newx, newy, p);
    }


    if (p.enemy[x + 2][y + 0] == ' ')
    {
        int newx = x + 2;
        int newy = y + 0;
        markResult(newx, newy, p);
    }


    if (p.enemy[x + 2][y + 2] == ' ')
    {
        int newx = x + 2;
        int newy = y + 2;
        markResult(newx, newy, p);
    }




}

/*
Function Description: allows user to fire their shoots and nuke
Pre-Condition: takes players shot by using the the players passed in &p
Post-condition: validates shoots and marks them
*/

void Player::fire(Player& p)

{

    int x, y;


    if ((tacNuke == true && ships < 3) && (p.submarine_ship.getHullpoint() > 0 || p.carrier_ship.getHullpoint() > 3))
    {

        cout << "Would you like to fire your nuke (Y OR N)" << endl;
        char  choice;
        cin >> choice;
        if (choice == 'Y')
        {



            cout << "Enter nuke x-column " << endl;
            cin >> x;
            cout << "Enter nuke y-column" << endl;
            cin >> y;


            while (checkNuke(x, y) == -1)
            {
                cout << "Not valid placement " << endl;
                cout << "Enter nuke x-column " << endl;
                cin >> x;
                cout << "Enter nuke y-column" << endl;
                cin >> y;
            }


            detonate(x, y, p);


            tacNuke = false;
        }


        else if (choice == 'N')
        {
            cout << "Nuke is on standby" << endl;
        }
    }





    if (p.carrier_ship.getHullpoint() != 0 || p.battle_ship.getHullpoint() != 0 || p.submarine_ship.getHullpoint() != 0 || p.destroyer_ship.getHullpoint() != 0 || p.patrol_ship.getHullpoint() != 0)

    {


        cout << "shoot the enemy array " << endl;



        int row;
        char column;
        int num;


        if (p.carrier_ship.getHullpoint() != 0)
        {

            cout << "Enter row [0-9]" << endl;
            cin >> row;
            cout << "Enter column  [A-J] " << endl;
            cin >> column;

            p.carrier_ship.fireWeapons();


            num = convertInttoLetter(column);


            while (validshot(row, num) == -1)
            {
                cout << "NOT A VALID SHOT TRY AGAIN " << endl;

                cout << "shoot the enemy array " << endl;
                int row;
                char column;
                cout << "Enter row [0-9]" << endl;
                cin >> row;
                cout << "Enter column  [A-J] " << endl;
                cin >> column;


                num = convertInttoLetter(column);



            }



            markResult(row, num, p);




        }





        if (p.battle_ship.getHullpoint() != 0)
        {



            cout << "Enter row [0-9]" << endl;
            cin >> row;
            cout << "Enter column  [A-J] " << endl;
            cin >> column;

            p.battle_ship.fireWeapons();





            num = convertInttoLetter(column);



            while (validshot(row, num) == -1)
            {
                cout << "NOT A VALID SHOT TRY AGAIN " << endl;

                cout << "shoot the enemy array " << endl;
                int row;
                char column;
                cout << "Enter row [0-9]" << endl;
                cin >> row;
                cout << "Enter column  [A-J] " << endl;
                cin >> column;


                num = convertInttoLetter(column);


            }



            markResult(row, num, p);


        }



        if (p.destroyer_ship.getHullpoint() != 0)
        {

            cout << "Enter row [0-9]" << endl;
            cin >> row;
            cout << "Enter column  [A-J] " << endl;
            cin >> column;

            p.destroyer_ship.fireWeapons();





            num = convertInttoLetter(column);



            while (validshot(row, num) == -1)
            {
                cout << "NOT A VALID SHOT TRY AGAIN " << endl;

                cout << "shoot the enemy array " << endl;
                int row;
                char column;
                cout << "Enter row [0-9]" << endl;
                cin >> row;
                cout << "Enter column  [A-J] " << endl;
                cin >> column;


                num = convertInttoLetter(column);

            }



            markResult(row, num, p);
        }




        if (p.submarine_ship.getHullpoint() != 0)
        {



            cout << "Enter row [0-9]" << endl;
            cin >> row;
            cout << "Enter column  [A-J] " << endl;
            cin >> column;

            p.submarine_ship.fireWeapons();

            num = convertInttoLetter(column);




            while (validshot(row, num) == -1)
            {
                cout << "NOT A VALID SHOT TRY AGAIN " << endl;

                cout << "shoot the enemy array " << endl;
                int row;
                char column;
                cout << "Enter row [0-9]" << endl;
                cin >> row;
                cout << "Enter column  [A-J] " << endl;
                cin >> column;


                num = convertInttoLetter(column);


            }



            markResult(row, num, p);



        }




        if (p.patrol_ship.getHullpoint() != 0)
        {



            cout << "Enter row [0-9]" << endl;
            cin >> row;
            cout << "Enter column  [A-J] " << endl;
            cin >> column;

            p.patrol_ship.fireWeapons();

            num = convertInttoLetter(column);


            while (validshot(row, num) == -1)
            {
                cout << "NOT A VALID SHOT TRY AGAIN " << endl;

                cout << "shoot the enemy array " << endl;
                int row;
                char column;
                cout << "Enter row [0-9]" << endl;
                cin >> row;
                cout << "Enter column  [A-J] " << endl;
                cin >> column;


                num = convertInttoLetter(column);


            }



            markResult(row, num, p);


        }





        else
        {


            markResult(row, num, p);

        }



    }

    cout << "********";
}









