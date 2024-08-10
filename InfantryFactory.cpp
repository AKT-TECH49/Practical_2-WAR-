#include "Infantry.h"
#include "InfantryFactory.h"

Soldiers *InfantryFactory::createUnit()
{
   
    return new Infantry(100,80);
}

InfantryFactory::~InfantryFactory()
{
   //delete this;
}

int InfantryFactory::calculateTotalHealthPerUnit()
{
   Infantry* infantry = static_cast<Infantry*>(createUnit());
   return infantry->getHealthPerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}

int InfantryFactory::calculateTotalDamagePerUnit()
{
   Infantry* infantry = static_cast<Infantry*>(createUnit());
   return infantry->getDamagePerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}

int InfantryFactory::calculateTotalDefencePerUnit()
{
   Infantry* infantry = static_cast<Infantry*>(createUnit());
   return infantry->getDefensePerSoldier() * infantry->getAmountOfSoldiersPerUnit();
}
