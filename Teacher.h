#pragma once
#include "Entity.h"
#include "Room.h"
#include "DoublyLinkedNode.h"
#include "SList.h"
#include "Item.h"
#include "NodeIterator.h"

class Teacher : public Entity
{
public: typedef DoublyLinkedNode<Room> Node;
private: 
		 int fLvl;
		 int fCurrExp;
		 int fMaxExp;
		 int fSalary;
		 //SList<Item> fInventory;
		 NodeIterator<Item> iter;
		 Node* fCurrRoom;
		 

public: Teacher();
	   Teacher
	  (
		  string aName,
		  int aMaxHP,
		  int aMaxE
	  );
	   ~Teacher();

	   // getters
	   int GetLvl();
	   //SList<Item> GetInventory();
	   Node& GetCurrRoom();
	   void PrintInventory();

	   // setters
	   void SetCurrRoom(Node* aRoom);
	   void PickItem();

	   void Move();
	   void LookAroundRoom();

	   bool isItemExist(string name);
	   int Attack();
	   void Damage(int aDamagePoint);

	   int Scold();
	   int Taunt();
	   void UpdateLevel();

	   int NavigateInventory();

	   void PingStatus();
	   void Command();
	   friend ostream& operator<<(ostream& aOstream, Teacher* aTeacher);

	   void PrintCurrRoom();
	   void PrintCurrLvl();

};