#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include <iostream>
#include <vector>
#include "Soldiers.h"



class ShieldBearer : public Soldiers
{
     private:
     int healthPerSoldier ;
     int damagePerSoldier;
     int defencePerSoldier;
    // int shieldCapacity;
    int amountOfSoldiersPerUnit ;
    std::string unitName;
    
};





#endif