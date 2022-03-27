//
// Created by User on 20.03.2022.
//

#include "fighter.h"

void Fighter::attack(Character* enemy){ // Referenz & statt Pointer würde auch gehen
    int damage = 5 + (std::rand() % 6) + this->strength - enemy->getArmor();
    std::cout << name << " trifft " <<enemy->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl; // this Pointer optional
    enemy->setHealth((enemy->getHealth() - damage));
}

//_____________________Getter & Setter_________________________
int Fighter::getStrength() const {
    return strength;
}

void Fighter::setStrength(int strength) {
    Fighter::strength = strength;
}


