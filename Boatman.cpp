#include "Boatman.h"
#include <string>
#include <iostream>

int Boatman::totalBoatmen = 0;

Boatman::Boatman(int damagePerSoldier, int defensePerSoldier) : Soldiers("BoatMan")
{
    totalBoatmen++;
    this->amountOfSoldiersPerUnit = totalBoatmen;
    this->damagePerSoldier = damagePerSoldier;
    this->defensePerSoldier = defensePerSoldier;
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

int Boatman::getDamagePerSoldier() const
{
    return this->damagePerSoldier;
}

int Boatman::getDefensePerSoldier() const
{
    return this->defensePerSoldier;
}

int Boatman::getAmountOfSoldiersPerUnit() const
{
    return this->amountOfSoldiersPerUnit;
}

Boatman::~Boatman()
{
    // totalBoatmen--;
    // delete this;
}

void Boatman::prepare()
{
    std::cout << "Boatman is preparing to fight." << std::endl;
    // How can we possibily have a way for the BoatMan to prepapre for battle?
    // store equipment or load equipment inside the boats?Or take the infantry and shieldbears soldiers to attack position?
    // This is a hypothetical scenario and may require further implementation.
    // In a realistic scenario, this would involve coordinating with other units, possibly even other factions, to prepare for the battle.
    std::cout << "Transporting Infantry and Shieldbearers: " << std::endl;
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
    // How can we possibly have a way for the BoatMan to position himself?Using the graph class?
    // std::cout << "Positioned boatman at: " << position << std::endl;
    // Using the Map class for positioning
    // Map battlefieldMap;
    // battlefieldMap.initializeMapFromSVG(/*add path to map.svg*/);

    // 4
    // check that there is no repairs of boats or equipment needed:
    std::cout << "Checking and repairing boats and equipment..." << std::endl;
    std::list<std::string> repairList = {"Boatman1", "Boatman3", "Boatman7"};                                                                           // How can we capture the boats???
    std::map<std::string, int> boatman = {{"Boatman1", 30}, {"Boatman2", 60}, {"Boatman3", 20}, {"Boatman4", 50}, {"Boatman9", 90}, {"Boatman10", 55}}; // has to be dynamic how can we modify it?
    for (const auto &boat : repairList)
    {
        if (boatman[boat] < 40)
        {
            std::cout << "Repairing " << boat << " (Health: " << boatman[boat] << ")." << std::endl;
            // lets calculate dynamically how much each boatman would need to get to 100
            boatman[boat] += calculateRepairAmount(boatman[boat]);
            if (boatman[boat] >= 100) // throw exception
            {
                throw std::runtime_error("Boatman's health cannot exceed 100.");
            }
            std::cout << boat << " repaired to full health." << std::endl;
        }
        else
        {
            std::cout << boat << " does not need repairs (Health: " << boatman[boat] << ")." << std::endl;
        }
    }
    std::cout << "Repairs completed." << std::endl;

    // 5
    // signal communications or radio using flags and a list or vector or map to allow communication between boatman:
    std::cout << "Setting up communication channels..." << std::endl;
    std::map<int, std::string> communications;
    for (int i = 0; i < 10 /*amountOfSoldiersPerUnit?*/; i++)
    {
        communications[i] = "Channel " + std::to_string(i + 1);
        std::cout << "Boat " << i + 1 << " communicating on " << communications[i] << "." << std::endl;
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
    //I'm thinking that the boatMan can also be more invloved we can allow them to deploy bombs to the enemy at sea
    // and also use their position to help them with their battle plans
    // but I'm not sure how to implement this without creating additional classes for each action
    // and also how to allow them to deploy bombs without creating additional classes for each bomb
    // and also how to handle the communication between boatmen without creating additional classes for each communication
    // and also how to handle the retreat without creating additional classes for each retreat
    // and also how to handle the rest without creating additional classes for each rest
     std::cout << "Boatman is executing battle plans." << std::endl;
    
    // Deploying bombs to the enemy at sea
    std::cout << "Deploying bombs to enemy positions." << std::endl;
    std::map<int, std::pair<std::string, int>> bombDeployment; // <Boat ID, <Target Area, Bomb Count>>
    for (int i = 0; i < 5; i++) // example bomb deployment count
    {
        bombDeployment[i] = std::make_pair("Enemy Ship " + std::to_string(i + 1), 3); // Each boat deploys 3 bombs
        std::cout << "Boat " << i + 1 << " deployed 3 bombs to " << bombDeployment[i].first << "." << std::endl;
    }
    std::cout << "Bomb deployment completed." << std::endl;

    // Using positions for strategic advantage
    std::cout << "Utilizing strategic positions for advantage." << std::endl;
    std::map<int, std::string> strategicPositions; // <Boat ID, Position>
    for (int i = 0; i < 10; i++)
    {
        strategicPositions[i] = "Position " + std::to_string(i + 1);
        std::cout << "Boat " << i + 1 << " at " << strategicPositions[i] << " providing cover fire." << std::endl;
    }
    std::cout << "Strategic positioning completed." << std::endl;

    // Coordinating attacks with communication channels
    std::cout << "Coordinating attacks via communication channels." << std::endl;
    std::map<int, std::string> attackCoordination; // <Boat ID, Target Area>
    for (int i = 0; i < 10; i++)
    {
        attackCoordination[i] = "Target Area " + std::to_string(i + 1);
        std::cout << "Boat " << i + 1 << " attacking " << attackCoordination[i] << " as per communication channel." << std::endl;
    }
    std::cout << "Attack coordination completed." << std::endl;

    // Signaling for support and reinforcements
    std::cout << "Signaling for support and reinforcements." << std::endl;
    std::map<int, std::string> supportSignals; // <Boat ID, Signal Type>
    for (int i = 0; i < 5; i++)
    {
        supportSignals[i] = "Reinforcement Signal " + std::to_string(i + 1);
        std::cout << "Boat " << i + 1 << " sending " << supportSignals[i] << " for additional support." << std::endl;
    }
    std::cout << "Support signaling completed." << std::endl;



    std::cout << "Boatman has executed all battle plans." << std::endl;

}

//ORRRR:

// void Boatman::deployBomb(const std::string& bombType)
// {
//     std::cout << "Deploying " << bombType << "." << std::endl;
//     if (bombType == "Depth Charge")
//     {
//         std::cout << "Depth Charge deployed against enemy submarines." << std::endl;
//     }
//     else if (bombType == "Fire Barrel")
//     {
//         std::cout << "Fire Barrel thrown at enemy ships." << std::endl;
//     }
//     else if (bombType == "Explosive Harpoon")
//     {
//         std::cout << "Explosive Harpoon launched from boat-mounted ballista." << std::endl;
//     }
//     else
//     {
//         std::cout << "Unknown bomb type: " << bombType << std::endl;
//     }
// }

// void Boatman::provideBattleIntel()
// {
//     std::cout << "Providing battle intelligence." << std::endl;
//     std::cout << "Scouting enemy movements and reporting positions." << std::endl;
//     std::cout << "Relaying information to other units using signal flags." << std::endl;
//     std::cout << "Advising on coastal features, tides, and hidden dangers." << std::endl;
// }

// void Boatman::broadcastMessage(const std::string& message)
// {
//     std::cout << "Broadcasting message: " << message << std::endl;
//     //create a series of switch cases of plausable broad casting messages:
//     // e.g., "Enemy Submarine 1 is moving towards our position."
//     // e.g., "Fire Barrel in position X at 10 meters away."
//     // e.g., "Signaling for reinforcement at Position Y."
//     // e.g., "Enemy Ship 1 is under attack. Please retreat."
//     // etc.
//     // and then we could have a function that takes a boatman ID and a message and sends it to all other boatmen in the same unit.
//      for (int i = 1; i <= totalBoatmen; ++i)
//     {
//         std::cout << "Sending message to Boatman " << i << ": " << message << std::endl;
//     }//idea nje

// }

// void Boatman::execute()
// {
//     std::cout << "Boatman is executing battle plans." << std::endl;

//     // Deploying bombs to the enemy at sea
//     deployBomb("Depth Charge");
//     deployBomb("Fire Barrel");
//     deployBomb("Explosive Harpoon");

//     // Using positions for strategic advantage
//     provideBattleIntel();

//     // Coordinating attacks with communication channels
//     broadcastMessage("Attack on Enemy Ship 1");

//     // how can we alllow signaling for support and reinforcements?
//     // if(Boatman[boat1] calls Boatman[boat6])
//     // {std::cout << "Signaling for support and reinforcements." << std::endl;
//     // //then we send boatman to go help but how?

//     // }






//     std::cout << "Boatman execution complete." << std::endl;
// }



void Boatman::retreat()
{
    std::cout << "Boatman is retreating." << std::endl;
    // How can we possibly have a way for the BoatMan to retreat?
    // Should it be that thing of we remove the BoatMan from where they were positioned in the prepare function?
}

void Boatman::rest()
{
    // recharge health
    this->healthPerSoldier += 10;
    std::cout << "Boatman is resting." << std::endl;
}
