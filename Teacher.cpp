#include "Teacher.h"

typedef DoublyLinkedNode<Room> Node;

Teacher::Teacher()
{
	fMaxHP = 0;
	fCurrHP = 0;
	fMaxE = 0;
	fCurrE = 0;
	fCurrExp = 0;
	fLvl = 1;
	fMaxExp = 10;
	fSalary = 0;
	fName = "No Name";
	//fInventory = SList<Item>();
	iter = NodeIterator<Item>(0);
}


Teacher::Teacher
(
	string aName,
	int aMaxHP,
	int aMaxE
) : Entity(aName, aMaxHP, aMaxE)
{
	fLvl = 1;
	fCurrExp = 0;
	fMaxExp = 10;
	fSalary = 0;
	fCurrRoom = &(Node::NIL);
	//fInventory = SList<Item>();
	iter = NodeIterator<Item>(0);
}

Teacher::~Teacher()
{
}

// setters
void Teacher::SetCurrRoom(Node* aRoom) { fCurrRoom = aRoom; }
void Teacher::PickItem()
{
	struct Item newItem = { fCurrRoom->getVal().item.name, fCurrRoom->getVal().item.buff, fCurrRoom->getVal().item.deplete };
	//fInventory.push_front(newItem);
	iter.push_front(newItem);
	fCurrRoom->getVal().item = {"",0,0};
	
	//cout << fInventory.size() << endl;
	//PrintInventory();
	//return fCurrRoom->getVal().item;
}

// getters
int Teacher::GetLvl() { return fLvl; }
Node& Teacher::GetCurrRoom() { return *fCurrRoom; }
//SList<Item> Teacher::GetInventory() { return fInventory;  }

void Teacher::Move() 
{ 
	fCurrE -= 1;
}


void Teacher::LookAroundRoom()
{
	if (fCurrRoom->getVal().item.name != "")
	{
		cout << "\t You see a " << fCurrRoom->getVal().item.name << "! " << endl;
	}
}
void Teacher::PrintInventory()
{
	//if (fInventory.size() > 0 )
	if (iter.size() > 0)
	{
		cout << "\t [ ";
		//for (int i = 0; i < fInventory.size(); i++)
		for (int i = 0; i < iter.size(); i++)
		{
			//cout << fInventory[i].name << " ";
			cout << iter.operator[](i).name << " ";
		}
		cout << "] \n";
	}
	
	
}

bool Teacher::isItemExist(string name)
{
	/*if (fInventory.size() > 0)*/
	if (iter.size() > 0)
	{
		//for (int i = 0; i < fInventory.size(); i++)
		for (int i = 0; i < iter.size(); i++)
		{
			/*if (fInventory[i].name == name)*/
			if (iter[i].name == name)
			{
				return true;
			}
		}
		return false;
	}
	return false;
}

void Teacher::Damage(int aDamagePoint)
{
	this->fCurrHP -= aDamagePoint;

	// here nid something
	if (isItemExist("potion") && this->fCurrHP < 25)
	{
		cout << "\t You: Ugh! Current HP is low than 25. You use a potion. +20HP " << endl;
		this->fCurrHP += 20;
		//RemoveItem("potion");
	}
}

int Teacher::Attack()
{
	int attkPoint;
	int option;
	cout <<
		"\n\t ~~~ [Attack option] ~~~ \n"
		"\t 1. Scold \n"
		"\t 2. Taunt \n"
		"\t Please enter an option: ";
	cin >> option;
	if (option == 1)
	{
		attkPoint = Scold();
	}
	else
	{
		attkPoint = Taunt();
	}
	attkPoint += NavigateInventory();
	

	cout << "\t [Game Message] You attacked the student with damage " << attkPoint << endl;
	UpdateLevel();
	return attkPoint;
}

int Teacher::Scold()
{
	srand(time(0));
	int attkPoint = (rand() % 15) + 1;
	int energyPoint = attkPoint / 2;
	int exp = (rand() % attkPoint) + 1;

	cout <<
		"\t [scold skill applied] \n"
		"\t You: Don\'t you see the class rules ?! Yes, you saw it ! It's on the wall ! \n\n"
		
		<< endl;
	// "\t [Game Message] You attacked the student with damage " << attkPoint << ": +" << exp << " EXP"
	fCurrExp += exp;
	fCurrE -= energyPoint;

	return attkPoint;
}

int Teacher::Taunt()
{
	srand(time(0));
	string sentences[5] = {
		"Own choice bear the consequences! I don\'t care you. \n",
		"Haiyer, who said easy ?? \n",
		"It\'s you ask me to switch you to this lesson. Bored again? I don\'t care.  \n",
		"HAHAHAHA, I blocked the YouTube. \n",
		"Continue messing up the class. I recorded already.  \n"
	};
	int index = (rand() % (sizeof(sentences) / sizeof(string)));
	cout << "\t You: " << sentences[index] << endl;
	int attkPoint = (rand() % 15) + 1;
	int energyPoint = attkPoint / 3;

	int exp = (rand() % attkPoint) + 1;
	fCurrExp += exp;
	fCurrE -= energyPoint;

	return attkPoint;
}

void Teacher::UpdateLevel()
{
	if (fCurrExp >= fMaxExp)
	{
		fLvl += 1;
		fCurrExp -= fMaxExp;
		fMaxExp += 10;
	}
}

int Teacher::NavigateInventory()
{
	if (iter.size() != 0)
	{
		string ans;
		cout << "\t Do you want to use the item? [y/n]: ";
		cin >> ans;
		if (ans == "y")
		{
			PrintInventory();
			string choice = "";
			while (choice != "use")
			{
				cout << "\n\t <-[prev] [use] [nxt]->" << endl;
				cout << "\t current item: " << (*iter).name <<  endl;

				cout << "\t command > ";
				cin >> choice;

				if (choice == "prev")
				{
					if (iter != iter.begin())
					{
						--iter;
					}
				}
				if (choice == "nxt")
				{
					if (iter != iter.end())
					{
						++iter;
					}
				}
			}

			if ((*iter).name == "potion")
			{
				fCurrHP += (*iter).buff;
				//iter.remove({ "potion",   +20, 1 });
				iter.remove(*iter);

				//got issue here
				return 0;
			}
			fCurrE += (*iter).deplete;
			return (*iter).buff;
		
		}
	}
	return 0;
	
}

void Teacher::PrintCurrRoom()
{
	cout << "\t | Current room: " << fCurrRoom->getVal().name << endl;
}

void Teacher::PrintCurrLvl()
{
	cout << "\t | Level: " << fLvl << endl;
}

ostream& operator<< (ostream& ostream, Teacher* aTeacher) {

	ostream << 
		"\n\t _________________________________\n" 
		"\t  You are in the [" << aTeacher->fCurrRoom->getVal().name << "] ! \n"
		<< endl;
		
	ostream << 
		"\t ~~ [" << aTeacher->fName << "'s current status] ~~ \n"
		"\t Your HP:     " << aTeacher->fCurrHP	<< "/" << aTeacher->fMaxHP	<< " \n"
		"\t Your Energy: " << aTeacher->fCurrE	<< "/" << aTeacher->fMaxE	<< " \n"
		"\t Your Level:  " << aTeacher->fLvl		<< " \n"
		"\t Your Exp:    " << aTeacher->fCurrExp << "/" << aTeacher->fMaxExp	<< " \n"
		"\t --------------------------------" << endl;

	return ostream;


}

