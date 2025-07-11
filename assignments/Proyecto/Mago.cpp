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
        maxMana = maxMana;
    } else {
        maxMana = 0;
    }
}
void wizard::setCurrentMana(int currentMana) {
    if (currentMana < 0) {
        currentMana = 0;
    } else if (currentMana > maxMana) {
        currentMana = maxMana;
    } else {
        currentMana = currentMana;
    }
}
void wizard::takeDamage(int damage) {
    int heal = 0;
    combatUnit::takeDamage(damage);
    if (currentMana > 0 && percentHP() < 50 && percentHP() > 0) {
        heal = currentMana / 10;
        currentMana -= heal;
        std::cout << getName() << " uses healing and restores HP by " << heal << "!\n";}
    else if (currentMana == 0 && percentHP() > 0 && percentHP() < 50) {
        std::cout << getName() << " has no mana left to heal!\n";
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
void wizard::print() const {
    combatUnit::print();
    std::cout << "Class attributes: " << "\n";
    std::cout << "Mana: " << getMana() << "\n";
    printBarMana();
    std::cout << "\n";
}