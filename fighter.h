
#ifndef EXERCISESHEET3_FIGHTER_H
#define EXERCISESHEET3_FIGHTER_H


#include "npc.h"

class Fighter : public NPC {

protected:
    int strength;

public:
    Fighter(const std::string &name, int health, int gold,
            int armor, int magicResistance, int strength) : NPC(name,
            health, gold, armor, magicResistance), strength(strength){}

    virtual ~Fighter(){}

    virtual void attack(Character* enemy) override;

// ________________Getter & Setter________________________

    int getStrength() const;
    void setStrength(int strength);
};

#endif //EXERCISESHEET3_FIGHTER_H
