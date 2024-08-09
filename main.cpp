#include <iostream>
#include "SoldierFactory.h"
#include "Soldiers.h"
#include "ShieldBearer.h"
#include "ShieldBearerFactory.h"
#include "Infantry.h"
#include "InfantryFactory.h"
#include "Boatman.h"
#include "BoatmanFactory.h"

int main()
{
    /*
      WAR LOGIC:
      The more shieldbeares you have, the more overall defense you have.
      The more boats you have, the more infantry/weapons you can send to the front lines.
      The more infantry you have the more overall attack you have.

      Tactics:
      Depending on how the war plays out, one can play offense by sending boatman with infantry to the frontlines 
      or defense by sending boatman to the back line.
      So boatman can either support the front or back and the opponent can capitalize on this.
      User can start by choosing a ratio of how many S, B, I depending on the users play style.
      You can program the boatman to help offense or defense depending on the situation of the war
      

    */
}