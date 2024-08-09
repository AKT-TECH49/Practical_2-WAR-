#include "Infantry.h"
int Infantry::totalInfantry = 0;

Infantry::Infantry(int damagePerSoldier, int defensePerSoldier) : Soldiers("Infantry")
{
    totalInfantry++;
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
    // prepare method to be implemented
    std::cout << "Infantry is preparing to fight." << std::endl;
    std::map<int, std::pair<std::string, std::string>> units;
    for (int i = 0; i < 10; i++) // example unit count
    {
        units[i] = std::make_pair("Infantry Soldier " + std::to_string(i + 1), "Shieldbear Soldier " + std::to_string(i + 1));
        std::cout << units[i].first << " and " << units[i].second << " arrived at the battlefield." << std::endl;
    }
    std::cout << "Transportation completed." << std::endl;

    // 2
    std::cout << "Loading Equipment onto boats..." << std::endl;
    std::vector<std::string> equipment = {"Weapons", "Shields", "Medical Supplies", "Rations"};
    std::map<int, std::vector<std::string>> boatEquipment;
    for (int i = 0; i < 10; i++)
    {
        boatEquipment[i] = equipment;
        std::cout << "Boat " << i + 1 << " loaded with equipment." << std::endl;
    }
    std::cout << "Equipment loading completed." << std::endl;

    // 3
    // position?
    std::string position = "Pacific ocean";
    // How can we possibly have a way for the Infantry to position himself?Using the graph class?
    // std::cout << "Positioned Infantry at: " << position << std::endl;
    // Using the Map class for positioning
    // Map battlefieldMap;
    // battlefieldMap.initializeMapFromSVG(/*add path to map.svg*/);

    // 4
    // check that there is no repairs of boats or equipment needed:
    std::cout << "Checking and repairing boats and equipment..." << std::endl;
    std::list<std::string> repairList = {"Infantry1", "Infantry3", "Infantry7"};                                                                           // How can we capture the boats???
    std::map<std::string, int> Infantry = {{"Infantry1", 30}, {"Infantry2", 60}, {"Infantry3", 20}, {"Infantry4", 50}, {"Infantry9", 90}, {"Infantry10", 55}}; // has to be dynamic how can we modify it?

    // 5
    // signal communications or radio using flags and a list or vector or map to allow communication between Infantry:
    std::cout << "Setting up communication channels..." << std::endl;
    std::map<int, std::string> communications;
    for (int i = 0; i < 10 /*amountOfSoldiersPerUnit?*/; i++)
    {
        communications[i] = "Channel " + std::to_string(i + 1);
        std::cout << "Boat " << i + 1 << " communicating on " << communications[i] << "." << std::endl;
    }
    std::cout << "Communications setup completed." << std::endl;

    std::cout << "Infantry is ready for battle." << std::endl;
}

void Infantry::execute()
{
    // execute method to be implemented
}

void Infantry::retreat()
{
    // retreat method to be implemented
}

void Infantry::rest()
{
    // rest method to be implemented
}
