#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
#include <vector>


#include "Game.h"

using namespace std;


Game::Game()
{
    fMsg = "";

    map = &(Node::NIL);
    fPlayer = new Teacher("Grayson Tan", 100, 100);
    fStudent = new Student("Tan Voon Tao", 100, 100);
    fStudent->Populate();


    fQueueInstruction = new Queue<string>;

    fQueueInstruction->enqueue("\t Hello! Mr " + fPlayer->GetName() + "! \n");
    fQueueInstruction->enqueue("\t Welcome to the (RPG) TechKID Learning Centre! \n");
    fQueueInstruction->enqueue("\t This super simple RPG game tells you how my life works as a part-timer to coach the kids about coding. \n");
    fQueueInstruction->enqueue("\t There is a one-line map which represent the environment of the centre. You can move forward and backward. \n");
    fQueueInstruction->enqueue("\t You will experience crazy student(s) as your enemy during our coaching. \n");
    fQueueInstruction->enqueue("\t Try to beat them down and escape from the centre!\n\n");

    fQueueInstruction->enqueue("Game Rules : \n");
    fQueueInstruction->enqueue("\t 1. Every time you move, you will lose 1 energy point \n");
    fQueueInstruction->enqueue("\t 2. Get items to help you escape from the crazy students \n");
    fQueueInstruction->enqueue("\t 3. Get outside with a key in your inventory to win the game \n");

    fQueueInstruction->enqueue("~~~ Game Commands ~~~ \n");
    fQueueInstruction->enqueue("\t > [go] {direction} (forward/backward) to enter the front or back room \n");
    fQueueInstruction->enqueue("\t > [get] {item}                        to pick up the item in the room \n");
    fQueueInstruction->enqueue("\t > [exit]                              to quit the game \n");
    fQueueInstruction->enqueue("\t > [stats]                             to display player current status \n");
    fQueueInstruction->enqueue("\t > [help]                              to see the available game commands \n\n");
    
    

    fQueueInstruction->enqueue("\t The map is shown below here. \n");
    fQueueInstruction->enqueue("\t [dinning room] -> [staff kitchen] -> [counter] -> [office] -> ");
    fQueueInstruction->enqueue("\t [toilet] -> [class room] -> [outside] \n\n");

    fQueueInstruction->enqueue("\t Without further ado, let's start the journey! ");
}


void Game::Typing(string msg)
{
    int x = 0;
    while (msg[x] != '\0')
    {
        cout << msg[x];
        Sleep(50);
        x++;
    };
    cout << endl;
}

void Game::Loading()
{
    cout << "\t ";
    for (int time = 0; time < 1; time++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "." << flush;
            Sleep(1000);
        }
        cout << "\b\b\b   \b\b\b";
    }
}

void Game::PrintInstructions()
{
    
    for (int i = 0; i < 6; i++)
    {
        cout << fQueueInstruction->dequeue() << endl;
    }

    /*
    cout << "\t Hello! Mr " << fPlayer.GetName() << "! " << endl;
    cout <<
        "\t Welcome to the (RPG) TechKID Learning Centre! \n"
        "\t This super simple RPG game tells you how my life works as a part-timer to coach the kids about coding. \n\n"

        "\t There is a one-line map which represent the environment of the centre. \n"
        "\t You can move forward and backward. You will experience crazy student(s) as your enemy during our coaching. \n"
        "\t Try to beat them down and escape from the centre!\n\n";
    */

    Loading();
    
    for (int i = 0; i < 4; i++)
    {
        Typing(fQueueInstruction->dequeue());
    }


    /*
    Typing(
        "Game Rules : \n"
        "\t 1. Every time you move, you will lose 1 energy point \n"
        "\t 2. Get items to help you escape from the crazy students \n"
        "\t 3. Get outside with a key in your inventory to win the game \n");
    */

    Loading();

    // game commands
    for (int i = 0; i < 6; i++)
    {
        cout << fQueueInstruction->dequeue();
    }

    // maps
    for (int i = 0; i < 3; i++)
    {
        cout << fQueueInstruction->dequeue();
    }

    /*
    cout << 
        "Command : \n"
        "\t exit \n"
        "\t get  [item] \n"
        "\t go   [direction] (forward / backward) \n" << endl;

    cout <<
        "\t The map is shown below here. \n"
        "\t [dinning room] -> [staff kitchen] -> [counter] -> [office] -> "
        "\t [toilet] -> [class room] -> [outside] \n"
        << endl;

    Typing("\t Without further ado, let's start the journey! ");
    */

    Typing(fQueueInstruction->dequeue());
}

void Game::Start()
{
    
    //PrintInstructions();

    while (true)
    {
        cout << fPlayer; // display player status
        fPlayer->PrintInventory();
        fPlayer->LookAroundRoom();
        

        cout << "\t command > ";
        getline(cin, fMsg);

        

        if (fMsg.find("go") != string::npos)
        {
            if (fMsg.find("forward") != string::npos)
            {
                UpdatePlayerPos("forward");
            }
            else if (fMsg.find("backward") != string::npos)
            {
                UpdatePlayerPos("backward");
            }
            else
            {
                Typing("\t Ugh... I guess you just read the commands, right? Are u try to escape from the wall?");
            }

            fPlayer->Move();
        }

        if (fMsg.find("get") != string::npos)
        {
            fMsg.replace(0, 4, "");

            if (isItemExist(fMsg))
            {
                fPlayer->PickItem();
            }
            else
            {
                cout << "\t There is nothing you can get! " << endl;
            }
        }

        if (fMsg.find("help") != string::npos)
        {
            Typing("\t ~~~ Game Commands ~~~ \n"
                    "\t > [go] {direction} (forward/backward) to enter the front or back room \n"
                    "\t > [get] {item}                        to pick up the item in the room \n"
                    "\t > [exit]                              to quit the game \n"
                    "\t > [stats]                             to display player current status \n"
                    "\t > [help]                              to see the available game commands \n\n"
            );
        }

        if (fMsg.find("stats") != string::npos)
        {
            fPlayer->PrintDetails();
        }

        if (isStudentExist())
        {
            StartFighting();
        }

        

        if (isPlayerInTheCounter())
        {
            NPC* principle = new NPC(999, 999);
            Typing("\t " + principle->GetName() + ": " + principle->GetSentence() + " \n");
            delete principle;
        }

        if (EndOfGame())
        {
            break;
        }

        if (fMsg.find("exit") != string::npos) { break; }
    }
}


// room related
void Game::AppendRoom(Room& aRoom)
{
    Node* newNode = new Node(aRoom);

    if (map == &(Node::NIL))
    {
        map = newNode;
        fLastRoom = newNode;
    }
    else
    {
        Node* temp = newNode;
        fLastRoom->append(*temp);
        fLastRoom = temp;
    }
}

void Game::PrependRoom(Room& aRoom)
{
    Node* newNode = new Node(aRoom);

    if (map == &(Node::NIL))
    {
        map = newNode;
        fLastRoom = newNode;
    }
    else
    {
        Node* temp = newNode;
        map->prepend(*temp);
        map = temp;
    }
}

void Game::ReadRooms()
{
    if (map != &(Node::NIL))
    {
        Node* temp = map;
        while (map != &(Node::NIL))
        {
            Room room = map->getVal();
            cout << room.name << endl;
            map = &map->getNxt();
        }
        map = temp;
    }
    else {
        cout << "No rooms available" << endl;
    }
}

void Game::RemoveRoom(string name)
{
    if (map != &(Node::NIL))
    {
        Node* temp = map;
        while (map != &(Node::NIL))
        {
            Room room = map->getVal();
            if (room.name == name)
            {
                if (&map->getPrev() == &(Node::NIL))
                {
                    temp = &map->getNxt();
                }
                map->remove();
                break;
            }
            map = &map->getNxt();
        }
        map = temp;
    }
    else {
        cout << "No rooms available" << endl;
    }
}

void Game::PopulateMap()
{
    struct Item key     = { "key",      0,   1 };
    struct Item rotan   = { "rotan",    +10, -10 };
    struct Item speaker = { "speaker",  +95, -15 };
    struct Item potion  = { "potion",   +20, 1 };


    struct Room dinningRoom     = { "dinning room", speaker };
    struct Room staffKitchen    = { "staff kitchen", potion };
    struct Room counter         = { "counter", {"",0,0}};
    struct Room office          = { "office", rotan };
    struct Room toilet          = { "toilet", key };
    struct Room classRoom       = { "class room", {"",0,0}, fStudent};
    struct Room outside         = { "outside" };
    
    AppendRoom(office);
    AppendRoom(toilet);
    AppendRoom(classRoom);
    AppendRoom(outside);
    PrependRoom(counter);
    PrependRoom(staffKitchen);
    PrependRoom(dinningRoom);

    fPlayer->SetCurrRoom(map);
}


// player related
void Game::UpdatePlayerPos(string direction)
{
    Node* temp = map;

    while (map != &(Node::NIL))
    {
        Room room = map->getVal();
        if (fPlayer->GetCurrRoom().getVal().name == room.name)
        {
            if (direction == "forward")
            {
                if (&map->getNxt() != &(Node::NIL))
                {
                    fPlayer->SetCurrRoom(&map->getNxt());
                }
            }
            else if (direction == "backward")
            {
                if (&map->getPrev() != &(Node::NIL))
                {
                    fPlayer->SetCurrRoom(&map->getPrev());
                }
            }
            break;
        }
        map = &map->getNxt();
    }
    map = temp;

}


// item related
bool Game::isItemExist(string& name)
{
    if (fPlayer->GetCurrRoom().getVal().item.name == name)
    {
        return true;
    }
    return false;
}

bool Game::isPlayerInTheCounter()
{
    if (fPlayer->GetCurrRoom().getVal().name == "counter")
    {
        return true;
    }
    return false;
}


bool Game::isStudentExist()
{
    //cout << fPlayer->GetCurrRoom().getVal().student.GetCurrHP() << endl;
    if (
        fPlayer->GetCurrRoom().getVal().student != nullptr && 
        fPlayer->GetCurrRoom().getVal().student->GetCurrHP() > 0)
    {
        return true;
    }
    return false;
}


void Game::StartFighting()
{
    bool endOfGame = false;
    int round = 1;
    int attkPoint = 0;

    vector<Entity*> entities = {
        fPlayer,
        fStudent
    };

    Typing(
        "\n\t You see a student. \n" 
        "\t You:     Hi student! Nice to meet you all, what a lovely day! \n" 
        "\t Student: Yay.. what a lovely day... hehehehe.... \n" 
        "\t You:     Let me ask you some questions now... \n\n"
    );

    string questions[3] = {
        "\t Q1: Queue cannot be implemented using in an array. [Y/N]",
        "\t Q2: Each node of a singly linked list has at least four components [Y/N]",
        "\t Q3: In general, there are three types of linked lists and they are: sorted, unsorted and mixed. [Y/N]"
    };

    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        cout << questions[i] << endl;
        Typing(
            "\t Student: YES! \n"
            "\t Student Level: " + to_string(fStudent->GetCurrLvl()) + " \n"
            "\t [wrong answer] Downgrading your level now... \n"
        );

        fStudent->DownGrade();

        Loading();
    }

    Typing(
        "\n\t Student: Ugh...! SUPER HARD! AHHHH! \n"
        "\t Ready... Start!!"
    );


    Loading();

    while (!endOfGame)
    {
        DisplayRoundStats(round, entities.at(1));


        // student 
        Loading();
        attkPoint = entities.at(1)->Attack(); // display attk opt and get opt
        entities.at(0)->Damage(attkPoint);

        // player - teacher
        attkPoint = entities.at(0)->Attack();
        entities.at(1)->Damage(attkPoint);


        endOfGame = EndOfFighting(entities.at(1));
        if (!endOfGame) { round += 1; }
    }


}

bool Game::EndOfFighting(Entity* student)
{
    if (EndOfGame())
    {
        return true;
    }

    if (student->GetCurrHP() < 1 || student->GetCurrE() < 1)
    {
        fPlayer->GetCurrRoom().getVal().student->SetCurrHP(0);
        cout << "\t You win the crazy student! " << endl;
        return true;
    }
    return false;
}


void Game::DisplayRoundStats(int aRound, Entity* student)
{

    cout << "\n\t -------------- Round " << aRound << "--------------\n"
        "\t [Game Message] \n"
        "\t Your Current HP:     " << fPlayer->GetCurrHP() << "/" << fPlayer->GetMaxHP() << " \n"
        "\t Your Current Energy: " << fPlayer->GetCurrE() << "/" << fPlayer->GetMaxE() << " \n"
        "\t Student Current HP:  " << student->GetCurrHP() << "/" << student->GetMaxHP() << endl;
}

bool Game::EndOfGame()
{
    if (fPlayer->GetCurrRoom().getVal().name == "outside" && fPlayer->isItemExist("key"))
    {
        Typing("\t [Game Win] You escaped from the learning centre! \n");
        return true;
    }
    if (fPlayer->GetCurrHP() < 1)
    {
        Typing("\t [Game Lose] You dead! \n");
        return true;
    }
    if (fPlayer->GetCurrE() < 1)
    {
        Typing("\t [Game Lose] You don\'t have anymore energy... ! \n");
        return true;
    }

    return false;
}

Game::~Game()
{
    delete fQueueInstruction;
    if (map != &(Node::NIL))
    {
        Node* temp = map;
        while (map != &(Node::NIL))
        {
            temp = &map->getNxt();
            map->remove();
            map = temp;
        }
    }
}

// getters
Teacher* Game::getPlayer() { return fPlayer; }