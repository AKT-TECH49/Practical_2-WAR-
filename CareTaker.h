#ifndef CARETAKER_H
#define CARETAKER_H

#include <list>
#include <vector>
#include <iostream>

#include "Memento.h"

class Memento ;

class CareTaker 
{
    private:
      std::vector<Memento*> mementos;


    public:
    void addMemento( Memento* memento);
    Memento* getMemento(int index);

};







#endif //CARETAKER_H