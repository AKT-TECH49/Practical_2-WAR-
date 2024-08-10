#include "CareTaker.h"

CareTaker::CareTaker()
{
}

void CareTaker::addMemento(Memento *memento)
{
  mementos.push_back(memento); // store a copy of the memento in the CareTaker
}

Memento *CareTaker::getMemento()
{
  Memento* m = mementos.front();

  mementos.erase(mementos.begin()); //pop off memento vector


  return m;
}

CareTaker::~CareTaker()
{
  for (auto memento : mementos)
  {
    delete memento; // deallocate the memory allocated by each Memento
  }
}
