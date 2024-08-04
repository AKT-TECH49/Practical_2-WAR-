#include "CareTaker.h"

void CareTaker::addMemento( Memento* memento)
{
    //copy then each memento manually since we dont have a copy construtor use "new" DEEP COPY
    Memento* copy = memento->clone();
    //STORE COPIED DATA
    mementos.push_back(copy);

    //When popping a memento, we return a copy of the top memento (if available).
    //This ensures the original memento is not changed by the CareTaker.
    //pop() code and check conditions:
    if (mementos.size() > 0) {
        Memento* topMemento = mementos.back();
        mementos.pop_back();
        delete topMemento;
    }


return;

}

Memento *CareTaker::getMemento(int index)
{
    if(index < 0 || index >= mementos.size()) {
        std::cerr << "Invalid index" << std::endl;
        return nullptr;
    }  else {
        return mementos[index]->clone();  //return a copy of the memento at the given index.
    }
}
