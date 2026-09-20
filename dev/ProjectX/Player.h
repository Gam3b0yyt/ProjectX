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

    int maxHealth;
    int maxMana;

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

    int getMaxHealth() const;
    int getMaxMana() const;
    
    int getMorale();

    void setName(const std::string& newName);
    void setCharacterType(characterTypes newType);
    void setMoney(int value);
    void setLevel(int value);
    void setExperience(int value);
    void setHealth(int value);
    void setMana(int value);
    void setAttack(int value);
    void setDefense(int value);

    void setMaxHealth(int value);
    void setMaxMana(int value);

    void setMorale(int value);

    bool isAlive() const;
    void fullRestore();

	


};

