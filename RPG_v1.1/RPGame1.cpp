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
#include "windows.h"

int mainCharacter::timeA = 0;
int mainCharacter::timeB = 0;

using namespace std;
void main()
{
	mainCharacter::startTimer();
	mainCharacter player;

	cout << player;
	cout << player.getCurrentHP();
	system("pause");
	
	++player;
	cout << player.getCurrentHP();
	system("pause");
	player.listStats();
	adventureHandler campaign1;
	campaign1.startAdventure(player);

	system("pause");
	mainCharacter::stopTimer();
	mainCharacter::getElapsedTime();
	system("pause");
}

