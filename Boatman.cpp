#include "Boatman.h"
#include "ShieldBearer.h"
#include "Soldiers.h"
#include "Infantry.h"

#include <string>
#include <iostream>

int Boatman::amountOfSoldiersPerUnit = 0;

Boatman::Boatman(int damagePerSoldier, int defensePerSoldier) : Soldiers("BoatMan")
{
    this->amountOfSoldiersPerUnit ++;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
    this->healthPerSoldier = 100;
}

Soldiers *Boatman::clonis()
{
    Soldiers *clone = new Boatman(this->damagePerSoldier, this->defensePerSoldier);
    return clone;
}

int Boatman::getHealthPerSoldier() const
{
    return this->healthPerSoldier;
}

int Boatman::getDamagePerSoldier()
{
    return this->damagePerSoldier;
}

int Boatman::getDefensePerSoldier()
{
    return this->defensePerSoldier;
}

int Boatman::getAmountOfSoldiersPerUnit()
{
    return this->amountOfSoldiersPerUnit;
}

Boatman::~Boatman()
{
    delete this;
}

void Boatman::Attack(Soldiers &shieldy)
{

    if (!shieldy || !shieldy->isAlive())
    {
        std::cout << "Boatman is not alive,thus cannot attack." << std::endl;
        return;
    }

    double attStr, dmgNew;
    attStr = shieldy->getDamagePerSoldier() / 2.5; // per punch
    dmgNew = shieldy->getDamagePerSoldier() / 2;

    shieldy->setHealthPerSoldier(attStr);
    shieldy->setDefensePerSoldier(dmgNew);

    std::cout << "Damage of enemy: " << shieldy->getDamagePerSoldier() << "\n";
    std::cout << "Health of soldier : " << shieldy->getHealthPerSoldier() << "\n";
    std::cout << "Defense of soldier : " << shieldy->getDefensePerSoldier() << "\n";
    std::cout << "\n";
}

// settter
void Boatman::setHealthPerSoldier(int i)
{
    this->healthPerSoldier = this->healthPerSoldier - i;
}

void Boatman::setDamagePerSoldier(int i)
{
    this->damagePerSoldier = i;
}

void Boatman::setDefensePerSoldier(int i)
{
    this->defensePerSoldier -= i;
}

void Boatman::setAmountOfSoldiersPerUnit(int i)
{
    this->amountOfSoldiersPerUnit = i;
}

void Boatman::subByOne()
{
    this->amountOfSoldiersPerUnit--;
}
bool Boatman::isAlive()
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

void Boatman::prepare()
{
    std::cout << "Boatman is preparing to fight." << std::endl;

    // 1. Transporting Infantry and Shieldbearers
    std::cout << "Transporting Infantry and Shieldbearers:" << std::endl;
    std::map<int, std::pair<std::string, std::string>> units;
    for (int i = 0; i < 10; i++) // example unit count
    {
        units[i] = std::make_pair("Infantry Soldier " + std::to_string(i + 1), "Shieldbear Soldier " + std::to_string(i + 1));
        std::cout << "\t- " << units[i].first << " and " << units[i].second << " arrived at the battlefield." << std::endl;
    }
    std::cout << "Transportation completed." << std::endl;

    // 2. Loading Equipment onto boats
    std::cout << "Loading Equipment onto boats:" << std::endl;
    std::vector<std::string> equipment = {"Weapons", "Shields", "Medical Supplies", "Rations"};
    std::map<int, std::vector<std::string>> boatEquipment;
    for (int i = 0; i < 10; i++)
    {
        boatEquipment[i] = equipment;
        std::cout << "\t- Boat " << i + 1 << " loaded with equipment." << std::endl;
    }
    std::cout << "Equipment loading completed." << std::endl;

    // 3. Checking and repairing boats and equipment
    std::cout << "Checking and repairing boats and equipment:" << std::endl;
    std::list<std::string> repairList = {"Boatman1", "Boatman3", "Boatman7"};
    std::map<std::string, int> boatman = {{"Boatman1", 30}, {"Boatman2", 60}, {"Boatman3", 20}, {"Boatman4", 50}, {"Boatman9", 90}, {"Boatman10", 55}};
    for (const auto &boat : repairList)
    {
        if (boatman[boat] < 40)
        {
            std::cout << "\t- Repairing " << boat << " (Health: " << boatman[boat] << ")." << std::endl;
            boatman[boat] += calculateRepairAmount(boatman[boat]);
            if (boatman[boat] > 100)
            {
                throw std::runtime_error("Boatman's health cannot exceed 100.");
            }
            std::cout << boat << " repaired to full health." << std::endl;
        }
        else
        {
            std::cout << "\t- " << boat << " does not need repairs (Health: " << boatman[boat] << ")." << std::endl;
        }
    }
    std::cout << "Repairs completed." << std::endl;

    // 4. Setting up communication channels
    std::cout << "Setting up communication channels:" << std::endl;
    std::map<int, std::string> communications;
    for (int i = 0; i < 10; i++)
    {
        communications[i] = "Channel " + std::to_string(i + 1);
        std::cout << "\t- Boat " << i + 1 << " communicating on " << communications[i] << "." << std::endl;
    }
    std::cout << "Communications setup completed." << std::endl;

    std::cout << "Boatman is ready for battle." << std::endl;
}

int Boatman::calculateRepairAmount(int currentHealth)
{
    // calculate the amount of health needed to reach 100
    return 100 - currentHealth;
    // so we know to add what ever we have left to return to totalHealth of 100
}

void Boatman::execute()
{
    // I'm thinking that the boatMan can also be more invloved we can allow them to deploy bombs to the enemy at sea
    //  and also use their position to help them with their battle plans
    //  but I'm not sure how to implement this without creating additional classes for each action
    //  and also how to allow them to deploy bombs without creating additional classes for each bomb
    //  and also how to handle the communication between boatmen without creating additional classes for each communication
    //  and also how to handle the retreat without creating additional classes for each retreat
    //  and also how to handle the rest without creating additional classes for each rest
    std::cout << "Boatman is executing battle plans." << std::endl;

    // Deploying bombs to the enemy at sea
    std::cout << "Deploying bombs to enemy positions." << std::endl;
    std::map<int, std::pair<std::string, int>> bombDeployment; // <Boat ID, <Target Area, Bomb Count>>
    for (int i = 0; i < 5; i++)                                // example bomb deployment count
    {
        bombDeployment[i] = std::make_pair("Enemy Ship " + std::to_string(i + 1), 3); // Each boat deploys 3 bombs
        std::cout << "\t- Boat " << i + 1 << " deployed 3 bombs to " << bombDeployment[i].first << "." << std::endl;
    }
    std::cout << "Bomb deployment completed." << std::endl;

    // Using positions for strategic advantage
    std::cout << "Utilizing strategic positions for advantage." << std::endl;
    std::map<int, std::string> strategicPositions; // <Boat ID, Position>
    for (int i = 0; i < 10; i++)
    {
        strategicPositions[i] = "Position " + std::to_string(i + 1);
        std::cout << "\t- Boat " << i + 1 << " at " << strategicPositions[i] << " providing cover fire." << std::endl;
    }
    std::cout << "Strategic positioning completed." << std::endl;

    // Coordinating attacks with communication channels
    std::cout << "Coordinating attacks via communication channels." << std::endl;
    std::map<int, std::string> attackCoordination; // <Boat ID, Target Area>
    for (int i = 0; i < 10; i++)
    {
        attackCoordination[i] = "Target Area " + std::to_string(i + 1);
        std::cout << "\t- Boat " << i + 1 << " attacking " << attackCoordination[i] << " as per communication channel." << std::endl;
    }
    std::cout << "Attack coordination completed." << std::endl;

    // Signaling for support and reinforcements
    std::cout << "Signaling for support and reinforcements." << std::endl;
    std::map<int, std::string> supportSignals; // <Boat ID, Signal Type>
    for (int i = 0; i < 5; i++)
    {
        supportSignals[i] = "Reinforcement Signal " + std::to_string(i + 1);
        std::cout << "\t- Boat " << i + 1 << " sending " << supportSignals[i] << " for additional support." << std::endl;
    }
    std::cout << "Support signaling completed." << std::endl;

    std::cout << "Boatman has executed all battle plans." << std::endl;
}

void Boatman::retreat()
{
    std::cout << "Boatman is retreating." << std::endl;

}

void Boatman::rest()
{   // recharge health
    this->healthPerSoldier += 10;
    std::cout << "Boatman is resting." << std::endl;
}
