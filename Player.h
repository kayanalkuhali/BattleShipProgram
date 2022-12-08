#ifndef PLAYER_H
#define PLAYER_H


#include<string>
#include "PTBoat.h"
#include "Submarine.h"
#include "Destroyer.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Types.h"
using namespace std;










class Player
{
public:
    Player(string n);
    ~Player();
    ptr_to_array getfleet();
    ptr_to_array getenemy();
    char getLocationStatus(int row, int column);
    void printBoard(char Board[10][10]);
    bool checkEmpty(int size1, int x, int y, char direction);
    bool validPlacement(char ship, int x, int y, char direction);
    void markship(char ship, int x, int y, char direction);
    int convertInttoLetter(char letter);
    void placeShips();
    bool validshot(int x, int y);
    void markResult(int x, int y, Player& p);
    void fire(Player& p);
    void detonate(int x, int y, Player& p);
    bool checkNuke(int x, int y);
    bool checkwin();
    void setShip();

















private:

    string name;
    int score;
    char enemy[10][10];//stores player's shot record
    char fleet[10][10];//stores player's fleet position

    Carrier    carrier_ship;
    Battleship battle_ship;
    Destroyer  destroyer_ship;
    Submarine  submarine_ship;
    PTBoat     patrol_ship;
    int ships;
    bool tacNuke;

















};

#endif // PLAYER_H
#pragma once
