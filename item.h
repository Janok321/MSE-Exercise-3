
#ifndef ExerciseSheet3_ITEM_H
#define ExerciseSheet3_ITEM_H


#include <string>

class Item {

private:
    std:: string name;
    int gold;
    bool valid;

public:

    Item() : name ("Default"), gold(0), valid(false){}

    Item(const std::string &name, int gold) : name(name), gold(gold),
    valid(true){}

    //~Item(){} Optional


//_________________Getter & Setter________________

void setName(const std::string& name){
    if (!name.empty()){
        this->name = name;
    }
}

const std::string& getName() const{
    return this->name;
}


bool isValid() const{
    return this->valid;
}

void setValid(bool isValid){
    if (!isValid){
        this->valid = false;
    }
    else{
        this->valid = true;
    }
}

void setGold (int gold){
    if (gold >= 0){
        this->gold = gold;
    }
}

int getGold () const{
    return this->gold;
}

};

#endif //ExerciseSheet3_ITEM_H
