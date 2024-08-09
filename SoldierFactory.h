#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H


#include <string>
#include "Soldiers.h"

class Soldiers;

class SoldierFactory //abstract class
{
    private:
    Soldiers* soldier ;
    

    protected:
    
    virtual Soldiers* createUnit() = 0;
    virtual int calculateTotalHealthPerUnit()=0;
    virtual int calculateTotalDamagePerUnit()=0;
   virtual  int calculateTotalDefencePerUnit()=0;



};


#endif 