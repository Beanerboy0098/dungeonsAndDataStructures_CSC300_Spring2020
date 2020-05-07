#include <iostream>
#include "Student.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "Item.hpp"

using namespace std;

int main()
{
    Student* theStudent = new Student("Mr. Gonzales");
    Room* serverRoom = new Room("Server Room");
    Room* esports = new Room("Esports");
    Room* lobby = new Room("Lobby");
    Room* locklairOffice = new Room("Locklairs Office");

    Door* A = new Door("north", serverRoom, "south", lobby);
    Door* B = new Door("west", locklairOffice, "east", lobby);
    Door* C = new Door("south", esports, "north", lobby);

    string command = "";
    lobby->addStudent(theStudent);

    Item* knife = new Item("Finally the perfect weapon");
    theStudent->addItem(knife);
    lobby->addItem("Med Kit");

    while(command != "quit")
    {
        theStudent->getCurrentRoom()->display();
        cout << "Where would you like to go?: ";
        cin >> command;

        if(command == "backpack")
        {
            theStudent->displayBackpackContents();
        }

        else if(command == "drop")
        {
            theStudent->dropItem("Finally the perfect weapon");

        }

        else if(command == "look")
        {
            theStudent->getCurrentRoom()->lookAround();
        }

         else if(command == "pickup")
        {
            string pickUpItem;
            theStudent->pickupItem("Med Kit");
        }

        else
        {
            theStudent->getCurrentRoom()->takeDoor(theStudent, command);

        }
        
    }
    cout << "Goodbye!!!!\n";
    return 0;
}