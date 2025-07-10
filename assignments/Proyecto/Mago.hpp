#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class wizard : public combatUnit {
private:
    static int wizardCounter;
    int wizID;
    int mana;
public:
    wizard();
    wizard(std::string name, int maxHP, int atk, int lvl, int mana);
    int getMana() const;
    void setMana(int mana);
    void takeDamage(int damage);
    void attack(combatUnit& target);
    int percentMana() const;
    void printBarMana() const;
    void print() const;
}; 