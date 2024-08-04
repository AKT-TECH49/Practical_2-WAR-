#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include <iostream>
#include <vector>
#include "Soldiers.h"



class ShieldBearer : public Soldiers
{
    public:
        int getHealthPerSoldier() const;
        int getDamagePerSoldier() const;
        int getDefensePerSoldier() const;
        int getAmountOfSoldiersPerUnit() const;
        //void createUnit() override ;

    Soldiers* clonis() override;
    
    ShieldBearer( int damagePerSoldier , int defencePerSoldier  );

    private:
        static int totalShieldBearer;
        int healthPerSoldier ;
        int damagePerSoldier;
        int defencePerSoldier;
        // int shieldCapacity;
        int amountOfSoldiersPerUnit = 0 ;
        std::string unitName;

        void prepare() override ;
        void execute() override;
        void reinforceShields();
        void phalanxCharge();
        void retreat() override;
        void rest() override ;
    
    
};





#endif