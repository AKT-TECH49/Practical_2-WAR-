#include "ShieldBearer.h"

//create constructor

// void ShieldBearer::createUnit(){
//     // implement logic to create a shieldbearer unit
//     // this could involve creating a new unit object, setting its properties, etc.
//     this.

// }


Soldiers *ShieldBearer::clonis()
{
        //clone once 
        Soldiers *clone = new ShieldBearer(this->damagePerSoldier, this->defencePerSoldier);
        return clone;
}

ShieldBearer::ShieldBearer(int damagePerSoldier, int defencePerSoldier) : Soldiers("ShiledBearer")
{
    this->damagePerSoldier = damagePerSoldier;
    this->defencePerSoldier = defencePerSoldier;
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit + 1;
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
