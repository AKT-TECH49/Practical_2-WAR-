#include "Soldiers.h"

Soldiers::Soldiers(std::string unitName)
{
    //THIS IS TO MAKE SURE WE KNOW WHICH TYPE OF SOLDIER WE ARE CREATING
    this->unitName= unitName;
    this->healthPerSoldier = 100;
}
