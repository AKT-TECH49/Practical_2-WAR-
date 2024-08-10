#include "Soldiers.h"

Soldiers::Soldiers(std::string unitName)
{
    // THIS IS TO MAKE SURE WE KNOW WHICH TYPE OF SOLDIER WE ARE CREATING
    this->unitName = unitName;
}

Soldiers::~Soldiers()
{
    std::cout << "Soldiers destructor" << std::endl;
    this->amountOfSoldiersPerUnit;
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

Memento *Soldiers::militusMemento()
{

    state.amountOfSoldiersPerUnit = getAmountOfSoldiersPerUnit();
    state.damagePerSoldier = getDamagePerSoldier();
    state.healthPerSoldier = getHealthPerSoldier();
    state.defencePerSoldier = getDefensePerSoldier();

    return new Memento(state.healthPerSoldier, state.damagePerSoldier, state.defencePerSoldier, state.amountOfSoldiersPerUnit, unitName);
}

void Soldiers::vivificaMemento(Memento *memento)
{
    /* this->state = memento->getState();*/ // private
    State state = memento->getState();
    healthPerSoldier = state.healthPerSoldier;
    damagePerSoldier = state.damagePerSoldier;
    defencePerSoldier = state.defencePerSoldier;
    amountOfSoldiersPerUnit = state.amountOfSoldiersPerUnit;
}
