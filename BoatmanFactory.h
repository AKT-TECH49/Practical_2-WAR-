#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H



#include <iostream>
#include <vector>
#include <string>
#include "SoldierFactory.h"


class BoatmanFactory : public SoldierFactory 
{
    public:
     Soldiers* createUnit();
     int calculateTotalHealthPerUnit();
     int calculateTotalDamagePerUnit();
     int calculateTotalDefencePerUnit();

};








#endif //BOATMANFACTORY_H