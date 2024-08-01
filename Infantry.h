#ifndef INFANTRY_H
#define INFANTRY_H


#include "Soldiers.h"

class Infantry : public Soldiers {
public:
    // Infantry(int health, int attack, int defense, int speed);
    // ~Infantry();
    // void attack(Soldiers* enemy) override;

    private:
    int healthPerSoldier ;
    int damagePerSoldier;
    int defensePerSoldier;
    int amountOfSoldiersPerUnit;
    std::string  unitName;

};




#endif