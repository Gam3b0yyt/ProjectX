#pragma once
#include <string>
#include "characterTypes.h"

class Player
{
private:
    std::string name;
    int money;
    characterTypes characterType;

    int level;
    int experience;
    int health;
    int mana;
    int attack;
    int defense;

    int morale; 
 

public:
	Player();

    const std::string& getName() const;
    int getMoney() const;
    characterTypes getType() const;
    int getLevel() const;
    int getExperience() const;
    int getHealth() const;
    int getMana() const;
    int getAttack() const;
    int getDefense() const;

    void setName(const std::string& newName);
    void setCharacterType(characterTypes newType);
    void setMoney(int value);
    void setLevel(int value);
    void setExperience(int value);
    void setHealth(int value);
    void setMana(int value);
    void setAttack(int value);
    void setDefense(int value);




	


};

