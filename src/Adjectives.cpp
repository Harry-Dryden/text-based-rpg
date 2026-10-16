#include "Adjectives.h"
#include <ctime>

namespace Adjectives
{
    const std::vector<Adjective> adjectiveList = {
        {AdjectiveID::Dark, "dark"},
        {AdjectiveID::Eerie, "eerie"},
        {AdjectiveID::Dripping, "dripping"},
        {AdjectiveID::Chilly, "chilly"},
        {AdjectiveID::Warm, "warm"},
        {AdjectiveID::Sharp, "sharp"},
        {AdjectiveID::Fiery, "fiery"},
        {AdjectiveID::Dangerous, "dangerous"},
        {AdjectiveID::Ancient, "ancient"},
        {AdjectiveID::Suspicious, "suspicious"}
    };

    const Adjective &randomAdjective()
    {
        srand(time(0));
        int randomNum = rand() % (adjectiveList.size()-1);

        return adjectiveList[randomNum];
    }
}