#ifndef CARETAKER_H
#define CARETAKER_H

#include <list>
#include <vector>
#include <iostream>

#include "Memento.h"


class CareTaker 
{
    private:
      std::vector<Memento*> mementos;


    public:
    CareTaker() ;
    void addMemento( Memento* memento);
    Memento* getMemento(); 
    ~CareTaker();

};







#endif //CARETAKER_H