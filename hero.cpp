//
#include <iostream>
#include <string>
#include <cstdlib>
#include "hero.h"


//Die Heldin greift einen spezifizierten Gegner an und reduziert dessen Lebenspunkte zufällig um einen Wert
// zwischen 15 und 25
void Hero::attack(Character* enemy){ //Pointer würde auch gehen
    int damage = 15 + std::rand() % 11 - armor;
    std::cout << this->name << " trifft " <<enemy->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}



void Hero::sellItem(int index){
    if (index >= 0 && index < CHARACTER_INVENTORY_SIZE) {
        if (inventory[index].isValid()) {                             //alternativ:
            setGold(getGold()+inventory[index].getGold());        //this->gold+= this->inventory[index].getGold();
            inventory[index].setValid(false);                                // Setzt IsValid des Items auf false
            std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. ";
            std::cout << name << " besitzt nun " << gold << " Gold." << std::endl;
        }
    }
}


int Hero::addGearItem(const Item& item){
    if (item.isValid()){
        for (int i = 0; i < HERO_GEAR_SIZE; i++) {
            if(!gear[i].isValid()) {
                gear[i] = item;
                return i;
            }
        }
    }
    return -1;
}


Item Hero::removeGearItem(int slot){
    if(slot >= 0 && slot < HERO_GEAR_SIZE){
        Item retval = gear[slot];
        this->gear[slot].setValid(false); //alternativ initItem()
        return retval;
    }
    Item retval;
    return retval;

}

Item *Hero::getGear(int index) {
    Item &item = this->gear[index];
    return &item;
}


//Wenn die Heldin einen Feind besiegt hat, soll ja ein zufällig ausgewählter Gegenstand aus dem Inventar des Feindes
// in das Inventar der Heldin übertragen werden. Um die weitere Entwicklung zu vereinfachen soll diese Funktionalität
// in der Objektfunktion Item retrieveRandomLoot() gekapselt werden, die einen zufälligen Gegenstand aus dem Inventar
// entfernt und zurückgibt. Überlegen Sie sich selbstständig, in welche Klasse diese Objektfunktion am besten hineinpasst.

