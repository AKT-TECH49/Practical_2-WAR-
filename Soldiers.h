#ifndef SOLDIERS_H
#define SOLDIERS_H

/*Allowed imports:*/

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <list>


class Soldiers//abstract 
{
    public:
        virtual void createUnit() = 0;
        virtual Soldiers* clonis() = 0 ;
        Soldiers(std::string unitName);

        
        
    private:
    int  healthPerSoldier ;
    int damagePerSoldier;
    int amountOfSoldiersPerUnit;
   std::string  unitName;

};


#endif