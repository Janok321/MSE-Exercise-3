
#include "character.h"


bool Character::fight(Character* enemy) {
    while (health > 0 && enemy->getHealth() > 0) { //this Pointer optional
        attack(enemy); //this Pointer optional
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }
    if (health > 0) {
        std::cout << enemy->getName() << " fiel in Ohnmacht! " << name <<
                  " hat noch " << health << " Lebenspunkte uebrig!" << std::endl;
    return this->health > 0;
    }
    return false;
}

Item Character::retrieveRandomLoot(Character *enemy){
    for (int i = 0; i < 10; i++) {
        int dice = std::rand() % CHARACTER_INVENTORY_SIZE;
        Item loot = enemy->removeInventarItem(dice);
        if (loot.isValid()) {
            if (addInventarItem(loot) < 0) {
                    std::cout << "Kein Platz mehr vorhanden!" << std::endl;
            }
            else {
                std::cout << loot.getName() << " wurde zum Inventar von "
                << this->name << " hinzugefuegt." << std::endl;
            }
            return loot;
        }
    }
    Item noloot;
    return noloot;
}

int Character::addInventarItem(const Item& item){               //Funktion fügt Gegenstand hinzu, wenn an der Indexstelle noch keiner vorhanden
    if (item.isValid()){
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
            if(!inventory[i].isValid()){
                inventory[i] = item;
                //this->inventory[i].setIsValid(true); Nicht nötig, da durch if Schleife überprüft
                return i;
            }
        }
    }
    return -1;
}

Item Character::removeInventarItem(int slot){
    if( slot >= 0 && slot < CHARACTER_INVENTORY_SIZE){
        Item retval = inventory[slot];
        inventory[slot].setValid(false);
        return retval;
    }
    Item retval;
    return retval;
}

