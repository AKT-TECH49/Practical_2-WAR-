#include "Soldiers.h"

Soldiers::Soldiers(std::string unitName, int amountOfSoldiersPerUnit)
{
    // THIS IS TO MAKE SURE WE KNOW WHICH TYPE OF SOLDIER WE ARE CREATING
    this->unitName = unitName;
    this->amountOfSoldiersPerUnit++;
}

Soldiers::~Soldiers()
{
    std::cout << "Soldiers destructor" << std::endl;
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

bool Soldiers::takeDamage(int i)
{
    if (getDefensePerSoldier() > 0)
    {
        int damageAfterDefense = i - getDefensePerSoldier();
        if (damageAfterDefense > 0)
        {
            this->defencePerSoldier = 0;
            this->healthPerSoldier -= damageAfterDefense;
        }
        else
        {
            this->defencePerSoldier -= i;
        }
        std::cout << defencePerSoldier << " after defense reduction.\n";
        std::cout << healthPerSoldier << " after health reduction.\n";
        return true;
    }
    else if (getHealthPerSoldier() > 0)
    {
        this->healthPerSoldier -= i;
        std::cout << healthPerSoldier << " after health reduction.\n";
        return true;
    }
    else
    {
        return false;
    }

    // if (defencePerSoldier > 0)
    // {
    //     int damageAfterDefense = i - defencePerSoldier;
    //     if (damageAfterDefense > 0)
    //     {
    //         defencePerSoldier = 0;
    //         healthPerSoldier -= damageAfterDefense;
    //     }
    //     else
    //     {
    //         defencePerSoldier -= i;
    //     }
    //     std::cout << defencePerSoldier << " after defense reduction.\n";
    //     std::cout << healthPerSoldier << " after health reduction.\n";
    //     return true;
    // }
    // else if (healthPerSoldier > 0)
    // {
    //     healthPerSoldier -= i;
    //     std::cout << healthPerSoldier << " after health reduction.\n";
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
}
