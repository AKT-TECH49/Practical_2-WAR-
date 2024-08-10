#include  "Memento.h"
#include "CareTaker.h"


Memento::Memento()
{
    this->healthPerSoldier = 0;
    this->damagePerSoldier = 0;
    this->amountOfSoldiersPerUnit = 0;
    this->defencePerSoldier = 0;
    this->unitName = "";
}


State Memento::getState() const
{
    return state;
}

// void Memento::setState(State s)
// {
//     state = s;
// }

// void Memento::setAtState(int index)
// {
//     ///go back to  a specifc state from caretaker
    
//     state = caretaker.get(index);

// }

// constructor
Memento::Memento(int value1 , int value2 , int value3,int value4 , std::string& value5):unitName(value5)
{   
    this->healthPerSoldier = value1;
    this->damagePerSoldier = value2;
    this->amountOfSoldiersPerUnit= value3;
    this->defencePerSoldier = value4;
}

Memento::~Memento()
{
}

std::string Memento::getUnitName() const
{
    return unitName;
}