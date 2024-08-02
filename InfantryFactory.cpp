#include "Infantry.h"
#include "InfantryFactory.h"

Soldiers *InfantryFactory::createUnit()
{
    return new Infantry(100,80);
}