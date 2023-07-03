#pragma once
#include "Entity.h"
#include <vector>

class NPC : public Entity
{
private:
	vector<string> fSentences;
public:
	NPC(
		int aMaxHP,
		int aMaxE
	);
	NPC();
	~NPC();

	// Getter
	string GetName();
	string GetSentence();

	// function
	int Attack();
	void Damage(int aDamagePoint);

	void PingStatus();
	void Command();

	void PrintCurrRoom();
	void PrintCurrLvl();
};