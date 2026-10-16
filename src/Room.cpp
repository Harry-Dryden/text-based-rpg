#include "Room.h"

Room::Room() //default constructor for the starting room
{
    roomNum =0;

    currAdjoiningRooms=0;
    currEnemiesInRoom=0;
    currNPCsInRoom=0;
    currItemsInRoom=0;

    giveRoomAdjective(Adjectives::adjectiveList[0]);
}

Room::Room(int id)
{
    roomNum= id;

    currAdjoiningRooms=0;
    currEnemiesInRoom=0;
    currNPCsInRoom=0;
    currItemsInRoom=0;

    decideRoomAdjective();
}

void Room::decideRoomAdjective()
{
    //randomly give room an adjective
    giveRoomAdjective(Adjectives::randomAdjective());
}

void Room::giveRoomAdjective(Adjectives::Adjective adjective)
{
    roomAdjective = adjective;
}

void Room::addAdjoiningRoom(Room &adjoiningRoom)
{
    if(currAdjoiningRooms<ADJOINING_ROOMS_POS){
        adjoiningRooms[currAdjoiningRooms] = &adjoiningRoom;
        currAdjoiningRooms+=1;
    }
}

//currently just calls the above function, but wants changing to logically add the previous room automatically (or just getting rid of)
void Room::addPrevRoom(Room &previousRoom)
{
    addAdjoiningRoom(previousRoom);
}

void Room::addCharToRoom(NPC character)
{
    if(currNPCsInRoom<MAX_CHARACTERS){
        npcsInRoom[currNPCsInRoom] = character;
        currNPCsInRoom+=1;
    }
}

void Room::addEnemyToRoom(Enemy enemy)
{
    if(currEnemiesInRoom<MAX_ENEMIES){
        enemiesInRoom[currEnemiesInRoom] = enemy;
        currEnemiesInRoom+=1;
    }
}

void Room::addItemToRoom(Item item)
{
    if(currItemsInRoom<MAX_ITEMS){
        itemsInRoom[currItemsInRoom] = item;
        currItemsInRoom+=1;
    }
}

int Room::getRoomNum()
{
    return roomNum;
}

Adjectives::Adjective Room::getRoomAdj()
{
    return roomAdjective;
}

void Room::printAdjoiningRooms()
{
    for(int i=0; i<adjoiningRooms.size(); i++){
        int adjoiningRoomNum = adjoiningRooms[i]->getRoomNum();
        Adjectives::Adjective adjoiningAdjective = adjoiningRooms[i]->getRoomAdj();
        std::cout<< "Adjoining Room " << i << ": " << adjoiningRoomNum << adjoiningAdjective.adjStr << " room. \n";
    }
}

void Room::printEnemies()
{
}

void Room::printCharacters()
{
}

void Room::printItems()
{
}
