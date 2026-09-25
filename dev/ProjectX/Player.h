#pragma once
#include "characterTypes.h"
#include "Item.h"
#include <vector>
#include

struct InventorySlot
{
    Item item;
    int quantity;
};

class Player
{
private:

    std::vector<InventorySlot> inventory;
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

    bool spendMana(int amount);
    void heal(int amount);

    bool levelUP();
	
    void addItem(const Item& item, int qty = 1);
    bool removeItem(const std::string& itemName, int qty = 1);
    bool hasItem(const std::string& itemName) const;
    const std::vector<InventorySlot>& getInventory() const;


};

