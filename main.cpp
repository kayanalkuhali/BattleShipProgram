#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#include "Carrier.h"
#include "Battleship.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "PTBoat.h"
#include "Player.h"
//#include "Ship.h"


using namespace std;









int main()
{


    Player p1("p1");
    Player p2("p2");
    p1.printBoard(p1.getenemy());
    p1.placeShips();
    p2.printBoard(p2.getenemy());
    p2.placeShips();






    int player_trun = 1;
    int winner = 0;




    while (false == p1.checkwin() && false == p2.checkwin())
    {


        if (player_trun == 1)
        {
            p1.printBoard(p1.getenemy());
            p1.fire(p1);

            if (p1.checkwin() == 1)
            {
                winner = 1;
                break;
            }

            else
            {
                player_trun = 2;
            }


        }
        if (player_trun == 2)
        {
            p2.printBoard(p2.getenemy());
            p2.fire(p2);

            if (p2.checkwin() == 1)
            {
                winner = 2;
                break;
            }

            else
            {
                player_trun = 1;
            }


        }



    }

    if (winner == 1)
    {
        cout << "Player 1 won  Thanks for playing " << endl;
    }


    else if (winner == 2)
    {
        cout << "  Player 2 Won  Thanks for playing " << endl;
    }




    return 0;
}
