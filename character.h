
#ifndef ExerciseSheet3_CHARACTER_H
#define ExerciseSheet3_CHARACTER_H

#include <string>
#include "item.h"
#include <iostream>

#define CHARACTER_INVENTORY_SIZE 10


class Character {

protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item inventory[CHARACTER_INVENTORY_SIZE];

public:

    Character (const std::string &name, int health, int gold,
               int armor, int magicResistance) : name(name),
               health(health), gold(gold), armor(armor), magicResistance(magicResistance){
        for(int i = 0; i < CHARACTER_INVENTORY_SIZE; i++)
        {
            this->inventory[i] = Item();
        }
    }

    virtual ~Character(){}


    virtual void attack(Character* enemy) = 0;

    bool fight(Character* enemy);

    int addInventarItem(const Item& item);

    Item removeInventarItem(int slot);

    Item retrieveRandomLoot(Character *enemy);


// ______________________________Getter & Setter_______________________________________________

    const std::string& getName() const {
        return this->name; // this Pointer optional
    }

    void setName (const std::string &_name){
        if(!_name.empty()){
            this->name = _name;
        }
    }

    void setHealth(int _health){
        if (_health < 0){
            this->health = 0;
        }
        else {
            this->health = _health; // this Pointer mandatory, da sonst Überschattung
        }
    }

    int getHealth() const{
        return this->health; //this Pointer optional, da keine Überschattung
    }

    Item* getInventory(int slot){
        if (slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
            return &inventory[slot];
        }
        else {
            return nullptr;
        }
    }

    int getGold() const{
        return gold;
    }

    void setGold(int gold){
        if (gold >= 0){
            this->gold = gold;
        }
    }

    int getArmor() const {
        return armor;
    }

    void setArmor(int armor) {
        this->armor = armor;
    }

    int getMagicResistance() const {
        return magicResistance;
    }

    void setMagicResistance(int _magicResistance) {
        this->magicResistance = _magicResistance;
    }


};

#endif //ExerciseSheet3_CHARACTER_H
