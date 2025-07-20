#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class archer : public combatUnit {
private:
    static int archerCounter;
    int arcID;
    int crit;
public:
    archer();
    archer(std::string name, int maxHP, int atk, int lvl, int crit);
    int getCrit() const;
    void setCrit(int crit);
    void takeDamage(int damage);
    void attack(combatUnit& target);
    bool isAlive() override;
    void print() const;
}; 