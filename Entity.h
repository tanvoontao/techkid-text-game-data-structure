#pragma once
#include <iostream>
using namespace std;

class Entity
{
protected:	string fName;
			string fMsg;
			int fMaxHP, fCurrHP;
			int fMaxE, fCurrE;

public: Entity();
		Entity
		(
			string aName,
			int aMaxHP,
			int aMaxE
		);
		~Entity();

		// getters
		virtual string GetName();
		virtual int GetMaxHP();
		virtual int GetCurrHP();
		virtual int GetMaxE();
		virtual int GetCurrE();

		// setters
		void SetName(int aName);
		void SetMaxHP(int aMaxHP);
		void SetCurrHP(int aCurrHP);
		void SetMaxE(int aMaxE);
		void SetCurrE(int aCurrE);

		void PrintDetails();
		void PrintName();
		virtual void PrintCurrRoom() = 0; 
		void PrintCurrHP();
		void PrintCurrEnergy();
		virtual void PrintCurrLvl() = 0;
		//virtual void PrintExtra() = 0;
		


		virtual int Attack() = 0;
		virtual void Damage(int aDmg) = 0;
		//virtual void PingStatus() = 0;
		virtual void Listen(string aMsg);
		virtual void Tell();
};