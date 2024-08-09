#ifndef BOATMAN_H
#define BOATMAN_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "Soldiers.h"

class Map;

class Boatman : public Soldiers 
{
    public:
        //void createUnit() override ;
        Boatman(int damagePerSoldier, int defensePerSoldier);
        Soldiers * clonis() override;
        int getHealthPerSoldier() const;
        int getDamagePerSoldier() const;
        int getDefensePerSoldier() const;
        int getAmountOfSoldiersPerUnit() const;
        virtual ~Boatman();

        void Attack(Soldiers* shieldy) override;
        // void Attack(Infantry* infty) override;
        // void Attack(Boatman* boaty) override;

        bool isAlive() override;

    private:
        static int totalBoatmen;
        int healthPerSoldier ;
        int damagePerSoldier;
        int defensePerSoldier;
        int amountOfSoldiersPerUnit;
        std::string unitName;

        void prepare() override ;
        void execute() override;
        void deployBomb(const std::string &bombType);
        void provideBattleIntel();
        void broadcastMessage(const std::string &message);
        int calculateRepairAmount(int currentHealth);
        void retreat() override;
        void rest() override ;
    
};




#endif