#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class warrior : public combatUnit {
private:
    static int warriorCounter;
    int warID;
    int rage;
public:
    warrior();
    warrior(std::string name, int maxHP, int atk, int lvl, int rage);
    int getRage() const;
    void setRage(int rage);
    void attack(combatUnit& target);
    void print() const;
}; 