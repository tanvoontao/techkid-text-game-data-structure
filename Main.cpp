
#include "Game.h"

#include <SFML/Graphics.hpp> // import sfml lib


int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    
    
    /*
    NodeIterator<Item> iter(0);
    iter.push_front({"5",0,0});
    iter.push_front({"4",0,0 });
    iter.push_front({"3",0,0 });
    iter.push_front({"2",0,0 });
    iter.push_front({"1",0,0 });
    iter.remove(*iter);
    for (iter; iter != iter.end(); ++iter)
    {
        cout << (*iter).name << endl;
    }
    */

    /*
    Game game = Game();
    game.PopulateMap();
    game.Start();*/

    

    /*
    Stack<int> instructions(5);
    instructions.push(1);
    instructions.push(2);
    instructions.push(3);

    cout << instructions.size() << endl;
    cout << instructions.top() << endl;
    instructions.pop();
    cout << instructions.top() << endl;
    instructions.pop();
    instructions.pop();
    cout << instructions.size() << endl;*/
    

    /*
    List<string> TheList;
    TheList.push_front("First");
    TheList.push_front("Second");
    TheList.push_front("Third");
    TheList.push_front("Fourth");
    TheList.push_front("Fifth");

    TheList.push_back("NegativeFirst");
    TheList.push_back("NegativeSecond");
    TheList.push_back("NegativeThird");
    TheList.push_back("NegativeFourth");
    TheList.push_back("NegativeFifth");
    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }
    cout << endl;
    TheList.remove("Third");
    TheList.remove("NegativeThird");
    cout << endl;
    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }
    */

    /*
    List<int> TheList;
    TheList.push_back(1);
    TheList.push_back(2);
    TheList.push_back(3);
    TheList.push_back(4);

    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }

    TheList.pop_front();

    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }

    cout << TheList.size() << endl;
    */

    /*
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "size: " << q.size() << endl;
    cout << "things dq: " << q.dequeue() << endl;
    cout << "things dq: " << q.dequeue() << endl;
    cout << "things dq: " << q.dequeue() << endl;
    cout << "size: " << q.size() << endl; */

    /*
    SList<string> TheList;
    TheList.push_front("5");
    TheList.push_front("4");
    TheList.push_front("3");
    TheList.push_front("2");
    TheList.push_front("1");

    
    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }
    cout << endl;
    //TheList.pop_front();
    //TheList.pop_back();
    TheList.remove("4");
    
    for (int i = 0; i < TheList.size(); i++)
    {
        cout << TheList[i] << endl;
    }
    */

    return 0;
}


// https://stackoverflow.com/questions/8486181/how-to-make-a-loading-animation-in-console-application-written-in-c
// https://stackoverflow.com/questions/17132151/how-to-display-loading-with-having-3-dots-animating-using-c
