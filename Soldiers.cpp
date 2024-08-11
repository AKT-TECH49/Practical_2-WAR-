#include "Soldiers.h"

Soldiers::Soldiers(std::string unitName)
{
    this->unitName = unitName;
}

Soldiers::~Soldiers()
{
    delete this;
}

void Soldiers::engage()
{
    // call prepare() and execute() methods
    prepare();
    execute();
}

void Soldiers::disengage()
{
    // call retreat() and rest() methods:
    retreat();
    rest();
}

Memento *Soldiers::militusMemento() const // Creates a memento 
{
     State currentState = { healthPerSoldier, damagePerSoldier, defencePerSoldier, amountOfSoldiersPerUnit, unitName };
    return new Memento(currentState);
}


void Soldiers::vivificaMemento(Memento *memento) // Restores 
{
    State state = memento->getState();
    healthPerSoldier = state.healthPerSoldier;
    damagePerSoldier = state.damagePerSoldier;
    defencePerSoldier = state.defencePerSoldier;
    amountOfSoldiersPerUnit = state.amountOfSoldiersPerUnit;
    unitName = state.unitName;
    
}
