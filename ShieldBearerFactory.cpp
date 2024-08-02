#include "ShieldBearerFactory.h"


Soldiers * ShieldBearerFactory::createUnit()
{
    return new ShieldBearer(50,100);
}
