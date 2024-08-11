#include <iostream>
#include "SoldierFactory.h"
#include "Soldiers.h"
#include "ShieldBearer.h"
#include "ShieldBearerFactory.h"
#include "Infantry.h"
#include "InfantryFactory.h"
#include "Boatman.h"
#include "BoatmanFactory.h"
#include "Memento.h"
#include "CareTaker.h"

using namespace std;

void TestShieldBearer();
void TestInfantry();
void TestBoatman();
void TestAttacks();
void testCalculateFunctions();

void testFactoryMethod();
void testTemplateMethod();

void testMementoMethod();

void testPrototypeMethod();

int main()
{
    // TestShieldBearer();
    // TestInfantry();
    // TestBoatman();
    // TestAttacks();
    // testCalculateFunctions();
    // Designs Patterns
    testFactoryMethod();
    testTemplateMethod();
    testMementoMethod();
    testPrototypeMethod();

    return 0;
}

void printPattern(const std::string &pattern, const std::string &color)
{
    std::cout << color << pattern << "\033[0m" << std::endl;
}

void testFactoryMethod()
{
    // Create
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    std::cout << endl;

    Soldiers *infantry = infantryFactory.createUnit();
    Soldiers *shieldBearer = shieldBearerFactory.createUnit();
    Soldiers *boatman = boatmanFactory.createUnit();

    std::cout << endl;

    std::cout << "- Testing Calculate Functions from Factory Method:\n\n";

    // Test calculateTotalHealthPerUnit
    std::cout << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << '\n';
    std::cout << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << '\n';
    std::cout << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n';

    std::cout << endl;

    // Test calculateTotalDamagePerUnit
    std::cout << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n';

    std::cout << endl;

    // Test calculateTotalDefencePerUnit
    std::cout << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n';

    std::cout << endl;

    std::cout << "Boatman Total units: " << boatmanFactory.calculateTotalNumOfUnits() << "\n";
    std::cout << "ShieldBearer Total units: " << shieldBearerFactory.calculateToTalNumUnits() << "\n";
    std::cout << "Infantry Total units: " << infantryFactory.calculateTotalNumOfUnits() << "\n";
}

void testTemplateMethod()
{
    // engage and disengage
    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[34m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_";

    InfantryFactory factory1;
    BoatmanFactory factory2;
    ShieldBearerFactory factory3;

    Soldiers *shieldy = factory3.createUnit();
    Soldiers *boaty = factory2.createUnit();
    Soldiers *fantry = factory1.createUnit();

    std::cout << yellow << " INFANTRY IS ENGAGING: " << std::endl;
    fantry->engage();
    printPattern(pattern, blue);
    std::cout << yellow << "INFANTRY IS DISENGAGING: " << std::endl;
    fantry->disengage();
    printPattern(pattern, blue);

    std::cout << yellow << " BOATMAN IS ENGAGING: " << std::endl;
    boaty->engage();
    printPattern(pattern, yellow);
    std::cout << yellow << " BOATMAN IS DISENGAGING: " << std::endl;
    boaty->disengage();

    std::cout << yellow << " SHIELDBEARER IS ENGAGING: " << std::endl;
    shieldy->engage();
    printPattern(pattern, green);
    std::cout << yellow << "SHIELDBEARER IS DISENGAGING: " << std::endl;
    shieldy->disengage();
}

void testMementoMethod()
{
    const std::string red = "\033[91m";
    const std::string green = "\033[92m";
    const std::string yellow = "\033[93m";
    const std::string blue = "\033[34m";
    const std::string purple = "\033[35m";
    const std::string reset = "\033[0m";
    const std::string pattern = "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*";

    InfantryFactory inf;
    BoatmanFactory boat;
    ShieldBearerFactory shield;
    CareTaker care;

    Soldiers *shieldy = shield.createUnit();
    Soldiers *boaty = boat.createUnit();
    Soldiers *fantry = inf.createUnit();

    printPattern(pattern, red);
    std::cout << red << " Infantry  unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << fantry->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << fantry->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << fantry->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << fantry->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);

    printPattern(pattern, yellow);
    std::cout << red << "Boatman unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boaty->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, yellow);

    printPattern(pattern, green);
    std::cout << red << "ShieldBearer unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shieldy->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);

    Memento *saveB = boaty->militusMemento();
    care.addMemento(saveB);
    fantry->Attack(boaty);
    std::cout << yellow << "Boatman unit state after attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boaty->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);

    // restore:
    Memento *restB = care.getMemento();
    boaty->vivificaMemento(restB);
    std::cout << yellow << "Boatman unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boaty->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boaty->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boaty->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boaty->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);

    Memento *saveF = fantry->militusMemento();
    care.addMemento(saveF);
    fantry->vivificaMemento(care.getMemento());
    std::cout << yellow << "Infantry unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << fantry->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << fantry->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << fantry->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << fantry->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);

    Memento *saveS = shieldy->militusMemento();
    care.addMemento(saveS);
    boaty->Attack(shieldy);
    std::cout << yellow << "ShieldBearer unit state after attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shieldy->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    // restore:
    Memento *restS = care.getMemento();
    shieldy->vivificaMemento(restS);
    std::cout << yellow << "ShieldBearer unit state after restoration :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shieldy->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    // attack again
    fantry->Attack(shieldy);
    std::cout << blue << "ShieldBearer unit state after attack again :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldy->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldy->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shieldy->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldy->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, green);
    // attack again
}

void testPrototypeMethod()
{
    const std::string blue = "\033[96m";
    const std::string green = "\033[35m";
    const std::string purple = "\033[91m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.";

    ShieldBearerFactory sF;
    InfantryFactory iF;
    BoatmanFactory bF;

    Soldiers *shld = sF.createUnit();
    Soldiers *inf = iF.createUnit();
    Soldiers *btm = bF.createUnit();

    Soldiers *cloneShld = shld->clonis();
    Soldiers *cloneInf = inf->clonis();
    Soldiers *cloneBtm = btm->clonis();

    // display:
    std::cout << yellow << "Original ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shld->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shld->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shld->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shld->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneShld->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneShld->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneShld->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneShld->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);
    std::cout << yellow << "Original Infantry unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << inf->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << inf->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << inf->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << inf->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned Infantry unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneInf->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneInf->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneInf->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneInf->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);
    std::cout << yellow << "Original Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << btm->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << btm->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << btm->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << btm->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << yellow << "Cloned Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << cloneBtm->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << cloneBtm->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << cloneBtm->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << cloneBtm->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);
}

void TestShieldBearer()
{
    const std::string blue = "\033[96m";
    const std::string green = "\033[35m";
    const std::string cyan = "\033[91m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.";

    // TESTING USING SHIELDBEARER:
    ShieldBearerFactory shieldFactoty, shieldFactoty2;
    Soldiers *shieldUnit = shieldFactoty.createUnit();
    Soldiers *shieldUnit2 = shieldUnit->clonis(); // copy
    Soldiers *shieldUnit3 = shieldFactoty2.createUnit();

    printPattern(pattern, blue);
    std::cout << blue << "Engaging the first ShieldBearer unit:" << reset << std::endl;
    shieldUnit->engage();

    // Display current state
    std::cout << green << "Current state of the first ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << shieldUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << shieldUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << shieldUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << shieldUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, blue);

    // Modify the unit's state
    std::cout << blue << "Shieldbeaerer disengaging: " << reset << std::endl;
    shieldUnit->disengage();
    std::cout << green << "Modified state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << shieldUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << shieldUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << shieldUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << shieldUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);

    std::cout << blue << "Engaging the second ShieldBearer unit:" << reset << std::endl;
    shieldUnit2->engage();

    // Display current state of the second unit
    std::cout << green << "Current state of the second ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << shieldUnit2->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << shieldUnit2->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << shieldUnit2->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << shieldUnit2->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, blue);

    std::cout << blue << "Engaging the third ShieldBearer unit:" << reset << std::endl;
    shieldUnit3->engage();

    // Display current state of the third unit
    std::cout << green << "Current state of the third ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << shieldUnit3->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << shieldUnit3->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << shieldUnit3->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << shieldUnit3->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, blue);
}

void TestInfantry()
{

    const std::string red = "\033[31m";
    const std::string green = "\033[32m";
    const std::string blue = "\033[34m";
    const std::string yellow = "\033[33m";
    const std::string reset = "\033[0m";
    const std::string pattern = "============================================";

    InfantryFactory infantryFactory;
    Soldiers *infantryUnit = infantryFactory.createUnit();
    Soldiers *infantryUnit2 = infantryUnit->clonis(); // copy

    printPattern(pattern, red);
    std::cout << red << "Engaging the first Infantry unit:" << reset << std::endl;
    infantryUnit->engage();

    // Display current state
    std::cout << green << "Current state of the Infantry unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Modify the unit's state
    std::cout << blue << "\nInfantry disengaging: " << reset << std::endl;
    infantryUnit->disengage();
    printPattern(pattern, red);
    std::cout << green << "Modified state of the ShieldBearer unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);

    std::cout << red << "Engaging the second Infantry unit:" << reset << std::endl;
    infantryUnit2->engage();

    // Display current state of the second unit
    std::cout << green << "Current state of the second Infantry unit:" << reset << std::endl;
    std::cout << yellow << "Health of soldier: " << reset << infantryUnit2->getHealthPerSoldier() << std::endl;
    std::cout << yellow << "Damage of soldier: " << reset << infantryUnit2->getDamagePerSoldier() << std::endl;
    std::cout << yellow << "Defense of soldier: " << reset << infantryUnit2->getDefensePerSoldier() << std::endl;
    std::cout << yellow << "Units: " << reset << infantryUnit2->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);
}

void TestBoatman()
{

    /*COLORS*/
    const std::string yellow = "\033[93m";
    const std::string green = "\033[94m";
    const std::string blue = "\033[34m";
    const std::string purple = "\033[35m";
    const std::string reset = "\033[0m";
    const std::string pattern = "<><><><><><><><><><><><><><><><><><><><><><>";

    /*CREATE*/
    BoatmanFactory boatmanFactory;
    Soldiers *boatmanUnit = boatmanFactory.createUnit();
    Soldiers *boatmanUnit2 = boatmanUnit->clonis();
    Soldiers *boatmanUnit3 = boatmanFactory.createUnit();

    printPattern(pattern, yellow);

    std::cout << "See the total amount: " << boatmanFactory.calculateTotalDamagePerUnit() << std::endl;
    std::cout << "See total boatmen: " << boatmanFactory.calculateTotalNumOfUnits() << std::endl;

    printPattern(pattern, yellow);

    /*Unit 1*/
    printPattern(pattern, yellow);
    std::cout << yellow << "Engaging the first Boatman unit:" << reset << std::endl;
    boatmanUnit->engage();

    // Display current state
    std::cout << green << "Current state of the first Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Units: " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;

    // Modify the unit's state
    std::cout << blue << "\nBoatman disengaing: " << reset << std::endl;
    boatmanUnit->disengage();

    printPattern(pattern, yellow);
    // Display modified state
    std::cout << green << "Modified state of the Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Units: " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, yellow);
    std::cout << yellow << "Engaging the second Boatman unit:" << reset << std::endl;
    boatmanUnit2->engage();
    printPattern(pattern, yellow);

    std::cout << green << "Current state of the second Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit2->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit2->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit2->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Units: " << reset << boatmanUnit2->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, yellow);
    std::cout << yellow << "Engaging the third Boatman unit:" << reset << std::endl;
    boatmanUnit3->engage();
    printPattern(pattern, yellow);

    std::cout << green << "Current state of the third Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit3->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit3->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit3->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Units: " << reset << boatmanUnit3->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, yellow);

    // clean memory
}

void TestAttacks()
{
    const std::string red = "\033[91m";
    const std::string green = "\033[92m";
    const std::string yellow = "\033[93m";
    const std::string blue = "\033[34m";
    const std::string purple = "\033[35m";
    const std::string reset = "\033[0m";
    const std::string pattern = "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*";

    printPattern(pattern, green);

    InfantryFactory infantryFactory;
    BoatmanFactory boatManFactoty;
    ShieldBearerFactory shieldBearerFactory;

    Soldiers *infantryUnit = infantryFactory.createUnit();
    Soldiers *boatmanUnit = boatManFactoty.createUnit();
    Soldiers *shieldBearer = shieldBearerFactory.createUnit();

    printPattern(pattern, yellow);
    std::cout << yellow << "Infantry unit:" << reset << std::endl;
    std::cout << green << "Current state Infantry unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, green);
    std::cout << yellow << "Boatman unit:" << reset << std::endl;
    std::cout << green << "Current state Boatman unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, blue);
    std::cout << yellow << "ShieldBearer unit:" << reset << std::endl;
    std::cout << green << "Current state ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;

    std::cout << "\n";

    printPattern(pattern, red);
    std::cout << red << "Infantry unit attacks Boatman unit:" << reset << std::endl;
    infantryUnit->Attack(boatmanUnit);
    std::cout << green << "After attack, Boatman unit state:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);
    std::cout << red << "Boatman unit attacks Infantry unit:" << reset << std::endl;
    boatmanUnit->Attack(infantryUnit);
    std::cout << green << "After attack, Infantry unit state:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, red);
    std::cout << red << "Infantry unit attacks ShieldBearer unit:" << reset << std::endl;
    infantryUnit->Attack(shieldBearer);
    std::cout << green << "After attack,ShieldBearer unit state:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << shieldBearer->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << shieldBearer->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << shieldBearer->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << shieldBearer->getAmountOfSoldiersPerUnit() << std::endl;

    printPattern(pattern, yellow);
}

void testCalculateFunctions()
{
    // Create
    InfantryFactory infantryFactory;
    ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    std::cout << endl;

    Soldiers *infantry = infantryFactory.createUnit();
    Soldiers *shieldBearer = shieldBearerFactory.createUnit();
    Soldiers *boatman = boatmanFactory.createUnit();
    std::cout << endl;

    std::cout << "- Testing Calculate Functions from Factory Method:\n\n";

    // Test calculateTotalHealthPerUnit
    std::cout << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << '\n';
    std::cout << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << '\n';
    std::cout << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n';

    std::cout << endl;

    // Test calculateTotalDamagePerUnit
    std::cout << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << '\n';
    std::cout << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n';

    std::cout << endl;

    // Test calculateTotalDefencePerUnit
    std::cout << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << '\n';
    std::cout << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n';

    std::cout << endl;

    std::cout << "Boatman Total units: " << boatmanFactory.calculateTotalNumOfUnits() << "\n";
    std::cout << "ShieldBearer Total units: " << shieldBearerFactory.calculateToTalNumUnits() << "\n";
    std::cout << "Infantry Total units: " << infantryFactory.calculateTotalNumOfUnits() << "\n";
}
