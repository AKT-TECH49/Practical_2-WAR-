#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include <iostream>
#include <vector>
#include "Infantry.h"
#include "SoldierFactory.h"

class InfantryFactory : public SoldierFactory
{
      public:
      Soldiers* createUnit();
      int calculateTotalHealthPerUnit();
      int calculateTotalDamagePerUnit();
      int calculateTotalDefence();


    // Infantry* createInfantry(const std::string& type) {
    //     if (type == "Footman") {
    //         return new Footman();
    //     } else if (type == "Swordsman") {
    //         return new Swordsman();
    //     } else if (type == "Archer") {
    //         return new Archer();
    //     } else {
    //         std::cerr << "Invalid infantry type: " << type << std::endl;
    //         return nullptr;
    //     }
    // }
    // void displayInfantryStats(const std::vector<Infantry*>& infantry) {
    //     for (const auto& i : infantry) {
    //         std::cout << "Infantry Type: " << i->getType() << std::endl;
    //         i->displayStats();
    //         std::cout << std::endl;
    //     }
    // }
};

#endif // INFANTRYFACTORY_H