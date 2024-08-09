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


     
     int calculateTotalHealthPerUnit();
     int calculateTotalDamagePerUnit();
     int calculateTotalDefencePerUnit();
     int calculateToTalNumUnits();

     // Soldier* createSoldier(const std::string& type) override {
     //     if (type == "shieldbearer") {
     //         return new ShieldBearer();
     //     }
     //     std::cerr << "Invalid soldier type: " << type << std::endl;
     //     return nullptr;
     // }
};


#endif //SHIELDBEARERFACTORY_H

