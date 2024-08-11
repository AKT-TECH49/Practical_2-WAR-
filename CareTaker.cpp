#include "CareTaker.h"

CareTaker::CareTaker()
{}

void CareTaker::addMemento(Memento *memento)
{
  mementos.push_back(memento); 
}

Memento *CareTaker::getMemento()
{
    if (!mementos.empty())
    {
        Memento* memento = mementos.back();
        mementos.pop_back();
        return memento;
    }

    return NULL;
}

CareTaker::~CareTaker()
{
  for (Memento* memento : mementos) {
        delete memento;
    }
}
