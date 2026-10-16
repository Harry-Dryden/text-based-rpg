#pragma once

#include "Player.h"
#include "States.h"
#include "Output.h"
#include "Room.h"

//The game class

class Game
{
private:
    static constexpr int MAX_ROOMS = 12;

    GameState currentState;
    Output output;
    Player player;

    std::array<Room*, MAX_ROOMS> createdRooms;
    Room* currentRoom;
    int numRooms;

    int playerInput;

    bool isRunning;

    bool Init();
    
    void Render();
    void ProcessInputs();
    void Update();

    void UpdateMainMenu();
    void UpdateNewGameMenu();
    void UpdateExploreMenu();
    void UpdateCombatMenu();
    void UpdateCharacterMenu();
    void UpdateInventoryMenu();

    void LoadWorld();

    void StarterRoom();
    Room* NewRoom(); //create a new room to be an adjoining room
    void LoadRoom(); //load a room when it is entered

    void NewGame();

public:
    Game();
    ~Game();

    void Run();
};