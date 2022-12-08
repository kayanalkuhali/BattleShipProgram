#ifndef DESTROYER_H
#define DESTROYER_H
#include <iostream>
#include<string>

#include "Ships.h"



class Destroyer : public Ships
{
public:
    Destroyer();
    ~Destroyer();
    void fireWeapons();


};




#endif // DESTROYER_H
#pragma once
