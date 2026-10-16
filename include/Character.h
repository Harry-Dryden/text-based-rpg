#pragma once

#include "Attribute.h"
#include "Skill.h"
#include "Weapon.h"
#include "Item.h"
#include <iostream>
#include <array>

//Character is the parent class of NPC and Player
//It represents a non-specific type of character in the world

class Character
{
protected:
    static constexpr int ATTRIBUTES_NUM = 12;
    static constexpr int SKILLS_NUM = 12; //TO DO: SORT OUT SKILLS AND ASSIGN NUMBER
    static constexpr int BASE_INVENTORY_SIZE = 10; //TO DO: Make this dynamic based on strength
    static constexpr int BASE_HEALTH = 100;
    static constexpr int BASE_CRIT_CHANCE = 5;
    static constexpr int BASE_EXP_TO_NEXT_LVL = 100;
    static constexpr int STARTING_ATTRIBUTE_LVL = 10;

    std::string name; //The character's name
    Weapon equippedWeapon;
    std::array<Item,BASE_INVENTORY_SIZE> inventory;
    std::array<Attribute,ATTRIBUTES_NUM> attributes;
    std::array<Skill,SKILLS_NUM> skills;
    int level;
    bool boolAlive;
    int health;

    //derived stats:
    int maxHealth;
    int armourStat;
    int critChance;
    //(remember to reCalcValues() when these should/could be changed)

    void equipWeapon(Weapon weapon);

    void TakeDamage(int damage);
    void DealDamage(Character target);
    void HealHealth(int heal);
    void Death(); //Called when health reaches 0

    void initAttributes(); //Fills the attribute array with attributes
    void PrintAttributes();
    void PrintAttribute(int choice);
    void IncreaseAttribute(int choice, int points);

    void reCalcValues();    //reCalculates the base stats using the methods below
    void calcMaxHealth();
    void calcArmourStat();
    void calcCritChance();

public:
    Character();
    Character(int maxHP, int lvl);
    bool IsAlive();

};