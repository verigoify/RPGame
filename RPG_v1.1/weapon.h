#pragma once
class weapon : equipment {
public:
	string getEquipmentName() {
		return equipmentName;
	}

	weapon(string tName, int tExtraDmg, int tWeight) {
		equipmentName = tName;
		weight = tWeight;
		extraDmg = tExtraDmg;
	}
	weapon() {
		equipmentName = "Generic Weapon";
		extraDmg = 1;
		weight = 1;
	}

	void setExtraDmg(int temp) {
		extraDmg = temp;
	}
	int getExtraDmg() {
		return extraDmg;
	}
private:
	int extraDmg;
};
