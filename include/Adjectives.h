#pragma once


#include <string>
#include <vector>
//An adjective is used to describe something
//For example, a room may be Dark.
//This could be split into adjective between things at some point.

namespace Adjectives {

    enum class AdjectiveID
    {
        Dark,
        Eerie,
        Dripping,
        Chilly,
        Warm,
        Sharp,
        Fiery,
        Dangerous,
        Ancient,
        Suspicious,
    };

    struct Adjective
    {
        AdjectiveID adjEnumId;
        std::string adjStr;
    };


    extern const std::vector<Adjective> adjectiveList;

    const Adjective &randomAdjective();
}