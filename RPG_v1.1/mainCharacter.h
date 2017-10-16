#pragma once
#include "equipment.h"
#include "armor.h"
#include "weapon.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class mainCharacter
{
public:

	//constructor for mainCharacter class that requires provided character's stat
	/*mainCharacter(int str, int dex, int consti, int intelli, int wis, int chari, string charName, string charClass)
	{
		strength = str;
		dexterity = dex;
		constitution = consti;
		intelligence = intelli;
		wisdom = wis;
		charisma = chari;
		name = charName;
		characterClass = charClass;
		
		currentHP = maxHP;
		if (charClass == "warrior") {
			armorClass = 10;
			maxCarriedWeight = 6;
		}
		if (charClass == "wizzard") {
			armorClass = 8;
			maxCarriedWeight = 3;
		}
		
	}*/
	//character creator function -reads dialog from GuardianAngel and saves player's stats using 1-dimension array
	mainCharacter() {
		//pregen statblock
		cout << "debugMode Y/N?" << endl;
		string choice;
		cin >> choice;
		if (choice == "y") {
			name = "Generic Name";
			characterClass = "warrior";
			strength = 10;
			dexterity = 10;
			constitution = 10;
			intelligence = 10;
			wisdom = 10;
			charisma = 10;
			maxHP = 10;
			currentHP = maxHP;
			armorClass = 10;
			weapon genericW("Generic", 1, 1);
			armor genericA("Generic", 1, 1);
			carriedWeapon = genericW;
			carriedArmor = genericA;
			maxCarriedWeight = 2;
		}
		//reasume normal ops
		else {
			fstream dialogFile;
			string playerInfo[8];
			int i = 0;
			dialogFile.open("characterCreation.dialog", ios::in);
			if (dialogFile.good() == true)
			{
				string dialog;
				while (getline(dialogFile, dialog))
				{
					cout << dialog << endl;
					cin >> playerInfo[i];
					i++;
				}
			}
			else cout << "Can not access dialog file. Please check if all files are in place." << endl;
			system("pause");
			system("exit");
			name = playerInfo[0];
			characterClass = playerInfo[1];
			strength = stoi(playerInfo[2]); //stoi = convert string to int 
			dexterity = stoi(playerInfo[3]);
			constitution = stoi(playerInfo[4]);
			intelligence = stoi(playerInfo[5]);
			wisdom = stoi(playerInfo[6]);
			charisma = stoi(playerInfo[7]);

			if (characterClass == "warrior") {
				maxHP = 15;
				currentHP = maxHP;

				maxCarriedWeight = 6;
				weapon axe("Axe", 3, 3);
				armor plate("Plate", 3, 3);
				carriedWeapon = axe;
				carriedArmor = plate;
				armorClass = 10 + plate.getExtraArmorClass();
			}
			else {
				if (characterClass == "wizzard") {
					setMaxHP(10);
					currentHP = maxHP;
					setMaxCarriedWeight(3);
					weapon wand("Wand", 1, 1);
					armor robes("Robes", 2, 2);
					carriedWeapon = wand;
					carriedArmor = robes;
					armorClass = 8 + robes.getExtraArmorClass();
				}
				else {
					setMaxHP(10);
					currentHP = maxHP;
					setMaxCarriedWeight(3);
					weapon genericW("Generic", 1, 1);
					armor genericA("Generic", 2, 2);
					carriedWeapon = genericW;
					carriedArmor = genericA;
					armorClass = 8 + genericA.getExtraArmorClass();
				}
			}
		}
			
			
	}

	//destructor for mainCharacter class
	~mainCharacter()
	{
	}

	//getters for mainCharacter class
	armor getCurrentArmor() {
		return carriedArmor;
	}
	weapon getCurrentWeapon() {
		return carriedWeapon;
	}
	int getStrength() {
		return strength;
	}
	int getDexterity() {
		return dexterity;
	}
	int getConstitution() {
		return constitution;
	}
	int getIntelligence() {
		return intelligence;
	}
	int getWisdom() {
		return wisdom;
	}
	int getCharisma() {
		return charisma;
	}
	string getName() {
		return name;
	}
	string getCharacterClass() {
		return characterClass;
	}
	int getMaxHP() {
		return maxHP;
	}
	int getCurrentHP() {
		return currentHP;
	}

	int getArmorClass() {
		return armorClass;
	}
	int getMaxCarriedWeight() {
		return maxCarriedWeight;
	}

	//setter for mainCharacter class
	void setStrength(int temp) {
		strength = temp;
	}
	void setDexterity(int temp) {
		dexterity = temp;
	}
	void setConstitution(int temp) {
		constitution = temp;
	}
	void setIntelligence(int temp) {
		intelligence = temp;
	}
	void setWisdom(int temp) {
		wisdom = temp;
	}
	void setCharisma(int temp) {
		charisma = temp;
	}
	void setName(string temp) {
		name = temp;
	}
	void setCharacterClass(string temp) {
		characterClass = temp;
	}
	void setMaxHP(int temp) {
		maxHP = temp;
	}
	void setCurrentHP(int temp) {
		currentHP = temp;
	}
	void setArmorClass(int temp) {
		armorClass = temp;
	}
	void setMaxCarriedWeight(int temp) {
		maxCarriedWeight = temp;
	}
	void setCarriedArmor(armor temp) {
		carriedArmor = temp;
	}
	void setCarriedWeapon(weapon temp) {
		carriedWeapon = temp;
	}

	//list stats function lists all character's stats formatted nicely
	void listStats() {
		cout << "Character's name: " << name << endl;
		cout << "Class: " << characterClass << endl;
		cout << "HP: " << currentHP << "/" << maxHP << endl;
		cout << "AC: " << armorClass << endl;
		cout << "You can carry up to: " << maxCarriedWeight << " weight of things" << endl;
		cout << "--------------------"			<< endl;
		cout << "| " << "Strenght:      " << strength		<< " |" << endl;
		cout << "| " << "Dexterity:     " << dexterity		<< " |" << endl;
		cout << "| " << "Constitution   " << constitution	<< " |" << endl;
		cout << "| " << "Intelligence:  " << intelligence	<< " |" << endl;
		cout << "| " << "Wisdom:        " << wisdom			<< " |" << endl;
		cout << "| " << "Charisma:      " << charisma		<< " |" << endl;
		cout << "--------------------"			<< endl;
		cout << "Your equipment: " << endl;
		cout << "Armor: " << carriedArmor.getEquipmentName() << endl;
		cout << "Weapon: " << carriedWeapon.getEquipmentName() << endl;
	
		system("pause");
		system("cls");
	}


private:
	//basic character stats, private values
	int strength;
	int dexterity;
	int constitution;
	int intelligence;
	int wisdom;
	int charisma;
	int maxHP;
	int currentHP;
	int armorClass;
	int maxCarriedWeight;
	string name;
	string characterClass;
	armor carriedArmor;
	weapon carriedWeapon;
};


