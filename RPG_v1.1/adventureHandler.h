#pragma once
#include "adventure.h"

class adventureHandler{
public:
	adventureHandler() {
		NPC dianna("Dianna", "w/e", 15, 15, 15);
		NPC narrator("Narrator", "narrator.dialog", 999, 999, 999);  //what is my purpose? You pass butter
		NPC frog("Wright", "Release... Me...", 6, 3, 4);
		NPC dzik("Occult", "REPENT HERETIC!", 10, 6, 6);
		NPC devil("Devil", "The Devil himself, reaper of souls... Welcome and prepare to die!", 200, 10, 15);

		Adventure1[0].setDialogPath("narrate0.dialog");
		Adventure1[0].setNarrateType("narration");
		Adventure1[0].setEncounter(narrator);

		Adventure1[1].setDialogPath("Dianna1.dialog");
		Adventure1[1].setNarrateType("narration");
		Adventure1[1].setEncounter(dianna);

		Adventure1[2].setDialogPath("dzikCombat.dialog");
		Adventure1[2].setNarrateType("combat");
		Adventure1[2].setEncounter(dzik);

		Adventure1[3].setDialogPath("narrate1.dialog");
		Adventure1[3].setNarrateType("questReturn");
		Adventure1[3].setEncounter(narrator);

		Adventure1[4].setDialogPath("frogCombat.dialog");
		Adventure1[4].setNarrateType("combat");
		Adventure1[4].setEncounter(frog);

		Adventure1[5].setDialogPath("devil.dialog");
		Adventure1[5].setNarrateType("combat");
		Adventure1[5].setEncounter(devil);

		progress = 0;
	}

	int narrate(adventure Adventure1, mainCharacter player) {
		fstream dialogFile;
	
					if (Adventure1.getNarrateType() == "combat") {
				bool temp = battle(player, Adventure1.getEncounter());
				if (!temp) return 3;
			
			}
					if (player.getCurrentHP() > 0) {
						dialogFile.open(Adventure1.getDialogPath(), ios::in);
						if (dialogFile.good() == true)
						{
							string dialog;
							while (getline(dialogFile, dialog))
							{
								cout << dialog << endl;
							}
						}
						else {
							cout << "Mising dialog file!" << endl;
						}
						cout << "Type below" << endl;
						cout << "1 -Go left" << endl;
						cout << "2 -Go right?" << endl;
						int choice;
						cin >> choice;
						switch (choice)
						{
						case 1:
							cout << "You go left" << endl;
							return 1;
							break;


						case 2:
							cout << "You go right" << endl;
							return 2;
							break;


						default:

							break;
						}
					}
					else {
						return 3;
					}
		}

	bool startAdventure(mainCharacter player) {
		switch (narrate(Adventure1[0], player)) {
		case 1:
			//go to dianna
			switch (narrate(Adventure1[1], player)) {
				case 1:
					//go to dzik
					narrate(Adventure1[2], player);
					//after dzik go to narrate2
					break;
				case 2:
					//go to frogs
					narrate(Adventure1[4], player);
					//after frog go to narrate2
					break;
				case 3:
					return false;
			}
		case 2:
			narrate(Adventure1[4], player);
		}
		switch (narrate(Adventure1[3], player)) {
		case 1: 
			narrate(Adventure1[5], player);
			break;
		case 3:
			return false;
		default:
			break;
		}
		cout << "End of the game" << endl;
		return true;
		
	}
	static int roller(int max, int min) {
		int	rolled = rand() % max + min;
		srand(time(NULL));
		return rolled;
	}
	bool battle(mainCharacter player, NPC encounter) {
		int damageLeft;
		int rolled;
		system("cls");
		cout << "You encounter " << encounter.getName() << endl;
		cout << encounter.getName() << " screams at you: " << encounter.getDialogPath() << endl;
		while (player.getCurrentHP() > 0 && (encounter.getCurrentHP() > 0)) {
			int choice;
			int rolledAttack;
			float rolledDmg;
			cout << "------------------------------------------" << endl;
			cout << "What do you do?" << endl;
			cout << "1- Attack" << endl;
			cout << "2- Run" << endl;
			cout << "------------------------------------------" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "You try to attack " << encounter.getName() << endl;
				rolledAttack = roller(20, 1);

				cout << "You rolled " << rolledAttack << " as your attack roll!" << endl;
				if (rolledAttack > encounter.getArmorClass()) {
					srand(time(NULL));
					rolledDmg = roller(6, 1) + player.getStrength() % 10 + player.getCurrentWeapon().getExtraDmg();
					encounter.setCurrentHP(encounter.getCurrentHP() - rolledDmg);
					cout << endl;
					cout << "------------------------------------------" << endl;
					cout << "You hit " << encounter.getName() << " dealing: " << rolledDmg << " dmg" << endl;
					cout << encounter.getName() << " has " << encounter.getCurrentHP() << "HP left" << endl;
					cout << "------------------------------------------" << endl;
				}
				else {
					cout << "------------------------------------------" << endl;
					cout << "You failed!" << endl;
					cout << "------------------------------------------" << endl;
				}
				system("pause");
				system("cls");
				break;

			case 2:
				cout << "You ran away safely..." << endl;
				return true;

			default:

				break;
			}
			if (encounter.getCurrentHP() > 0) {
				rolledAttack = 0;
				rolledDmg = 0;
				cout << encounter.getName() << " tries to attack you!" << endl;

				rolledAttack = roller(20, 1);
				if (rolledAttack > player.getArmorClass()) {
					rolledDmg = roller(encounter.getDmgMax(), 0);
					damageLeft = player.getCurrentHP() - rolledDmg;
					player.setCurrentHP(damageLeft);
					cout << endl;
					cout << "------------------------------------------" << endl;
					cout << encounter.getName() << " attacks you and deals you: " << rolledDmg << " dmg points." << endl;
					cout << "You have " << player.getCurrentHP() << "HP left" << endl;
					cout << "------------------------------------------" << endl;
				}
				else {
					cout << "Enemy attack missed!" << endl;
				}
				system("pause");
				system("cls");
			}

			else {
				system("pause");
				system("cls");
			}
		}
		cout << "Battle ends!" << endl;
		system("pause");
		system("cls");

		if (player.getCurrentHP() > 0) {
			cout << "You won!" << endl;
			return true;
		}
		else {
			cout << " YOU DIED" << endl;
			return false;
		}
	
	}

private: 
	int progress;
	adventure Adventure1[6];
};
