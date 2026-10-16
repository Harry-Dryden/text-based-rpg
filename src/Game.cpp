#include "game.h"
#include "Logger.h"

bool Game::Init()
{
    currentState = GameState::MainMenu;
    return true;
}

void Game::Render()
{
    switch(currentState){ //currently no purpose for this switch but will probably be used when rendering more specific things eg combat
        case(GameState::MainMenu):
            output.PrintMenu(currentState);
            break;
        case(GameState::NewGame):
            output.PrintMenu(currentState);
            break;
        case(GameState::Exploration):
            output.PrintMenu(currentState);
            break;
        case(GameState::Combat):
            output.PrintMenu(currentState);
            break;
        case(GameState::CharacterScreen):
            output.PrintMenu(currentState);
            break;
        case(GameState::Inventory):
            output.PrintMenu(currentState);
            break;
    }
}

void Game::ProcessInputs()
{
    if(!(std::cin >> playerInput)){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

//void Game::ChangeGameState(GameState newState){}

void Game::Update()
{
    switch(currentState){
        case GameState::MainMenu:
            UpdateMainMenu();
            break;
        case GameState::NewGame:
            UpdateNewGameMenu();
            break;
        case GameState::Exploration:
            UpdateExploreMenu();
            break;
        case GameState::Combat:
            UpdateCombatMenu();
            break;
        case GameState::CharacterScreen:
            UpdateCharacterMenu();
            break;
        case GameState::Inventory:
            UpdateInventoryMenu();
            break;
    }
}

void Game::UpdateMainMenu(){
    switch(playerInput){
        case 1: //LOAD GAME
            std::cout << "Loading... \n";
            break;
        case 2: //NEW GAME
            std::cout << "Starting New Game! \n";
            currentState=GameState::NewGame;
            NewGame();
            break;
        case 3: //EXIT GAME
        //TO DO: Turn this into a method where things are cleaned up
            currentState=GameState::Exit;
            isRunning = false;
            break;
        default: //NOT AN OPTION
            std::cout << "Please enter the number of the option you want! \n";
            break;
    }
}

//Creates the player character etc.
void Game::NewGame(){
    player.PlayerCreation();
}

void Game::LoadWorld(){
    StarterRoom();
}

void Game::StarterRoom()
{
    //create the start room and add it to the createdRooms
    Room startRoom;
    currentRoom=&startRoom;
    createdRooms[numRooms]=&startRoom;
    numRooms++;

    //create a next room, which will be loaded upon entry
    Room nextRoom(numRooms);
    createdRooms[numRooms]=&nextRoom;
    numRooms++;

    //load the start room
    startRoom.addAdjoiningRoom(nextRoom);
    //add items etc.
}

Room* Game::NewRoom()
{
    Room newRoom(numRooms);
    numRooms++;
    return &newRoom;
}

void Game::LoadRoom()
{
}

void Game::UpdateNewGameMenu(){
    switch(playerInput){
        case 1: //START GAME
            std::cout << "Loading... \n";
            LoadWorld();
            currentState = GameState::Exploration;
            break;
        case 2: //CHECK CHARACTER
            std::cout << "Here is your character: \n";
            player.CheckPlayer(); //TO DO: CHANGE TO THE CharacterScreen Game state
            break;
        case 3: //REDO CHARACTER
            std::cout << "Starting New Game! \n";
            NewGame();
            break;
        case 4: //EXIT GAME
        //TO DO: Turn this into a method where things are cleaned up
            currentState=GameState::Exit;
            isRunning = false;
            break;
        default: //NOT AN OPTION
            std::cout << "Please enter the number of the option you want! \n";
            break;
    }
}

void Game::UpdateExploreMenu()
{
    switch(playerInput){
        case 1: //EXAMINE ROOM
        currentRoom->printAdjoiningRooms();
        //What enemies are there?
        //What items are there?
            break;
        case 2: //INTERACT WITH ITEM
        //Choose item to interact with
        //Say how to interact with it
        //Decide how interaction plays out
            break;
        case 3: //FIGHT ENEMY
        //Choose enemy to fight
        //Enter combat state
            break;
        case 4: //CHECK PLAYER
            std::cout << "Here is your character: \n";
            player.CheckPlayer(); //TO DO: CHANGE TO THE CharacterScreen Game state
            break;
        case 5: //CHECK INVENTORY
        //Enter inventory state
            break;
        case 6: //NEW ROOM
        //Show adjoining rooms
        //Player decides which room
        //Check if that is possible - eg. maybe it is blocked by enemy or locked
        //Change room
            break;
        default: //NOT AN OPTION
            std::cout << "Please enter the number of the option you want! \n";
            break;
    }
}

void Game::UpdateCombatMenu()
{
}

void Game::UpdateCharacterMenu()
{
}

void Game::UpdateInventoryMenu()
{
}

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
    if(!Init()){
        isRunning = false;
    }
    while (isRunning){
        Render();               //show the current state, tells the player what they can do
        ProcessInputs();        //asks the player what they want to do
        Update();               //apply the action
    }
}
