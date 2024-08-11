#ifndef MEMENTO_H
#define MEMENTO_H

#include "State.h"

class Memento
{

public:
    Memento(const State &state);
    State getState() const;

private:
    State state;
};

#endif // MEMENTO_H
