#include "Door.hpp"
#include "Room.hpp"

Door::Door(string directionToRoomA, Room* roomA, string directionToRoomB, Room* roomB)
{
    this->directionToRoomA = directionToRoomA;
    this->directionToRoomB = directionToRoomB;
    this->roomA = roomA;
    this->roomB = roomB;
    this->roomA->addDoor(this);
    this->roomB->addDoor(this);
}

 string Door::getDirectionToOtherRoom(Room* currentRoom)
{
    if(currentRoom == this->roomA)
    {
        return this->directionToRoomB;
    }

    else
    {
        return this->directionToRoomA;
    }
    

}

 Room* Door::getOtherRoom(Room* currentRoom)
 {
     //boolean_expression?true-exp:false-exp
     return this->roomA == currentRoom?this->roomB:this->roomA;
 }
 bool Door::hasDirection(string direction)
 {
     return directionToRoomA == direction || directionToRoomB == direction;

 }