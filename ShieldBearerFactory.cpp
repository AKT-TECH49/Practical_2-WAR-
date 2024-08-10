#include "ShieldBearerFactory.h"


Soldiers * ShieldBearerFactory::createUnit()
{
    return new ShieldBearer(50,100);
}

ShieldBearerFactory::~ShieldBearerFactory()
{
  // delete this;
}

int ShieldBearerFactory::calculateTotalHealthPerUnit()
{
   ShieldBearer* shieldBearer = static_cast<ShieldBearer*>(createUnit());
   return shieldBearer->getHealthPerSoldier() * shieldBearer->getAmountOfSoldiersPerUnit();
}

int ShieldBearerFactory::calculateTotalDamagePerUnit()
{
   ShieldBearer* shieldBearer = static_cast<ShieldBearer*>(createUnit());
   return shieldBearer->getDamagePerSoldier() * shieldBearer->getAmountOfSoldiersPerUnit();
}


int ShieldBearerFactory::calculateTotalDefencePerUnit()
{
   ShieldBearer* shieldBearer = static_cast<ShieldBearer*>(createUnit());
   return shieldBearer->getDefensePerSoldier() * shieldBearer->getAmountOfSoldiersPerUnit();
}
