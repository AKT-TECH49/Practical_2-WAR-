#ifndef INFANTRYFACTORY_H
#define INFANTRYFACTORY_H

#include <iostream>
#include <vector>
#include "Infantry.h"
#include "SoldierFactory.h"
#include "Soldiers.h"

class InfantryFactory : public SoldierFactory
{
      public:
      Soldiers* createUnit() override;
      ~InfantryFactory();

      int calculateTotalHealthPerUnit();
      int calculateTotalDamagePerUnit() ;
      int calculateTotalDefencePerUnit();
};

#endif // INFANTRYFACTORY_H