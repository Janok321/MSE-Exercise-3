#include <cstdlib>
#include <ctime>
#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"


int main() {
    std::srand(time(0));

    Hero heldin("Annina", 300, 100, 10, 5);

    Sorcerer pascal("Pascal", 50, 10000, 100, 5, 15);
    Item item1("Diamand", 1000);
    pascal.addInventarItem(item1);
    Item item2("Zauberstab", 100);
    pascal.addInventarItem(item2);
    Item item3("Zauberrobe", 200);
    pascal.addInventarItem(item3);

    Fighter matthias("Matthias", 100, 1000, 10, 5, 15);
    Item item4("Rubin", 800);
    matthias.addInventarItem(item4);
    Item item5("Schwert", 100);
    matthias.addInventarItem(item5);
    Item item6("Ruestung", 200);
    matthias.addInventarItem(item6);

    if (heldin.fight(&pascal)) {
        heldin.retrieveRandomLoot(&pascal);

        if (heldin.fight(&matthias)){
            heldin.retrieveRandomLoot(&pascal);
        }
    }

    if (heldin.getHealth() > 0) {
        for (int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
            heldin.sellItem(i);
        }
    }
}





