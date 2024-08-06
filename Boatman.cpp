#include "Boatman.h"

int Boatman::totalBoatmen = 0;
Boatman::Boatman( int damagePerSoldier, int defensePerSoldier ):Soldiers("BoatMan")
{   
    totalBoatmen++;
    this->amountOfSoldiersPerUnit = totalBoatmen ;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
}

Soldiers *Boatman::clonis()
{
    Soldiers * clone = new Boatman(this->damagePerSoldier ,  this->defensePerSoldier);
    return clone;
}

int Boatman::getHealthPerSoldier() const
{
   return this->healthPerSoldier;
}

int Boatman::getDamagePerSoldier() const
{
   return this->damagePerSoldier;
}

int Boatman::getDefensePerSoldier() const
{
   return this->defensePerSoldier;
}

int Boatman::getAmountOfSoldiersPerUnit() const
{
   return this->amountOfSoldiersPerUnit;
}

Boatman::~Boatman()
{
    totalBoatmen--;
    this->amountOfSoldiersPerUnit--;
    delete this;
}

void Boatman::prepare()
{
    std::cout << "Boatman is preparing to fight." << std::endl;


}

void Boatman::execute()
{
}

void Boatman::retreat()
{
    std::cout << "Boatman is retreating." << std::endl;
}

void Boatman::rest()
{
    //recharge health
    this->healthPerSoldier += 10;
    std::cout << "Boatman is resting." << std::endl;
}
