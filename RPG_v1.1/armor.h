#pragma once
#include <string>
#include <iostream>
using namespace std;
class armor :equipment {
public:
	string getEquipmentName() {
		return equipmentName;
	}
	armor(string tName, int tExtraArmorClass, int tWeight) {
		equipmentName = tName;
		weight = tWeight;
		extraArmorClass = tExtraArmorClass;
	}
	armor() {
		equipmentName = "Generic Armor";
		extraArmorClass = 1;
		weight = 1;
	}

	void setExtraArmorClass(int temp) {
		extraArmorClass = temp;
	}
	int getExtraArmorClass() {
		return extraArmorClass;
	}

private:
	int extraArmorClass;

};
