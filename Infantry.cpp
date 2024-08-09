#include "Infantry.h"
#include "ShieldBearer.h" 
#include "Boatman.h"



int Infantry::totalInfantry = 0;

Infantry::Infantry(int damagePerSoldier, int defensePerSoldier) : Soldiers("Infantry" , 0)
{
    totalInfantry++;
    this->healthPerSoldier = 100;
    this->amountOfSoldiersPerUnit = totalInfantry;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
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

int Infantry::getDamagePerSoldier() const
{
    return this->damagePerSoldier;
}

int Infantry::getDefensePerSoldier() const
{
    return this->defensePerSoldier;
}

int Infantry::getAmountOfSoldiersPerUnit() const
{
    return this->amountOfSoldiersPerUnit;
}

int Infantry::calculateRepairAmount(int currentHealth)
{
    // calculate the amount of health needed to reach 100
    return 100 - currentHealth;
    // so we know to add what ever we have left to return to totalHealth of 100
}

void Infantry::prepare()
{
    std::cout << "Infantry unit is preparing for battle." << std::endl;

    // Simulating equipment checks and formation setup
    std::vector<std::string> equipment = {"Rifles", "Ammunition", "Grenades", "Medical Kits"};
    std::cout << "Checking and distributing equipment:" << std::endl;
    for (const auto &item : equipment)
    {
        std::cout << " - " << item << " checked and ready." << std::endl;
    }

    std::cout << "Setting up defensive positions and scouting enemy locations." << std::endl;
    std::map<std::string, std::string> positions = {
        {"Alpha", "Frontline"}, {"Bravo", "Left flank"}, {"Charlie", "Right flank"}, {"Delta", "Reserve"}};
    for (const auto &position : positions)
    {
        std::cout << position.first << " team positioned at " << position.second << "." << std::endl;
    }

    // Simulating morale boost
    std::cout << "Boosting morale with a motivational speech." << std::endl;
    std::cout << "\"Remember, each one of us plays a crucial role. Stay sharp, stay focused, and we will succeed!\"" << std::endl;
}

void Infantry::execute()
{
    std::cout << "Infantry unit is executing battle plans." << std::endl;

    // Coordinated attack
    std::cout << "Launching coordinated assault on enemy positions." << std::endl;
    std::vector<std::string> attackPhases = {"Suppressive fire", "Flanking maneuver", "Close-quarters combat"};
    for (const auto &phase : attackPhases)
    {
        std::cout << " - " << phase << " initiated." << std::endl;
    }

    // Simulating battlefield communication
    std::cout << "Communicating with command and allied units for support." << std::endl;
    std::map<std::string, std::string> communications = {
        {"HQ", "Requesting artillery support"}, {"Alpha", "Holding position"}, {"Bravo", "Advancing"}, {"Charlie", "Under heavy fire"}};
    for (const auto &communication : communications)
    {
        std::cout << " - " << communication.first << ": " << communication.second << "." << std::endl;
    }

    // Simulating dynamic adjustments
    std::cout << "Adjusting tactics based on battlefield conditions." << std::endl;
    std::cout << " - Enemy flanking detected, repositioning units to counter." << std::endl;
}

void Infantry::retreat()
{
    std::cout << "Infantry unit is retreating to a safer position." << std::endl;

    // Simulating retreat tactics
    std::vector<std::string> retreatPhases = {"Smoke grenades deployed", "Falling back under cover fire", "Regrouping at fallback position"};
    for (const auto &phase : retreatPhases)
    {
        std::cout << " - " << phase << " executed." << std::endl;
    }

    // Assessing casualties and regrouping
    std::cout << "Assessing casualties and regrouping units." << std::endl;
    int casualties = rand() % 10; // Simulating random casualty count
    std::cout << " - " << casualties << " soldiers lost. Regrouping remaining units." << std::endl;
}

void Infantry::rest()
{
    std::cout << "Infantry unit is resting and recuperating." << std::endl;

    // Simulating health recovery
    int recoveryAmount = 20;
    healthPerSoldier += recoveryAmount;
    if (healthPerSoldier > 100)
    {
        healthPerSoldier = 100;
    }
    std::cout << " - Soldiers' health increased by " << recoveryAmount << " points. Current health: " << healthPerSoldier << "." << std::endl;

    // Simulating morale boost and maintenance
    std::cout << "Boosting morale and performing equipment maintenance." << std::endl;
    std::vector<std::string> maintenanceTasks = {"Cleaning weapons", "Replenishing supplies", "Medical checkups"};
    for (const auto &task : maintenanceTasks)
    {
        std::cout << " - " << task << " completed." << std::endl;
    }
}


void Infantry::Attack(Soldiers *shieldy)
{
    if(!shieldy || !shieldy->isAlive() )
    {
        std::cout << "ShieldBearer is not alive. Boatman cannot attack." << std::endl;
        return;
    }

    double attStr;
    attStr = damagePerSoldier / 2 ;  // per punch 
    shieldy->takeDamage(attStr);

}

// void Infantry::Attack(Infantry* infantry)
// {
//     if(!infantry || !infantry->isAlive() )
//     {
//         std::cout << "Infantry is not alive. Boatman cannot attack." << std::endl;
//         return;
//     }

//     double attStr;
//     attStr = damagePerSoldier * 0.5 ;  // per punch 
//     infantry->takeDamage(attStr);
// }

// void Infantry::Attack(Boatman* boatman)
// {
//     if(!boatman || !boatman->isAlive() )
//     {
//         std::cout << "Boatman is not alive. Boatman cannot attack." << std::endl;
//         return;
//     }
//     double attStr;
//     attStr = damagePerSoldier /2 ;  // per punch
//     boatman->takeDamage(attStr);

// }

bool Infantry::isAlive()
{
    if(this->healthPerSoldier >0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
