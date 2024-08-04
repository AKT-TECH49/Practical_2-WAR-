#include "Infantry.h"
int Infantry::totalInfantry = 0;

Infantry::Infantry( int damagePerSoldier, int defensePerSoldier):Soldiers("Infantry")
{
    totalInfantry++;
    this->amountOfSoldiersPerUnit = totalInfantry;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
}

Soldiers *Infantry::clonis()
{
    //clone once
    Soldiers * clone = new Infantry(this->damagePerSoldier , this->defensePerSoldier);
    return clone;
    
}

int Infantry::getHealthPerSoldier() const
{
   return this->healthPerSoldier;
}

int Infantry::getDamagePerSoldier() const
{
   return this->damagePerSoldier;
}

int Infantry::getDefensePerSoldier() const
{
   return this->defensePerSoldier;
}

int Infantry::getAmountOfSoldiersPerUnit() const
{
   return this->amountOfSoldiersPerUnit;
}

void Infantry::prepare()
{
    //prepare method to be implemented 

}

void Infantry::execute()
{
    //execute method to be implemented
}

void Infantry::retreat()
{
    //retreat method to be implemented
}

void Infantry::rest()
{
    //rest method to be implemented
}
