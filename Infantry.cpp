#include "Infantry.h"
#include "ShieldBearer.h"
#include "Boatman.h"



int Infantry::amountOfSoldiersPerUnit = 0;

Infantry::Infantry(int damagePerSoldier, int defensePerSoldier) : Soldiers("Infantry")
{
    this->healthPerSoldier = 100;
    this->amountOfSoldiersPerUnit ++;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
}

Infantry::~Infantry()
{
    delete this;
}

Soldiers *Infantry::clonis()
{
    // clone once
    Soldiers *clone = new Infantry(this->damagePerSoldier, this->defensePerSoldier);
    return clone;
}

int Infantry::getHealthPerSoldier() const
{
    return this->healthPerSoldier;
}

int Infantry::getDamagePerSoldier()
{
    return this->damagePerSoldier;
}

int Infantry::getDefensePerSoldier()
{
    return this->defensePerSoldier;
}

int Infantry::getAmountOfSoldiersPerUnit()
{
    return this->amountOfSoldiersPerUnit;
}

int Infantry::calculateRepairAmount(int currentHealth)
{
    // calculate the amount of health needed to reach 100
    return 100 - currentHealth;
    // so we know to add what ever we have left to return to totalHealth of 100
}

void Infantry::subByOne()
{
   this-> amountOfSoldiersPerUnit--;
}

void Infantry::prepare()
{
    std::cout << "IFANTRY preparing for battle." << std::endl;

    //1
    std::vector<std::string> equipment = {"Rifles", "Ammunition", "Grenades", "Medical Kits"};
    std::cout << "Checking and distributing equipment:" << std::endl;
    for (const auto &item : equipment)
    {
        std::cout << " - " << item << " checked and ready." << std::endl;
    }
    //2
    std::cout << "Setting up defensive positions and scouting enemy locations." << std::endl;
    std::map<std::string, std::string> positions = {
        {"Alpha", "Frontline"}, {"Bravo", "Left flank"}, {"Charlie", "Right flank"}, {"Delta", "Reserve"}};
    for (const auto &position : positions)
    {
        std::cout << position.first << " team positioned at " << position.second << "." << std::endl;
    }
//FUN
    std::cout << "CAPTAIN SPEECH: " << std::endl;
    std::cout <<"\t" << "\"Remember, each one of us plays a crucial role. Stay sharp, stay focused, and YOU WILL BE A HERO TO MANY PEOPLE OUT THERE!\"" << std::endl;
}

void Infantry::execute()
{
    std::cout << "INFANTRY EXECUTING:  " << std::endl;

    //1
    std::cout << "Launching coordinated assault on enemy positions." << std::endl;
    std::vector<std::string> attackPhases = {"Suppressive fire", "Flanking maneuver", "Close-quarters combat"};
    for (const auto &phase : attackPhases)
    {
        std::cout << " - " << phase << " initiated." << std::endl;
    }

    // 2
    std::cout << "Communicating with command and allied units for support." << std::endl;
    std::map<std::string, std::string> communications = {
     {"HQ", "Requesting artillery support"}, {"Alpha", "Holding position"}, {"Bravo", "Advancing"}, {"Charlie", "Under heavy fire"}};
    for (const auto &communication : communications)
    {
        std::cout << " - " << communication.first << ": " << communication.second << "." << std::endl;
    }

    // 3
    std::cout << " - Enemy flanking detected, repositioning units to counter." << std::endl;
}

void Infantry::retreat()
{
    std::cout << "INFANTRY RETREATING: " << std::endl;

    //1
    std::vector<std::string> retreatPhases = {"Smoke grenades deployed", "Falling back under cover fire", "Regrouping at fallback position"};
    for (const auto &phase : retreatPhases)
    {
        std::cout << " - " << phase << " executed." << std::endl;
    }
    //2 
    std::cout << "Assessing casualties and regrouping units." << std::endl;
    int casualties = rand() % 10; //JUST RANDOM 
    std::cout << " - " << casualties << " soldiers lost. Regrouping remaining units." << std::endl;
}

void Infantry::rest()
{
    std::cout << "INFANTRY RESTING." << std::endl;
      healthPerSoldier+=20;
    if (healthPerSoldier > 100)
    {
        healthPerSoldier = 100;
    }
    std::cout << "performing equipment maintenance." << std::endl;
    std::vector<std::string> maintenanceTasks = {"Cleaning weapons", "Replenishing supplies", "Medical checkups"};
    for (const auto &task : maintenanceTasks)
    {
        std::cout << " - " << task << " completed." << std::endl;
    }
}

void Infantry::Attack(Soldiers *shieldy)
{
    if (!shieldy || !shieldy->isAlive())
    {
        std::cout << "Infantry is not alive ,thus cannot attack." << std::endl;
        return;
    }

    double attStr, dmgNew;
    attStr = shieldy->getDamagePerSoldier() / 2.5; // per punch
    dmgNew = shieldy->getDamagePerSoldier() / 2;

    shieldy->setHealthPerSoldier(attStr);
    shieldy->setDefensePerSoldier(dmgNew);
}

void Infantry::setHealthPerSoldier(int i)
{
    this->healthPerSoldier -= i;
}

void Infantry::setDamagePerSoldier(int i)
{
    this->damagePerSoldier = i;
}

void Infantry::setDefensePerSoldier(int i)
{
    this->defensePerSoldier = i;
}

void Infantry::setAmountOfSoldiersPerUnit(int i)
{
    this->amountOfSoldiersPerUnit = i;
}

bool Infantry::isAlive()
{
    if (this->healthPerSoldier > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
