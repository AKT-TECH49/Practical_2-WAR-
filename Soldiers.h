#ifndef SOLDIERS_H
#define SOLDIERS_H

/*Allowed imports:*/

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <list>
#include "Memento.h"
class Memento;
struct State
{
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit ;
};

class Soldiers // abstract
{
public:
    // virtual void createUnit() = 0;
    virtual Soldiers *clonis() = 0;
    Soldiers(std::string unitName);
    virtual int getHealthPerSoldier() const = 0;
    virtual int getDamagePerSoldier() const = 0;
    virtual int getDefensePerSoldier() const = 0;
    virtual int getAmountOfSoldiersPerUnit() const = 0;

    //Template method:
    //create template methods for engage() and disengage()
    void engage();
    void disengage();
   // void attack(Soldiers *enemy);

   //Memento method:
    Memento* militusMemento() ;//create
   void vivificaMemento(Memento* memento);//restore


private:
    int healthPerSoldier;
    int damagePerSoldier;
    int amountOfSoldiersPerUnit;
    std::string unitName;
    State state;
    virtual void prepare() = 0;
    virtual void execute() = 0;
    virtual void retreat() =  0;
    virtual void rest() = 0;
   // virtual void displayInfo() const = 0;
};

#endif