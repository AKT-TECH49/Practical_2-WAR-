#include "Memento.h"
#include "State.h"



Memento::Memento(const State& state) : state(state) {}

State Memento::getState() const {
    return state;
}

