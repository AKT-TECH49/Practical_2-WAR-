#include "ShieldBearer.h"

//create constructor

// void ShieldBearer::createUnit(){
//     // implement logic to create a shieldbearer unit
//     // this could involve creating a new unit object, setting its properties, etc.
//     this.

// }

int ShieldBearer::totalShieldBearer = 0;

Soldiers *ShieldBearer::clonis()
{
    //clone once 
    Soldiers *clone = new ShieldBearer(this->damagePerSoldier, this->defencePerSoldier);
    return clone;
}

ShieldBearer::ShieldBearer(int damagePerSoldier, int defencePerSoldier) : Soldiers("ShieldBearer")
{
    totalShieldBearer++;
    this->damagePerSoldier = damagePerSoldier;
    this->defencePerSoldier = defencePerSoldier;
    this->amountOfSoldiersPerUnit = totalShieldBearer;
}

int ShieldBearer::getHealthPerSoldier() const
{
   return this->healthPerSoldier;
}

int ShieldBearer::getDamagePerSoldier() const
{
   return this->damagePerSoldier;
}

int ShieldBearer::getDefensePerSoldier() const
{
   return this->defencePerSoldier;
}

int ShieldBearer::getAmountOfSoldiersPerUnit() const
{
   return this->amountOfSoldiersPerUnit;
}

void ShieldBearer::prepare()
{
}

void ShieldBearer::execute()
{
}

void ShieldBearer::retreat()
{
}

void ShieldBearer::rest()
{
}
