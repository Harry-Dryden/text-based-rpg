#include "Output.h"

void Output::PrintMenu(GameState currentState)
{
    switch(currentState){
        case(GameState::MainMenu):
        PrintMainMenu();
        break;
        case(GameState::NewGame):
        PrintNewGameMenu();
        break;
        case(GameState::Exploration):
        PrintExplorationMenu();
        break;
        case(GameState::Combat):
        PrintCombatMenu();
        break;
        case(GameState::CharacterScreen):
        PrintCharacterMenu();
        break;
        case(GameState::Inventory):
        PrintInventoryMenu();
        break;
    }
}

//void Output::RenderUI(GameState currentState)

//Prints the main menu for the game
void Output::PrintMainMenu()
{
    std::cout<< "Welcome to Prototype 1: The RPG \n";
    std::cout<< "What would you like to do? \n";
    std::cout<< "1. Load Game \n";
    std::cout<< "2. Start New Game \n";
    std::cout<< "3. Exit \n";
}

//Prints the new game menu
void Output::PrintNewGameMenu()
{
    std::cout<< "What would you like to do? \n";
    std::cout<< "1. Start the Game \n";
    std::cout<< "2. Check Character \n";
    std::cout<< "3. Redo Character \n";
    std::cout<< "4. Exit \n";
}

//Prints the exploration/generic menu
void Output::PrintExplorationMenu()
{
    std::cout<< "What would you like to do? \n";
    std::cout<< "1. Examine the Room \n";
    std::cout<< "2. Interact with an Item \n";
    std::cout<< "3. Fight an Enemy \n";
    std::cout<< "4. Check Character \n";
    std::cout<< "5. Check Inventory \n";
    std::cout<< "6. Move to another Room \n";
}

//prints exploration UI - TO DO LATER
void Output::PrintExplorationUI()
{
    //draw room?
}

//prints the combat menu
void Output::PrintCombatMenu()
{
    std::cout<< "What would you like to do? \n";
    std::cout<< "1. Attack the enemy \n";
    std::cout<< "2. Heal yourself \n";
    std::cout<< "3. Analyse your situation \n";
    std::cout<< "4. Check inventory \n";
    std::cout<< "5. Retreat \n";
}

//prints combat UI - TO DO LATER
void Output::PrintCombatUI()
{
    //draw enemy?
}

void Output::PrintCharacterMenu()
{
}

void Output::PrintInventoryMenu()
{
}
