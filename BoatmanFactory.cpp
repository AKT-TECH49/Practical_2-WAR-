#include "BoatmanFactory.h"

Soldiers * BoatmanFactory::createUnit()
{
   return new Boatman(75,75);
}

int BoatmanFactory::calculateTotalHealthPerUnit()
{
   //Boatman* boatman = static_cast<Boatman*>(createUnit());

   Soldiers* boatman = createUnit();
   // std::cout << "Health:\n" << boatman->getHealthPerSoldier() << std::endl;
   
   // std::cout << "No of soldiers:\n" << boatman->getAmountOfSoldiersPerUnit() << std::endl;


   return boatman->getHealthPerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

int BoatmanFactory::calculateTotalDamagePerUnit()
{
   Boatman* boatman = static_cast<Boatman*>(createUnit());
    return boatman->getDamagePerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

int BoatmanFactory::calculateTotalDefencePerUnit()
{
   Boatman* boatman = static_cast<Boatman*>(createUnit());
   return boatman->getDefensePerSoldier() * boatman->getAmountOfSoldiersPerUnit();
}

BoatmanFactory::~BoatmanFactory()
{
   //delete this;
}
