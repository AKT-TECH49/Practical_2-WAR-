#include "Boatman.h"

Boatman::Boatman( int damagePerSoldier, int defensePerSoldier ):Soldiers("BoatMan")
{   
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit + 1 ;//Allowed?
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
}

Soldiers *Boatman::clonis()
{
    Soldiers * clone = new Boatman(this->damagePerSoldier ,  this->defensePerSoldier);
    return clone;
}
