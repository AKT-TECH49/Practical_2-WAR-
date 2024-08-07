#include "CareTaker.h"

void CareTaker::addMemento( Memento* memento)
{
    mementos.push_back(memento);  //store a copy of the memento in the CareTaker
}

Memento *CareTaker::getMemento(int index)
{
    //get index
    return mementos.at(index);

}

CareTaker::~CareTaker()
{
   for(auto memento: mementos)\
   {
     delete memento;  //deallocate the memory allocated by each Memento
   }
}
