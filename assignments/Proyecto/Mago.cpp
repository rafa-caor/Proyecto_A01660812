#include "Mago.hpp"
#include "Personaje.hpp"
#include <iostream>
#include <string>

int wizard::wizardCounter = 0;

wizard::wizard()
    : combatUnit("Default Wizard " + std::to_string(wizard::wizID = ++wizardCounter), 100, 20, 1), maxMana(100), currentMana(100) {
    type = "Wizard";
}
wizard::wizard(std::string name, int maxHP, int atk, int lvl, int maxMana)
    : combatUnit(name, maxHP, atk, lvl), maxMana(maxMana), currentMana(maxMana) {
    type = "Wizard";
}
int wizard::getMaxMana() const {
    return maxMana;
}
int wizard::getCurrentMana() const {
    return currentMana;
}
std::string wizard::getMana() const {
    return std::to_string(currentMana) + "/" + std::to_string(maxMana);
}
void wizard::setMaxMana(int maxMana) {
    if (maxMana >= 0) {
        this -> maxMana = maxMana;
    } else {
        this -> maxMana = 0;
    }
}
void wizard::setCurrentMana(int currentMana) {
    if (currentMana < 0) {
        currentMana = 0;
    } else if (currentMana > maxMana) {
        this -> currentMana = maxMana;
    } else {
        this -> currentMana = currentMana;
    }
}
void wizard::takeDamage(int damage) {
    combatUnit::takeDamage(damage);
    if (getCurrentMana() > 0 && percentHP() < 50 && percentHP() > 0) {
        int heal = currentMana / 10;
        setCurrentHP(getCurrentHP() + heal);
        setCurrentMana(currentMana -= heal);
        std::cout << getName() << " uses healing and restores HP by " << heal << "!\n";}
    else if (currentMana == 0 && percentHP() > 0 && percentHP() < 50) {
        std::cout << getName() << " has no mana left to heal!\n";
    }
    if (!isAlive()) {
        std::cout << getName() << " has fallen in battle!\n";
    } else {
        std::cout << getName() << " is still standing strong with " << getCurrentHP() << " HP and " << getCurrentMana() << " mana left!\n";
    }
}
void wizard::attack(combatUnit& target) {
    int dmg = getAtk();
    int critDmg = getAtk() + (currentMana / 10);
    int critChance = rand() % 3;
    if (target.getLvl() > getLvl()) {
    dmg = 1 + (rand() % (getAtk( )/ 2));
    } else {
    dmg = (getAtk() / 2) + (rand() % (getAtk()/2)) + 1;
    }
    if (critChance == 0) {
        std::cout << getName() << " casts a spell at " << target.getName() << " using a special kind of magic!\n";
        std::cout << getName() << " infused " << currentMana/10 << " mana to enhance the spell!\n";
        std::cout << "Dealed " << critDmg << " damage! Amazing power!\n";
        target.takeDamage(dmg);
        currentMana -= currentMana/10;
    } else {
        std::cout << getName() << " casts a spell at " << target.getName() << " by channeling mana!\n";
        std::cout << getName() << " lands the spell and deals " << dmg << " damage to " <<target.getName() << "!\n";
        target.takeDamage(dmg);
    }
}
int wizard::percentMana() const {
    return (currentMana * 100) / maxMana;
}
void wizard::printBarMana() const {
    int barSize = 50;
    int filledSize = (currentMana * barSize) / maxMana;
    int emptySize = barSize - filledSize;
    std::cout << "[";
    for (int i = 0; i < filledSize; ++i) {
        std::cout << "=";
    }
    for (int i = 0; i < emptySize; ++i) {
        std::cout << "-";
    }
    std::cout << "] " << percentMana() << "% Mana\n";
}
bool wizard::isAlive() {
    if (getCurrentHP() > 0) return true;
    if (currentMana >= 30) {
        int newMana = currentMana - 30;
        if(newMana < 0) newMana = 0;
        setCurrentMana(newMana);
        int newHP = getMaxHP() / 4;
        setCurrentHP(newHP);
        std::cout << getName() << " uses the last of their mana to revive themselves!\n";
        std::cout << getName() << " has " << getCurrentHP() << " HP and " << getCurrentMana() << " mana left!\n";
        return true;
    }
    return false;
}
void wizard::print() const {
    combatUnit::print();
    std::cout << "Class attributes: " << "\n";
    std::cout << "Mana: " << getMana() << "\n";
    printBarMana();
    std::cout << "\n";
}