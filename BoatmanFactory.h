#ifndef BOATMANFACTORY_H
#define BOATMANFACTORY_H



#include <iostream>
#include <vector>
#include <string>
#include "SoldierFactory.h"
#include "Soldiers.h"
#include "Boatman.h"

class BoatmanFactory : public SoldierFactory 
{
    public:
     Soldiers* createUnit() override;
     int calculateTotalHealthPerUnit();
     int calculateTotalDamagePerUnit();
     int calculateTotalDefencePerUnit();
     ~BoatmanFactory();

};








#endif //BOATMANFACTORY_H