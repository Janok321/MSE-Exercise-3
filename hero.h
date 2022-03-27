
#ifndef ExerciseSheet3_HERO_H
#define ExerciseSheet3_HERO_H


#include <string>
#include <cstdlib>
#include "item.h"
#include "character.h"

#define HERO_GEAR_SIZE 2


class Hero : public Character{
protected:
    Item gear[HERO_GEAR_SIZE];


public:

    using Character::Character;

    virtual ~Hero() {
        std::cout << "Heldin Annina verabschiedet sich und reitet in den Sonnenuntergang" <<std::endl;
    }

    virtual void attack(Character* enemy) override;

    void sellItem(int index);


    int addGearItem(const Item& item);

    Item removeGearItem(int slot);

    Item *getGear(int index);

};


#endif //ExerciseSheet3_HERO_H
