#pragma once
class NPC {
public:

	NPC (string NPCName, string NPCDialogPath, int NPCMaxHP, int NPCDmgMax, int NPCArmorClass) {
		name = NPCName;
		dialogPath = NPCDialogPath;
		maxHP = NPCMaxHP;
		dmgMax = NPCDmgMax;
		armorClass = NPCArmorClass;
		currentHP = maxHP;
	}
	NPC() {
		name = "generic";
		dialogPath = "null";
		maxHP = 1;
		dmgMax = 0;
		armorClass = 1;
		currentHP = maxHP;
	}
	void setName( string temp) {
		name = temp;
	}
	void setDialogPath(string temp) {
		dialogPath = temp;
	}
	void setMaxHP(int temp) {
		maxHP = temp;
	}
	void setCurrentHP(int temp) {
		currentHP = temp;
	}
	void setDmgMax(int temp) {
		dmgMax = temp;
	}
	void setArmorClass(int temp) {
		armorClass = temp;
	}

	string getName() {
		return name;
	}
	string getDialogPath() {
		return dialogPath;
	}
	int getMaxHp() {
		return maxHP;
	}
	int getCurrentHP() {
		return currentHP;
	}
	int getDmgMax() {
		return dmgMax;
	}
	int getArmorClass() {
		return armorClass;
	}
public:

	string name;
	string dialogPath;
	int maxHP;
	int currentHP;
	int dmgMax;
	int armorClass;
};