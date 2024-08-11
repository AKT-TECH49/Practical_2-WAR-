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
void testCareTaker();
void testCalculateFunctions();

int main()
{
     TestShieldBearer();
     TestInfantry();
     TestBoatman();
     testCareTaker();
     TestAttacks();
     testCalculateFunctions();


    return 0;
}

void printPattern(const std::string &pattern, const std::string &color)
{
    std::cout << color << pattern << "\033[0m" << std::endl;
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

      std::cout<<"See the total amount: "<<boatmanFactory.calculateTotalDamagePerUnit()<<std::endl;
      std::cout<<"See total boatmen: "<<boatmanFactory.calculateTotalNumOfUnits()<<std::endl;

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

    //clean memory

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
    ShieldBearerFactory shieldBearerFactory ;

    Soldiers *infantryUnit = infantryFactory.createUnit();
    Soldiers *boatmanUnit = boatManFactoty.createUnit();
    Soldiers* shieldBearer = shieldBearerFactory.createUnit();


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

    printPattern(pattern , blue);
    std::cout << yellow << "ShieldBearer unit:" << reset << std::endl;
    std::cout << green << "Current state ShieldBearer unit:" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;


    std::cout<<"\n";


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

void testCalculateFunctions() {
    //InfantryFactory infantryFactory;
    // ShieldBearerFactory shieldBearerFactory;
    BoatmanFactory boatmanFactory;

    cout << endl;

    // Soldiers* infantry = infantryFactory.createUnit();
    // Soldiers* shieldBearer = shieldBearerFactory.createUnit();
    Soldiers* boatman = boatmanFactory.createUnit();
    std::cout<<"Boatman Data: "<<std::endl;
    std::cout<<"Health: "<<boatman->getHealthPerSoldier()<<", Damage: "<<boatman->getDamagePerSoldier()<<", Defense: "<<boatman->getDefensePerSoldier()<<", Units: "<<boatman->getAmountOfSoldiersPerUnit()<<"\n";


    cout << endl;

    cout << "- Testing Calculate Functions from Factory Method:\n\n";

    // Test calculateTotalHealthPerUnit
    // cout << "Infantry Total Health: " << infantryFactory.calculateTotalHealthPerUnit() << '\n';
    // cout << "ShieldBearer Total Health: " << shieldBearerFactory.calculateTotalHealthPerUnit() << '\n';
    cout << "Boatman Total Health: " << boatmanFactory.calculateTotalHealthPerUnit() << '\n';

    cout << endl;

    // Test calculateTotalDamagePerUnit
    // cout << "Infantry Total Damage: " << infantryFactory.calculateTotalDamagePerUnit() << '\n';
    // cout << "ShieldBearer Total Damage: " << shieldBearerFactory.calculateTotalDamagePerUnit() << '\n';
    cout << "Boatman Total Damage: " << boatmanFactory.calculateTotalDamagePerUnit() << '\n';

    cout << endl;

    // Test calculateTotalDefencePerUnit
    //cout << "Infantry Total Defence: " << infantryFactory.calculateTotalDefencePerUnit() << '\n';
    // cout << "ShieldBearer Total Defence: " << shieldBearerFactory.calculateTotalDefencePerUnit() << '\n';
    cout << "Boatman Total Defence: " << boatmanFactory.calculateTotalDefencePerUnit() << '\n';
    
    cout << endl;

    cout<<"Boatman Total units: "<<boatmanFactory.calculateTotalNumOfUnits()<<"\n";

    //delete memory
 
}

void testCareTaker() {

    const std::string red = "\033[91m";
    const std::string green = "\033[92m";
    const std::string yellow = "\033[93m";
    const std::string blue = "\033[34m";
    const std::string purple = "\033[35m";
    const std::string reset = "\033[0m";
    const std::string pattern = "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*";


    CareTaker care;
    InfantryFactory infantryFactory;
    BoatmanFactory boatManFactoty;

    Soldiers *infantryUnit = infantryFactory.createUnit();
    Soldiers *boatmanUnit = boatManFactoty.createUnit();


    printPattern(pattern, red);
    std::cout << red << " Infantry  unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);


    std::cout << green << "Save state after attack(infantry)" << std::endl;
    printPattern(pattern, yellow);

    //create and add to caretaker for infantry
    care.addMemento(infantryUnit->militusMemento());

    //restore:
      printPattern(pattern , yellow);
    std::cout<<"Original state gottenr(restored):  "<<std::endl;
    infantryUnit->vivificaMemento(care.getMemento());
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern , yellow);

    //modify state
    std::cout << red << "Infantry unit after its attacked by Boatman unit:" << reset << std::endl;
    boatmanUnit->Attack(infantryUnit);
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);
   //restore
    std::cout << green << "Infantry's previous state" << reset <<std::endl;
    care.addMemento(infantryUnit->militusMemento());

    infantryUnit->vivificaMemento(care.getMemento());
    std::cout << purple << "Health of soldier: " << reset << infantryUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << infantryUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << infantryUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << infantryUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern , yellow);


    std::cout << green << "Save state before attack(boatman)" << std::endl;
    printPattern(pattern, blue);

    //create and add to caretaker for boatman
     printPattern(pattern, red);
    std::cout << red << "Boatman  unit state before attack :" << reset << std::endl;
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);
    Memento* savedState = boatmanUnit->militusMemento();
    care.addMemento(savedState);


    //modify state
    std::cout << red << "Boatman unit after its attacked by Infantry unit:" << reset << std::endl;
    infantryUnit->Attack(boatmanUnit);
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, red);

    //restore
    std::cout << green << "Boatman's original state: "<<reset<<std::endl;
    boatmanUnit->vivificaMemento(savedState);
    std::cout << purple << "Health of soldier: " << reset << boatmanUnit->getHealthPerSoldier() << std::endl;
    std::cout << purple << "Damage of soldier: " << reset << boatmanUnit->getDamagePerSoldier() << std::endl;
    std::cout << purple << "Defense of soldier: " << reset << boatmanUnit->getDefensePerSoldier() << std::endl;
    std::cout << purple << "Unit(s): " << reset << boatmanUnit->getAmountOfSoldiersPerUnit() << std::endl;
    printPattern(pattern, blue);


}
