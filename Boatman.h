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

  Boatman(int damagePerSoldier, int defensePerSoldier);
  void createUnit();
  Boatman();
  virtual ~Boatman();

  Soldiers *clonis() override;

  //getters
  int getHealthPerSoldier() const;
  int getDamagePerSoldier();
  int getDefensePerSoldier();
  int getAmountOfSoldiersPerUnit();

  // setters
  void setHealthPerSoldier(int i) override;
  void setDamagePerSoldier(int i) override;
  void setDefensePerSoldier(int i) override;
  void setAmountOfSoldiersPerUnit(int i) override;


  //action
  void Attack(Soldiers *shieldy) override;
  bool takeDamage(Boatman *boat, int i);
  void subByOne();
  bool isAlive() override;

  private:
  int healthPerSoldier;
  int damagePerSoldier;
  int defensePerSoldier;
  static int amountOfSoldiersPerUnit;
  std::string unitName;


  void prepare() override;
  void execute() override;
  void retreat() override;
  void rest() override;

  //helpers
  int calculateRepairAmount(int currentHealth);



};

#endif