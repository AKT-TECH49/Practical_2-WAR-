#include "BoatmanFactory.h"

Soldiers *BoatmanFactory::createUnit()
{

   return new Boatman(75, 75);
}

int BoatmanFactory::calculateTotalHealthPerUnit()
{
   Boatman *boatman = static_cast<Boatman *>(createUnit());
   boatman->subByOne();
   return boatman->getHealthPerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

int BoatmanFactory::calculateTotalDamagePerUnit()
{
   Boatman *boatman = static_cast<Boatman *>(createUnit());
   boatman->subByOne();
   return boatman->getDamagePerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

int BoatmanFactory::calculateTotalDefencePerUnit()
{
   Boatman *boatman = static_cast<Boatman *>(createUnit());
   boatman->subByOne();
   return boatman->getDefensePerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

int BoatmanFactory::calculateTotalNumOfUnits()
{
   Boatman *boatman = static_cast<Boatman *>(createUnit());
   boatman->subByOne();
   return boatman->getAmountOfSoldiersPerUnit();
}