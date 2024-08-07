#include <iostream>
#include "SoldierFactory.h"
#include "Soldiers.h"
#include "ShieldBearer.h"
#include "ShieldBearerFactory.h"
#include "Infantry.h"
#include "InfantryFactory.h"
#include "Boatman.h"
#include "BoatmanFactory.h"



void TestShieldBearer();
void TestInfantry();



int main()
{
     //TestShieldBearer();
     TestInfantry();


    return 0 ;


}

void printPattern(const std::string &pattern, const std::string &color)
{
    std::cout << color << pattern << "\033[0m" << std::endl;
}

void TestShieldBearer()
{
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[34m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "============================================";



    //TESTING USING SHIELDBEARER:
    ShieldBearerFactory shieldFactoty;
    Soldiers * shieldUnit = shieldFactoty.createUnit();
    Soldiers* shieldUnit2 = shieldUnit->clonis();//copy


   
    printPattern(pattern, red);
    std::cout << red << "Engaging the first ShieldBearer unit:" << reset << std::endl;
    shieldUnit->engage();

    // Display current state
    std::cout << green << "Current state of the first ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << shieldUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << shieldUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << shieldUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << shieldUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Create a memento of the current state
    Memento *savedState = shieldUnit->militusMemento();

    // Modify the unit's state
    std::cout << blue << "\nModifying the ShieldBearer unit's state..." << reset << std::endl;
    shieldUnit->disengage();

    // Display modified state
    std::cout << green << "Modified state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << shieldUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << shieldUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << shieldUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << shieldUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Restore the unit's state from the memento
    std::cout << blue << "\nRestoring the ShieldBearer unit's state from memento..." << reset << std::endl;
    shieldUnit->vivificaMemento(savedState);

    // Display restored state
    std::cout << green << "Restored state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << shieldUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << shieldUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << shieldUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << shieldUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);

    std::cout << red << "Engaging the second ShieldBearer unit:" << reset << std::endl;
    shieldUnit2->engage();

    // Display current state of the second unit
    std::cout << green << "Current state of the second ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << shieldUnit2->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << shieldUnit2->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << shieldUnit2->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << shieldUnit2->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);
    // Clean up
    // delete shieldUnit;
    // delete savedState;
}



void TestInfantry()
{
    
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[34m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "============================================";


    InfantryFactory  infantryFactory;
    Soldiers * infantryUnit = infantryFactory.createUnit();
    Soldiers* infantryUnit2 = infantryUnit->clonis();//copy
    Soldiers* infantryUnit3 = infantryFactory.createUnit();

    infantryUnit3->engage();
   
    printPattern(pattern, red);
    std::cout << red << "Engaging the first Infantry unit:" << reset << std::endl;
    infantryUnit->engage();

    // Display current state
    std::cout << green << "Current state of the Infantry unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Create a memento of the current state
    Memento *savedState = infantryUnit->militusMemento();

    // Modify the unit's state
    std::cout << blue << "\nModifying the ShieldBearer unit's state..." << reset << std::endl;
    infantryUnit->disengage();

    // Display modified state
    std::cout << green << "Modified state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Restore the unit's state from the memento
    std::cout << blue << "\nRestoring the ShieldBearer unit's state from memento..." << reset << std::endl;
    infantryUnit->vivificaMemento(savedState);

    // Display restored state
    std::cout << green << "Restored state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);

    std::cout << red << "Engaging the second Infantry unit:" << reset << std::endl;
    infantryUnit2->engage();

    // Display current state of the second unit
    std::cout << green << "Current state of the second Infantry unit:" << reset << std::endl;
    std::cout << yellow << "Health per soldier: " << reset << infantryUnit2->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage per soldier: " << reset << infantryUnit2->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense per soldier: " << reset << infantryUnit2->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Amount of soldiers per unit: " << reset << infantryUnit2->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);
    // Clean up
    // delete shieldUnit;
    // delete savedState;
}