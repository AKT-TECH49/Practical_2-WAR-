#include "Infantry.h"
#include "InfantryFactory.h"

Soldiers *InfantryFactory::createUnit()
{

   return new Infantry(100, 80);
}



int InfantryFactory::calculateTotalHealthPerUnit()
{
   Infantry *infantry = static_cast<Infantry *>(createUnit());
   infantry->subByOne();
   return infantry->getHealthPerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}

int InfantryFactory::calculateTotalDamagePerUnit()
{
   Infantry *infantry = static_cast<Infantry *>(createUnit());
   infantry->subByOne();
   return infantry->getDamagePerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}

int InfantryFactory::calculateTotalDefencePerUnit()
{
   Infantry *infantry = static_cast<Infantry *>(createUnit());
   infantry->subByOne();
   return infantry->getDefensePerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}

int InfantryFactory::calculateTotalNumOfUnits()
{
   Infantry* infantry = static_cast<Infantry*>(createUnit());
   infantry->subByOne();
   return infantry->getAmountOfSoldiersPerUnit();
}