#include "Player.h"

//levels up the player
//should be called when experience has surpassed expToLevel
//TO DO: Change the magic numbers in this function
void Player::LevelUp()
{
    std::cout << "NEW LEVEL! \n";
    level +=1;
    experience -= expToLevel;
    expToLevel = level * 100;
    ChooseAttributes(5);
    std::cout << "You are now level " << level << " and have " << experience << " / " << expToLevel << " until the next level! \n";
}

//Allows the player to assign some points into their attributes
void Player::ChooseAttributes(int assignablePoints)
{
    while(assignablePoints > 0){ //while there is still assignable points remaining,
        PrintAttributes(); //print the player's current attributes
        std::cout << "======== \n";
        int choiceAttribute = SelectingAttribute(); //select an attribute
        int assignedPoints = SelectingAttributeValue(assignablePoints); //select how many points to put into it
        assignablePoints -= assignedPoints; //remove the assigned points
        IncreaseAttribute(choiceAttribute, assignedPoints); //increase the attribute
        std::cout << "======== \n";
        PrintAttribute(choiceAttribute); //tell the player what has happened
    }
}

//Allows the player to select the attribute to increase
int Player::SelectingAttribute()
{
    int choiceAttribute = 0;
    bool selectingAttribute = true;
    while(selectingAttribute){ //while an attribute is being selected
        std::cout << "Which attribute would you like to improve? \n";
        if(std::cin >> choiceAttribute){
            if(choiceAttribute>0 && choiceAttribute<=ATTRIBUTES_NUM){ //If a correct value corresponding to an attribute has been chose
                return choiceAttribute -1; //Transfer to the array value with the -1  
            } else {
                std::cout << "Out of attribute range! \n";
            }
        } else {
            std::cout << "Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        }
    }
}

//Allows the player to enter how much they want to increase the attribute by
int Player::SelectingAttributeValue(int assignablePoints)
{
    bool assigningPoints = true;
    int assignedPoints=0;
    while(assigningPoints){
        std::cout << "By how many points? You have " << assignablePoints << " remaining. \n";
        if(std::cin >> assignedPoints){
            if (assignedPoints<=assignablePoints){ //If an allowed number of points have been entered
                return assignedPoints;
            } else {
                std::cout << "Too many points. \n";
            }
        } else {
            std::cout << "Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore('\n');
        }
    }
}

Player::Player()
{
}

//initialises the player
void Player::PlayerCreation()
{
    level = 1;
    std::cout << "Enter your character's name: \n";
    std::cin >> name; 
    ChooseAttributes(15);
}

//checks for level up
//maybe when the player rests?
void Player::CheckForLevelUp()
{
    if (experience > expToLevel){
        LevelUp();
    }
}

//Shows the player their current level and attributes
void Player::CheckPlayer(){
    std::cout << "You are " << name << ",\n";
    std::cout << "At level " << level << ",\n";
    std::cout << "With the attributes: \n";
    PrintAttributes();
}