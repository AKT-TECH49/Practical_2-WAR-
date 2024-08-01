#ifndef BOATMAN_H
#define BOATMAN_H

#include <iostream>
#include <vector>
#include <string>
#include "Soldiers.h"

class Boatman : public Soldiers 
{
    private :
    int healthPerSoldier ;
    int damagePerSoldier;
    int defensePerSoldier;
    int amountOfSoldiersPerUnit;
    //std::vector<std::string> unitNames;
    std::string unitName;
};




#endif