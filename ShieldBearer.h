#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include <iostream>
#include <vector>
#include "Soldiers.h"



class ShieldBearer : public Soldiers
{
    public:

    //void createUnit() override ;

    Soldiers* clonis() override;
    
    ShieldBearer( int damagePerSoldier , int defencePerSoldier  );

     private:
     int healthPerSoldier ;
     int damagePerSoldier;
     int defencePerSoldier;
    // int shieldCapacity;
    int amountOfSoldiersPerUnit = 0 ;
    std::string unitName;

     void prepare() override ;
    void execute() override;
    void retreat() override;
    void rest() override ;
    
    
};





#endif