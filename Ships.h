#ifndef SHIPS_H
#define SHIPS_H
#include<string>


using namespace std;




class Ships
{
public:

    Ships(string n = "Default", int hp = 0, bool p = false);

    ~Ships();

    void setName(string n);
    void setHullpoint(int hp);
    void setPlace(bool p);
    const string getName();
    const int getHullpoint();
    const bool getPlace();
    void hit();
    virtual void fireWeapons() = 0;//abstract method



private:
    string name;
    int hullPoints;
    bool placed;
};











#endif // SHIPS_H
#pragma once
