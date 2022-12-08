#ifndef CARRIER_H
#define CARRIER_H

#include <iostream>
#include<string>

#include "Ships.h"
class Carrier : public Ships
{
public:
    Carrier();
    ~Carrier();
    void fireWeapons();


};

#endif // CARRIER_H
