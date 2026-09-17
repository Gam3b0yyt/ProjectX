#include "Monster.h"

Monster::Monster()
	: name("Slime"), type(monsterType::BEAST), health(40), maxHealth(40), attack(8), defense(2), experienceReward(25) {
}
Monster::Monster(const std::string& monsterName, monsterType monsterTypeValue, int hp, int attackValue, int defenseValue, int expReward)
	: name(monsterName), type(monsterTypeValue), health(hp), maxHealth(hp), attack(attackValue), defense(defenseValue), experienceReward(expReward) {
}

std::string Monster::getName() const { return name; }
monsterType Monster::getType() const { return type; }
int Monster::getHealth() const { return health; }
int Monster::getMaxHealth() const { return maxHealth; }
int Monster::getAttack() const { return attack; }
int Monster::getDefense() const { return defense; }
int Monster::getExperienceReward() const { return experienceReward; }
void Monster::takeDamage(int amount) { health = health - amount; }
bool Monster::isAlive() const { return health > 0; }
