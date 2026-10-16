#pragma once

#include "States.h"
#include <iostream>

class Output{
    private:

    public:
        void PrintMenu(GameState currentState);
        void PrintMainMenu();
        void PrintNewGameMenu();

        void PrintExplorationMenu();
        void PrintExplorationUI();

        void PrintCombatMenu();
        void PrintCombatUI();
        
        void PrintCharacterMenu();
        void PrintInventoryMenu();
};