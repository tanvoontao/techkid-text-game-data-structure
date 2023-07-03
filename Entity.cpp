#include  "Entity.h"

Entity::Entity()
{
	fName = "Grayson Tan";
	fMsg = "";
	fMaxHP, fCurrHP = 100;
	fMaxE, fCurrE = 100;
}

Entity::Entity(string aName, int aMaxHP, int aMaxE)
{
	fName	= aName;
	fMaxHP	= aMaxHP;
	fCurrHP = aMaxHP;
	fMaxE	= aMaxE;
	fCurrE	= aMaxE;
}

Entity::~Entity()
{
}


string Entity::GetName()
{
	return fName;
}

// getters
int Entity::GetMaxHP()
{
	return fMaxHP;
}
int Entity::GetCurrHP()
{
	return fCurrHP;
}
int Entity::GetMaxE()
{
	return fMaxE;
}
int Entity::GetCurrE()
{
	return fCurrE;
}

// setters
void Entity::SetName(int aName)
{
	fName = aName;
}

void Entity::SetMaxHP(int aMaxHP)
{
	fMaxHP = aMaxHP;
}

void Entity::SetCurrHP(int aCurrHP)
{
	fCurrHP = aCurrHP;
}

void Entity::SetMaxE(int aMaxE)
{
	fMaxE = aMaxE;
}

void Entity::SetCurrE(int aCurrE)
{
	fCurrE = aCurrE;
}

void Entity::PrintDetails()
{
	PrintName();
	PrintCurrRoom(); // from derived class
	PrintCurrHP();
	PrintCurrEnergy();
	PrintCurrLvl(); // from derived class
}

void Entity::PrintName()
{
	cout << "\t | Player: " << fName << endl;
}

void Entity::PrintCurrHP()
{
	cout << "\t | Player HP: " << fCurrHP << "/" << fMaxHP << endl; 
}

void Entity::PrintCurrEnergy()
{
	cout << "\t | Player Energy: " << fCurrE << "/" << fMaxE << endl;
}


void Entity::Listen(string aMsg)
{
	fMsg = aMsg;
}
void Entity::Tell()
{
	cout << fMsg << endl;
}
