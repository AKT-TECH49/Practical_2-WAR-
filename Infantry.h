#ifndef INFANTRY_H
#define INFANTRY_H


#include "Soldiers.h"

class Infantry : public Soldiers {
public:
     void createUnit() override;
     
    Infantry(int damagePerSoldier , int defensePerSoldier );
    // ~Infantry();
    // void attack(Soldiers* enemy) override;
    Soldiers * clonis() override;

    private:
    int healthPerSoldier ;
    int damagePerSoldier;
    int defensePerSoldier;
    int amountOfSoldiersPerUnit=0;
      //std::string  unitName;

};




#endif