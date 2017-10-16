#pragma once
class adventure {
public:

	adventure(string tdialogPath, string tnarrateType, NPC tencounter) {
		dialogPath = tdialogPath;
		narrateType = tnarrateType;
		encounter = tencounter;
	}
	adventure() {
		dialogPath = "narrator1.dialog";
	}

	string getDialogPath() {
		return dialogPath;
	}
	string getNarrateType() {
		return narrateType;
	}

	NPC getEncounter() {
		return encounter;
	}

	void setDialogPath( string temp) {
		dialogPath = temp;
	}
	void setNarrateType(string temp) {
		narrateType = temp;
	}
	void setEncounter(NPC temp) {
		encounter = temp;
	}
		
private:
	string dialogPath;
	string narrateType;
	NPC encounter;
};