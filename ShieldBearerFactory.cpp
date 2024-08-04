#include "ShieldBearerFactory.h"


Soldiers * ShieldBearerFactory::createUnit()
{
    return new ShieldBearer(50,100);
}

int ShieldBearerFactory::calculateTotalHealthPerUnit()
{
    int sum = 0;
    sum += createUnit()->getHealth();
    return sum;
}

int ShieldBearerFactory::calculateTotalDamagePerUnit()
{
    return 0;
}


int ShieldBearerFactory::calculateTotalDefencePerUnit()
{
    return 0;
}
