#include  "Memento.h"
#include "CareTaker.h"
Memento *Memento::clone() const
{
       return new Memento(healthPerSoldier, damagePerSoldier, defencePerSoldier, amountOfSoldiersPerUnit, unitName);
    
}

Memento::Memento()
{
    this->healthPerSoldier = 0;
    this->damagePerSoldier = 0;
    this->amountOfSoldiersPerUnit = 0;
    this->defencePerSoldier = 0;
    this->unitName = "";
}

State Memento::getState()
{
    return state;
}

void Memento::setState(State s)
{
    state = s;
}

void Memento::setAtState(int index)
{
    ///go back to  a specifc state from caretaker
    
    state = caretaker.get(index);

}

// constructor
Memento::Memento(int value1 , int value2 , int value3,int value4 , std::string value5)
{
    this->healthPerSoldier = value1;
    this->damagePerSoldier = value2;
    this->amountOfSoldiersPerUnit= value3;
    this->defencePerSoldier = value4;
    this->unitName = value5;

}

