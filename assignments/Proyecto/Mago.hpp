#pragma once
#include <iostream>
#include <string>
#include "Personaje.hpp"

class wizard : public combatUnit {
private:
    static int wizardCounter;
    int wizID;
    int maxMana;
    int currentMana;
public:
    wizard();
    wizard(std::string name, int maxHP, int atk, int lvl, int mana);
    int getMaxMana() const;
    int getCurrentMana() const;
    std::string getMana() const;
    void setMaxMana(int mana);
    void setCurrentMana(int mana);
    void takeDamage(int damage);
    void attack(combatUnit& target);
    int percentMana() const;
    void printBarMana() const;
    void print() const;
}; 