#include "NPC.h"

NPC::NPC
(
	int aMaxHP,
	int aMaxE
) : Entity("Principle", aMaxHP, aMaxE)
{
	fSentences = { "Be patient to the kids...","Be friend with them :) " };
}

NPC::~NPC()
{
}

string NPC::GetName()
{
	return fName;
}

string NPC::GetSentence()
{
	srand(time(0));
	int index = (rand() % fSentences.size());
	return fSentences[index];
}

int NPC::Attack()
{
	return 0;
}
void NPC::Damage(int aDamagePoint)
{

}

void NPC::PrintCurrRoom()
{
}

void NPC::PrintCurrLvl()
{
}