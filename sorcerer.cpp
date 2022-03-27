//
// Created by User on 18.03.2022.
//

#include "sorcerer.h"

void Sorcerer::attack(Character* enemy){ //Pointer würde auch gehen
    int damage = 5 + (std::rand() % 6) + magicPower - enemy->getMagicResistance();
    std::cout << this->name << " trifft " <<enemy->getName()<< " fuer " << damage << " Lebenspunkte!" << std::endl;
    enemy->setHealth(enemy->getHealth() - damage);
}

int Sorcerer::getMagicPower() const {
    return magicPower;
}

void Sorcerer::setMagicPower(int magicPower) {
    Sorcerer::magicPower = magicPower;
}

//damage = rand(5, 10) + MagicPower - MagicResistance
