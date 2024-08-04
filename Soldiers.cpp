#include "Soldiers.h"

Soldiers::Soldiers(std::string unitName)
{
    //THIS IS TO MAKE SURE WE KNOW WHICH TYPE OF SOLDIER WE ARE CREATING
    this->unitName= unitName;
    this->healthPerSoldier = 100;
}


void Soldiers::engage()
{
    //call prepare() and execute() methods
    prepare();
    execute();

}

void Soldiers::disengage()
{
    //call retreat() and rest() methods:
    retreat();
    rest();

}

Memento *Soldiers::militusMemento()
{
    Memento* m = new Memento();
    /*m->setState(this->state);*///private
    
    return m;
}

void Soldiers::vivificaMemento(Memento *memento)
{
   /* this->state = memento->getState();*/  //private
}
