#include "Player.h"

Player::Player()
{
    name = "Lynx";
    money = 1500;
    characterType = characterTypes::CLERIC;

    level = 1;
    experience = 0;
    maxHealth = 100;
    health = 100;
    maxMana = 50;
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

int Player::getMaxHealth() const { return maxHealth;}

int Player::getMaxMana() const { return maxMana; }

int Player::getMorale() {return morale;}


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

void Player::setMaxHealth(int value) { maxHealth = value; }
void Player::setMaxMana(int value) { maxMana = value; }

void Player::setMorale(int value) { morale = morale + value;}

bool Player::isAlive() const
{
    if (health > 0)
    {
        return true;
    }
    else if (health <= 0)
    {
        return false;
    }
}
void Player::fullRestore() { health = maxHealth; mana = maxMana; }

bool Player::spendMana(int amount)
{
    if (amount < 0 || mana < amount) return false;
    mana -= amount;
    return true;
}

void Player::heal(int amount)
{
    health = std::min(maxHealth, health + std::max(0, amount));
}

bool Player::levelUP()
{
    int needed = level * 100;
    if (experience < needed) return false;

    experience -= needed;
    ++level;
    maxHealth += 20;
    maxMana += 10;
    attack += 4;
    defense += 2;
    fullRestore();
    return true;
}

void Player::addItem(const Item& item, int qty)
{
    for (auto& slot : inventory)
    {
        if (slot.item.name == item.name)
        {
            slot.quantity += qty;
            return;
        }
    }
    inventory.push_back({ item, qty });
}

bool Player::removeItem(const std::string& itemName, int qty)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if (it->item.name == itemName)
        {
            if (it->quantity < qty) return false;
            it->quantity -= qty;
            if (it->quantity <= 0) inventory.erase(it);
            return true;
        }
    }
    return false;
}

bool Player::hasItem(const std::string& itemName) const
{
    for (const auto& slot : inventory)
        if (slot.item.name == itemName) return true;
    return false;
}

const std::vector<InventorySlot>& Player::getInventory() const { return inventory; }

void Player::saveToFile(std::ofstream& file) const
{
	file << name << "\n";
	file << money << "\n";
	file << static_cast<int>(characterType) << "\n";
	file << level << "\n";
	file << experience << "\n";
	file << health << "\n";
	file << mana << "\n";
	file << attack << "\n";
	file << defense << "\n";
	file << maxHealth << "\n";
	file << maxMana << "\n";
	file << morale << "\n";



}

void Player::loadFromFile(std::ifstream& file)
{
	std::string line;

	std::getline(file, name);
	std::getline(file, line); money = std::stoi(line);
	std::getline(file, line); characterType = static_cast<characterTypes>(std::stoi(line));
	std::getline(file, line); level = std::stoi(line);
	std::getline(file, line); experience = std::stoi(line);
	std::getline(file, line); health = std::stoi(line);
	std::getline(file, line); mana = std::stoi(line);
	std::getline(file, line); attack = std::stoi(line);
	std::getline(file, line); defense = std::stoi(line);
	std::getline(file, line); maxHealth = std::stoi(line);
	std::getline(file, line); maxMana = std::stoi(line);
	std::getline(file, line); morale = std::stoi(line);

}