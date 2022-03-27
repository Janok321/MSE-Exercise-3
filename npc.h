
#ifndef EXERCISESHEET3_NPC_H
#define EXERCISESHEET3_NPC_H

#include "character.h"

class NPC : public Character{

public:
    using Character::Character;

    virtual ~NPC() {
        std::cout << "Der Boesewicht " << name <<  " faehrt zurueck in die Hoelle" <<std::endl;
    }

};


#endif //EXERCISESHEET3_NPC_H
