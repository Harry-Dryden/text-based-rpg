#pragma once
#include <string>
#include "Adjectives.h"

//An item is something that can be found in the world
//It is generic, but something may be just an item
//Its children classes have different methods
//They are: Weapon, 
class Item{
    protected:
        std::string name;
        std::string adjective;
    public:
};