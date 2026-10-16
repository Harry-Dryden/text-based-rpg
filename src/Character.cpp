#include "Character.h"


void Character::equipWeapon(Weapon weapon)
{
    equippedWeapon = weapon;
}

// The character takes damage which is subtracted from their health
void Character::TakeDamage(int damage)
{
    health = health - damage;
    if (health <= 0 ){
        Death();
    }
}

void Character::DealDamage(Character target)
{
    int equippedWeaponDamage = 1; //Get the damage of equipped weapon
    //do dice roll for crit chance
    //do dice roll for hit chance- skill related
    int damage = equippedWeaponDamage * attributes[0].value; //equipped weapon * BRUTE
    target.TakeDamage(damage);
    std::cout<< "Hit! " << target.name << " takes " << damage << " damage!";
}

void Character::HealHealth(int heal)
{
    health = health + heal;
}

void Character::Death()
{
    boolAlive = false;
}

//TO DO: Set a more realistic starting number for attributes
void Character::initAttributes()
{
    //BODY
    attributes[0] =  {"Brute", STARTING_ATTRIBUTE_LVL};          //Affects:  Physical Damage, Stamina           USED
    attributes[1] =  {"Dexterity", STARTING_ATTRIBUTE_LVL};      //Affects:  Stamina, Speed, Dodge Chance
    attributes[2] =  {"Fortitude", STARTING_ATTRIBUTE_LVL};      //Affects:  Health                             USED
    attributes[3] =  {"Subtlety", STARTING_ATTRIBUTE_LVL};       //Affects:  Stealth
    //MIND
    attributes[4] =  {"Perception", STARTING_ATTRIBUTE_LVL};     //Affects:  Stealth, Utility Magic
    attributes[5] =  {"Spirituality", STARTING_ATTRIBUTE_LVL};   //Affects:  Offensive Magic, Artifacts' Power  
    attributes[6] =  {"Intelligence", STARTING_ATTRIBUTE_LVL};   //Affects:  Experience Gain
    attributes[7] =  {"Charm", STARTING_ATTRIBUTE_LVL};          //Affects:  Speech
    //SOUL
    attributes[8] =  {"Resistance", STARTING_ATTRIBUTE_LVL};     //Affects:  Non-physical defense
    attributes[9] =  {"Craft", STARTING_ATTRIBUTE_LVL};          //Affects:  Crafting
    attributes[10] = {"Empathy", STARTING_ATTRIBUTE_LVL};        //Affects:  Speech, Healing magic
    attributes[11] = {"Luck", STARTING_ATTRIBUTE_LVL};           //Affects:  Everything a small amount          USED
}

void Character::PrintAttributes()
{
    for(int i=0; i<ATTRIBUTES_NUM; i++){
        PrintAttribute(i);
    }
}

void Character::PrintAttribute(int choice)
{
    std::cout << choice+1 << ". " << attributes[choice].name << ": " << attributes[choice].value << "\n";
}

void Character::IncreaseAttribute(int choice, int points)
{
    attributes[choice].value += points;
}

//recalculates maxHealth and other values that are derived from attributes upon a level up
//these methods can, of course, be called individually - for example, when changing armour
void Character::reCalcValues()
{
    calcMaxHealth();
    calcArmourStat();
    calcCritChance();
}

void Character::calcMaxHealth()
{
    maxHealth = BASE_HEALTH * attributes[2].value; //100*FORTITUDE
}

void Character::calcArmourStat()
{
    armourStat; //TO DO: Add armour slots and have equipped armour update this value.
}

void Character::calcCritChance()
{
    int critChanceModifiers = 1; //PLACEHOLDER VAR
    //TO DO: add a crit chance modifier that can be inserted into the following calculation
    critChance = ((BASE_CRIT_CHANCE * critChanceModifiers)+ (attributes[11].value / 10))/100; // ((5 * 1) + (LUCK/10)) / 100 , so 6% at 10 Luck
}

Character::Character()
{
    initAttributes();
}

Character::Character(int maxHP, int lvl)
{
    maxHealth = maxHP;
    level = lvl;
    boolAlive = true;
    health = maxHealth;
}

bool Character::IsAlive()
{
    return boolAlive;
}