#include <iostream>
#include <string>
#include "mainCharacter.h"
#include <time.h>
#include <fstream>
#include "NPC.h"
#include "equipment.h"
#include "armor.h"
#include "weapon.h"
#include "adventure.h"
#include "adventureHandler.h"


using namespace std;
void main()
{
	mainCharacter player;
	cout << player;

	system("pause");
	player.listStats();
	adventureHandler campaign1;
	campaign1.startAdventure(player);
	system("pause");
}

