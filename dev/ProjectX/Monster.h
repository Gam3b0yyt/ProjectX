#pragma once
#include <string>
#include "monsterTypes.h"
class Monster
{
private:
    std::string name;
    monsterType type;
    int health;
    int maxHealth;
    int attack;
    int defense;
    int experienceReward;

public:
    Monster();
    Monster(const std::string& monsterName, monsterType monsterTypeValue, int hp, int attackValue, int defenseValue, int expReward);

    std::string getName() const;
    monsterType getType() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttack() const;
    int getDefense() const;
    int getExperienceReward() const;

    void takeDamage(int amount);
    bool isAlive() const;
};



};

