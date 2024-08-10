#include "ShieldBearer.h"
#include "Boatman.h"
#include "Infantry.h"
//create constructor

int ShieldBearer::totalShieldBearer = 0;

Soldiers *ShieldBearer::clonis()
{
    //clone once 
    Soldiers *clone = new ShieldBearer(this->damagePerSoldier, this->defencePerSoldier);
    return clone;
}

ShieldBearer::ShieldBearer(int damagePerSoldier, int defencePerSoldier) : Soldiers("ShieldBearer" , 0 )
{
    this->amountOfSoldiersPerUnit = amountOfSoldiersPerUnit + totalShieldBearer;
    totalShieldBearer++;
    this->damagePerSoldier = damagePerSoldier;
    this->defencePerSoldier = defencePerSoldier;
    this->healthPerSoldier = 100;
}

ShieldBearer::~ShieldBearer()
{
    totalShieldBearer--;
    this->amountOfSoldiersPerUnit--;
    std::cout << "Deleting Shield \n";
    delete this;
}

int ShieldBearer::getHealthPerSoldier() const
{
   return this->healthPerSoldier;
}

int ShieldBearer::getDamagePerSoldier() const
{
   return this->damagePerSoldier;
}

int ShieldBearer::getDefensePerSoldier() const
{
   return this->defencePerSoldier;
}

int ShieldBearer::getAmountOfSoldiersPerUnit() const
{
   return this->amountOfSoldiersPerUnit;
}





void ShieldBearer::prepare()
{
   //What they possibly do to prepare , Sharpen blades , positioning themselves on land , and gearing up:
    reinforceShields();
   
}


void ShieldBearer::reinforceShields()
{
    // Define shield reinforcement parameters
    std::map<std::string, std::string> reinforcementTasks;
    reinforcementTasks["Layering"] = "Attaching additional layers for durability.";
    reinforcementTasks["ReinforcedEdges"] = "Strengthening shield edges to withstand strikes.";
    reinforcementTasks["FireproofCoating"] = "Applying fire-resistant coating to shields.";

    for (const auto& task : reinforcementTasks)
    {
        std::cout << "\t-"<<task.second << std::endl;
    }

    std::cout << "Shield reinforcement completed." << std::endl;
}



void ShieldBearer::execute()
{
   std::cout<<"Execution process starting..."<<std::endl;

   phalanxCharge();


   //protecting flanks
 std::cout << "Shieldbearers forming defensive lines on the flanks." << std::endl;
   std::map<int, std::string> flankPositions;
    for (int i = 0; i < 5/*some where in the map or graph*/; i++)
    {
        flankPositions[i] = "Flank Position " + std::to_string(i + 1);
    }
    for (const auto& position : flankPositions)
    {
        std::cout << "\t- Shieldbearer at " << position.second << " holding the line." << std::endl;
    }

    // 2. Coordinating with Other Units?
    std::cout << "Coordinating with infantry and archers for a synchronized attack." << std::endl;
    std::vector<std::string> units = {"Infantry", "Archers"};
    for (const auto& unit : units)
    {
        std::cout << "\t- Shieldbearers coordinating with " << unit << "." << std::endl;
    }

    // 3. Engaging Enemies
    std::cout << "Engaging enemies attempting to breach the flanks." << std::endl;
    std::vector<std::string> enemies = {"Enemy Cavalry", "Enemy Infantry"};
    for (const auto& enemy : enemies)
    {
        std::cout << "\t- Shieldbearer engaging " << enemy << "." << std::endl;
    }


    // need to add the damage factors 
    // and the damage taken from enemy units
    // and the losing soldiers
    // and the reinforcement of the shields

    std::cout << "Shieldbearers have executed their battle plan." << std::endl;
}

void ShieldBearer::phalanxCharge()
{  
    std::vector<std::string> actions = {
        "Phalanx Push: Advance as a unit, using shields to push back enemy lines.",
        "Shield Slam: Strike enemies with the edges of shields during the charge.",
        "Intimidation Factor: The synchronized movement intimidates foes."
    };

    for (const auto& action : actions)
    {
        std::cout << "\t-" << action << std::endl;
    }

    std::cout << "Phalanx Charge completed." << std::endl;
}


void ShieldBearer::retreat()
{
   //we need to figure out a way for them to retreat can they possibly go to an empty land or join the boatman or just be more centered than at the boarders?

}

void ShieldBearer::rest()
{
   this->healthPerSoldier += 30 ;
   this->defencePerSoldier += 10;
   std::cout<<"ShieldBearers are currently resting. "<<std::endl;
}


void ShieldBearer::Attack(Soldiers &shieldy)
{
    if( !shieldy.isAlive() )
    {
        std::cout << "ShieldBearer is not alive. Boatman cannot attack." << std::endl;
        return;
    }

    double attStr;
    attStr = damagePerSoldier / 2 ;  // per punch 
    shieldy.takeDamage(attStr);
  

}

// void ShieldBearer::Attack(Infantry* infantry)
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

// void ShieldBearer::Attack(Boatman* boatman)
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

bool ShieldBearer::isAlive()
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
