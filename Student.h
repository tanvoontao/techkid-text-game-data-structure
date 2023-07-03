#pragma once
#include "Entity.h"
#include "Stack.h"


class Student : public Entity
{
private:
	Stack<int> fLvl;

public:
	Student();
	Student
	(
		string aName,
		int aMaxHP,
		int aMaxE
	);
	~Student();


	void DownGrade();
	void Populate();

	int Attack();
	void Damage(int aDamagePoint);
	int GetCurrLvl();

	void PingStatus();
	void Command();
	friend ostream& operator<<(ostream& aOstream, Student* aStudent);

	void PrintCurrRoom();
	void PrintCurrLvl();

};