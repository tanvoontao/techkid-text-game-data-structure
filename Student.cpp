#include "Student.h"

Student::Student():fLvl(5)
{
	fMaxHP = 0;
	fCurrHP = 0;
	fMaxE = 0;
	fCurrE = 0;
	fName = "Student 1";
}

Student::Student
(
	string aName,
	int aMaxHP,
	int aMaxE
) :Entity(aName, aMaxHP, aMaxE), fLvl(5)
{
}

Student::~Student()
{
}

void Student::Damage(int aDamagePoint)
{
	this->fCurrHP -= aDamagePoint;
}

int Student::Attack()
{
	srand(time(0));
	string sentences[5] = {
		"Teacher, this is so bored! ",
		"Teacher, this is so hard! ",
		"No one like me.... ",
		"Ughhh, I don\'t like that kid! He bully me! wuuu... ",
		"Don\'t be too loud! Enough for this... No more coding! wuuuu.... "
	};

	int index = (rand() % (sizeof(sentences) / sizeof(string)));
	int attkPoint = (rand() % 20) + 1;
	this->fCurrE -= attkPoint / 3;

	//if (fCurrentHP < 30)
	//{
	//	return Cry(); // return attk point
	//}

	cout << "\n\t Student: " << sentences[index] << endl;
	cout << "\t [Game Message] Student attacked you with damage " << attkPoint << endl;
	return attkPoint;
}


int Student::GetCurrLvl()
{
	return fLvl.top();
	//cout << "Level " << fLvl.top() << endl;
}

void Student::DownGrade()
{
	fLvl.pop();
}

void Student::Populate()
{
	fLvl.push(1);
	fLvl.push(2);
	fLvl.push(3);
}

void Student::PrintCurrRoom()
{
}

void Student::PrintCurrLvl()
{
	cout << "\t Level: " << fLvl.top() << endl;
}