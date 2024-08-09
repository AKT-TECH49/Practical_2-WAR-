#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include "State.h"

class Memento
{
public:
    // Memento(State state);
    Memento(int value1, int value2, int value3, int value4, std::string& value5);
    State getState() const;

    virtual ~Memento();
    std::string getUnitName() const;

private:
    // store current state of soldiers
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit;
    std::string unitName;
    
    State state;
    Memento();



    // void setState(State s);
    // void setAtState(int index);


};

#endif // MEMENTO_H