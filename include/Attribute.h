#pragma once

#include <string>
//An attribute is a key part of a character
//Each character has 12 of these structs, making up their attributes

struct Attribute{
    std::string name; //The name of the attribute, e.g. 'Brute'
    int value; //The character's level of this attribute
};
