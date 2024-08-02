#include "Infantry.h"

Infantry::Infantry( int damagePerSoldier, int defensePerSoldier):Soldiers("Ifantry")
{
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit+1;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;

}

Soldiers *Infantry::clonis()
{
    //clone once
    Soldiers * clone = new Infantry(this->damagePerSoldier , this->defensePerSoldier);
    return clone;
    
}
