#include "ShieldBearer.h"
#include "Boatman.h"
#include "Infantry.h"


int ShieldBearer::amountOfSoldiersPerUnit = 0;

Soldiers *ShieldBearer::clonis()
{
    // clone once
    Soldiers *clone = new ShieldBearer(this->damagePerSoldier, this->defencePerSoldier);
    return clone;
}

ShieldBearer::ShieldBearer(int damagePerSoldier, int defencePerSoldier) : Soldiers("ShieldBearer")
{

    this->damagePerSoldier = damagePerSoldier;
    this->defencePerSoldier = defencePerSoldier;
    this->healthPerSoldier = 100;
    this->amountOfSoldiersPerUnit++;
}

ShieldBearer::~ShieldBearer()
{
    // totalShieldBearer--;
    this->amountOfSoldiersPerUnit--;
    std::cout << "Deleting Shield \n";
    delete this;
}

int ShieldBearer::getHealthPerSoldier() const
{
    return this->healthPerSoldier;
}

int ShieldBearer::getDamagePerSoldier()
{
    return this->damagePerSoldier;
}

int ShieldBearer::getDefensePerSoldier()
{
    return this->defencePerSoldier;
}

int ShieldBearer::getAmountOfSoldiersPerUnit()
{
    return this->amountOfSoldiersPerUnit;
}

void ShieldBearer::subByOne()
{
    this->amountOfSoldiersPerUnit--;
}

void ShieldBearer::prepare()
{
    reinforceShields();
}

void ShieldBearer::reinforceShields()
{
    //1
    std::map<std::string, std::string> reinforcementTasks;
    reinforcementTasks["Layering"] = "Attaching additional layers for durability.";
    reinforcementTasks["ReinforcedEdges"] = "Strengthening shield edges to withstand strikes.";
    reinforcementTasks["FireproofCoating"] = "Applying fire-resistant coating to shields.";

    for (const auto &task : reinforcementTasks)
    {
        std::cout << "\t-" << task.second << std::endl;
    }

    std::cout << "Shield reinforcement completed." << std::endl;
}

void ShieldBearer::execute()
{
    std::cout << "SHIELDBEARER EXECUTING: " << std::endl;
    phalanxCharge();
    // 1
    std::cout << "Shieldbearers forming defensive lines on the flanks." << std::endl;
    std::map<int, std::string> flankPositions;
    for (int i = 0; i < 5 ; i++)
    {
        flankPositions[i] = "Flank Position " + std::to_string(i + 1);
    }
    for (const auto &position : flankPositions)
    {
        std::cout << "\t- Shieldbearer at " << position.second << " holding the line." << std::endl;
    }

    // 2
    std::cout << "SYNCONIZATION ATTACK" << std::endl;
    std::vector<std::string> units = {"Infantry", "Archers","Boatman"};
    for (const auto &unit : units)
    {
        std::cout << "\t- Shieldbearers coordinating with " << unit << "." << std::endl;
    }

    // 3
    std::cout << "Engaging enemies attempting to breach the flanks." << std::endl;
    std::vector<std::string> enemies = {"Enemy Boatman", "Enemy Infantry"};
    for (const auto &enemy : enemies)
    {
        std::cout << "\t- Shieldbearer engaging " << enemy << "." << std::endl;
    }
    std::cout << "Shieldbearers have executed their battle plan." << std::endl;
}

void ShieldBearer::phalanxCharge()
{
    std::vector<std::string> actions = {
        "Phalanx Push: Advance as a unit, using shields to push back enemy lines.",
        "Shield Slam: Strike enemies with the edges of shields during the charge.",
        "Intimidation Factor: The synchronized movement intimidates foes."};

    for (const auto &action : actions)
    {
        std::cout << "\t-" << action << std::endl;
    }

    std::cout << "Phalanx Charge completed." << std::endl;
}

void ShieldBearer::retreat()
{
    std::cout<<"SHIELDBEARERS RETREAT!!!!!!!";

}

void ShieldBearer::rest()
{
    if(defencePerSoldier > 75)
    {
        defencePerSoldier = 75;
    }
    std::cout<<"ShieldBearer resting ^☺^"<<std::endl;
}

void ShieldBearer::Attack(Soldiers *shieldy)
{
    if (!shieldy || !shieldy->isAlive())
    {
        std::cout << "ShieldBearer is not alive,thus cannot attack." << std::endl;
        return;
    }

    double attStr, dmgNew;
    attStr = shieldy->getDamagePerSoldier() / 2.5; // per punch
    dmgNew = shieldy->getDamagePerSoldier() / 2;

    shieldy->setHealthPerSoldier(attStr);
    shieldy->setDefensePerSoldier(dmgNew);
}

void ShieldBearer::setHealthPerSoldier(int i)
{
    this->healthPerSoldier -= i;
}

void ShieldBearer::setDamagePerSoldier(int damage)
{
    this->damagePerSoldier = damage;
}

void ShieldBearer::setDefensePerSoldier(int defence)
{
    this->defencePerSoldier = defence;
}

void ShieldBearer::setAmountOfSoldiersPerUnit(int amount)
{
    this->amountOfSoldiersPerUnit = amount;
}

bool ShieldBearer::isAlive()
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
