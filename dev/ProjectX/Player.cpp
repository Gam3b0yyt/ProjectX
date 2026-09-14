#include "Player.h"

Player::Player()
{
    name = "Lynx";
    money = 1500;
    characterType = characterTypes::CLERIC;

    level = 1;
    experience = 0;
    health = 100;
    mana = 50;
    attack = 15;
    defense = 5;

    morale = 0;


}

const std::string& Player::getName() const { return name; }
int Player::getMoney() const { return money; }
characterTypes Player::getType() const { return characterType; }

int Player::getLevel() const { return level; }
int Player::getExperience() const { return experience; }
int Player::getHealth() const { return health; }
int Player::getMana() const { return mana; }
int Player::getAttack() const { return attack; }
int Player::getDefense() const { return defense; }


void Player::setName(const std::string& newName)
{
    if (!newName.empty()) name = newName;
}
void Player::setCharacterType(characterTypes newType) { characterType = newType; }
void Player::setMoney(int value) { money = value; }
void Player::setLevel(int value) { level = value; }
void Player::setExperience(int value) { experience = value; }
void Player::setHealth(int value) { health = value; }
void Player::setMana(int value) { mana = value; }
void Player::setAttack(int value) { attack = value; }
void Player::setDefense(int value) { defense = value; }
