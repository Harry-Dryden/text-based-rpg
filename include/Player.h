#pragma once

#include "Character.h"

#include <limits>

//The player class

class Player : public Character{
private:
    static constexpr int MAX_LEVEL = 100;
    static constexpr int STARTING_GOLD = 50;

    int experience;
    int expToLevel;

    void LevelUp();
    void ChooseAttributes(int assignablePoints);
    int SelectingAttribute();
    int SelectingAttributeValue(int assignablePoints);

public:
    Player();
    void PlayerCreation();
    void CheckForLevelUp();
    void CheckPlayer();
};