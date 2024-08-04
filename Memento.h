#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>

class Soldiers;
struct State
{
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit ;
};


class Memento {
public: //we want a function that returns a pointer to memento i.e) clone function
Memento* clone() const;//gets state
    Memento();



    private:
    //store current state of soldiers
    int healthPerSoldier;
    int damagePerSoldier;
    int defencePerSoldier;
    int amountOfSoldiersPerUnit ;
    std::string unitName;
    State state;
    State getState();
    void setState(State s);
    void setAtState(int index);
    Memento(int value1 , int value2 , int value3,int value4 , std::string value5);



};

#endif //MEMENTO_H