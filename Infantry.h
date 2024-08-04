#ifndef INFANTRY_H
#define INFANTRY_H


#include "Soldiers.h"

class Infantry : public Soldiers {
public:
     //void createUnit() override;
     
    Infantry(int damagePerSoldier , int defensePerSoldier );
    // ~Infantry();
    // void attack(Soldiers* enemy) override;
    Soldiers * clonis() override;
    int getHealthPerSoldier() const;
    int getDamagePerSoldier() const;
    int getDefensePerSoldier() const;
    int getAmountOfSoldiersPerUnit() const;

    private:
      static int totalInfantry;
      int healthPerSoldier ;
      int damagePerSoldier;
      int defensePerSoldier;
      int amountOfSoldiersPerUnit;//might need to make it static
      //std::string  unitName;

    void prepare() override ;
    void execute() override;
    void retreat() override;
    void rest() override ;


};




#endif