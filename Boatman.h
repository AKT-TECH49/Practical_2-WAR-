#ifndef BOATMAN_H
#define BOATMAN_H

#include <iostream>
#include <vector>
#include <string>
#include "Soldiers.h"

class Boatman : public Soldiers 
{

    public:
    void createUnit() override ;
    Boatman(int damagePerSoldier,
    int defensePerSoldier);

   Soldiers * clonis() override;


    private :
    int healthPerSoldier ;
    int damagePerSoldier;
    int defensePerSoldier;
    int amountOfSoldiersPerUnit=0;
    //std::vector<std::string> unitNames;
    std::string unitName;
};




#endif