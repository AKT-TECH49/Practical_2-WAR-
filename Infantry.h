#ifndef INFANTRY_H
#define INFANTRY_H

#include "Soldiers.h"

class Infantry : public Soldiers
{
public:
  Infantry(int damagePerSoldier, int defensePerSoldier);
  virtual ~Infantry();
  

  Soldiers *clonis() override;

  //getters
  int getHealthPerSoldier() const ;
  int getDamagePerSoldier() ;
  int getDefensePerSoldier();
  int getAmountOfSoldiersPerUnit();
  int calculateRepairAmount(int currentHealth);
  void subByOne();

  //Setters
  void setHealthPerSoldier(int i) override;
  void setDamagePerSoldier(int i ) override ;
  void setDefensePerSoldier(int i ) override ;
  void setAmountOfSoldiersPerUnit(int i) override ;



//action
  void Attack(Soldiers *shieldy) override;
  bool isAlive() override;


private:
  int healthPerSoldier;
  int damagePerSoldier;
  int defensePerSoldier;
  static int amountOfSoldiersPerUnit;
  std::string unitName ;



  void prepare() override;
  void execute() override;
  void retreat() override;
  void rest() override;

  
};

#endif