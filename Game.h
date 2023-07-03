#pragma once
#include <iostream>

#include "Room.h"
#include "Item.h"
#include "DoublyLinkedNode.h"
#include "Stack.h"
#include "Queue.h"
#include "Teacher.h"
#include "NPC.h"


using namespace std;

class Game
{
public: typedef DoublyLinkedNode<Room> Node;

private: Node* map;
	     Node* fLastRoom;
		 Queue<string>* fQueueInstruction;

		 Teacher* fPlayer;
		 Student* fStudent;
		 string fMsg;
		 



public: Game();
	    ~Game();

		void Start();
		void PrintInstructions();

		/*
		void StartFighting();
		bool EndOfGame();
		bool EndOfFighting();
		*/

		// getters
		Teacher* getPlayer();

		void AppendRoom(Room& aRoom);
		void PrependRoom(Room& aRoom);
		void RemoveRoom(string name);
		void ReadRooms();

		void PopulateMap();
		void UpdatePlayerPos(string direction);

		bool isItemExist(string& name);
		bool isStudentExist();
		bool isPlayerInTheCounter();

		void StartFighting();
		void DisplayRoundStats(int aRound, Entity* student);
		bool EndOfFighting(Entity* student);
		bool EndOfGame();

		void Typing(string aMsg);
		void Loading();
};