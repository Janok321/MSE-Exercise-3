

#ifndef EXERCISESHEET3_SORCERER_H
#define EXERCISESHEET3_SORCERER_H

#include "npc.h"

class Sorcerer : public NPC{

protected:
    int magicPower;

public:

    Sorcerer(const std::string &name, int health, int gold, int armor, int magicResistance, int magicPower)
    : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower){}


    virtual ~Sorcerer(){}

    virtual void attack(Character* enemy) override;

//_____________Getter & Setter________________
    int getMagicPower() const;

    void setMagicPower(int magicPower);

};

#endif //EXERCISESHEET3_SORCERER_H
