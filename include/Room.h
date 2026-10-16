#pragma once

#include "Adjectives.h"
#include "NPC.h"
#include "Enemy.h"
#include "Item.h"

#include <limits>

class Room{
private:
    static constexpr int ADJOINING_ROOMS_POS = 4;
    static constexpr int MAX_CHARACTERS = 4;
    static constexpr int MAX_ENEMIES = 4;
    static constexpr int MAX_ITEMS = 4;

    std::string roomName;
    Adjectives::Adjective roomAdjective; //the adjective of the room
    int roomNum; //the room's incremental id - higher ids will mean more difficulty

    int currAdjoiningRooms;
    int currNPCsInRoom;
    int currEnemiesInRoom;
    int currItemsInRoom;

    std::array<Room*, ADJOINING_ROOMS_POS> adjoiningRooms;
    std::array<NPC, MAX_CHARACTERS> npcsInRoom;
    std::array<Enemy, MAX_ENEMIES> enemiesInRoom;
    std::array<Item, MAX_ITEMS> itemsInRoom;

    void addPrevRoom(Room& previousRoom); //Should always be called in room constructor if room id>0, to ensure the last room is returnable.
    void decideRoomAdjective();


public:
    Room();
    Room(int id);
    void giveRoomAdjective(Adjectives::Adjective adjective);

    void addAdjoiningRoom(Room& adjoiningRoom); //adds an adjoining room

    void addCharToRoom(NPC character);
    void addEnemyToRoom(Enemy enemy);
    void addItemToRoom(Item item);

    int getRoomNum();
    Adjectives::Adjective getRoomAdj();

    void printAdjoiningRooms();
    void printEnemies();
    void printCharacters();
    void printItems();
};