#ifndef SHIELDBEARER_H
#define SHIELDBEARER_H

#include <iostream>
#include <vector>
#include "Soldiers.h"

class ShieldBearer : public Soldiers
{
public:
    int getHealthPerSoldier() const;
    int getDamagePerSoldier();
    int getDefensePerSoldier();
    int getAmountOfSoldiersPerUnit();
    void subByOne();


    // setters
    void setHealthPerSoldier(int health) override;
    void setDamagePerSoldier(int damage) override;
    void setDefensePerSoldier(int defense) override;
    void setAmountOfSoldiersPerUnit(int i) override;

        Soldiers *clonis() override;
        ShieldBearer(int damagePerSoldier, int defencePerSoldier);
        ~ShieldBearer();

        void Attack(Soldiers *shieldy) override;
        bool isAlive() override;

private:
    static int totalShieldBearer;
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    // int shieldCapacity;
    static int amountOfSoldiersPerUnit;
    std::string unitName;

        void prepare() override;
        void execute() override;
        void reinforceShields();
        void phalanxCharge();
        void retreat() override;
        void rest() override;
};

#endif