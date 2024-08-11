#ifndef SHIELDBEARERFATCORY_H
#define SHIELDBEARERFACTORY_H

#include <iostream>
#include "SoldierFactory.h"
#include "ShieldBearer.h"
#include "Soldiers.h"
#include <string>

class ShieldBearerFactory : public SoldierFactory 
{
     public:
     Soldiers* createUnit() override;
     ~ShieldBearerFactory();


     
     int calculateTotalHealthPerUnit();
     int calculateTotalDamagePerUnit();
     int calculateTotalDefencePerUnit();
     int calculateToTalNumUnits();
};


#endif //SHIELDBEARERFACTORY_H

