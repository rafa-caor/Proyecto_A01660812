#include "Mago.hpp"
#include "Personaje.hpp"
#include <iostream>
#include <string>

int wizard::wizardCounter = 0;

wizard::wizard()
    : combatUnit("Default Wizard " + std::to_string(wizard::wizID = ++wizardCounter), 100, 20, 1), mana(100) {
    type = "Wizard";
}
wizard::wizard(std::string name, int maxHP, int atk, int lvl, int mana)
    : combatUnit(name, maxHP, atk, lvl), mana(mana) {
    type = "Wizard";
}
int wizard::getMana() const {
    return mana;
}
void wizard::setMana(int mana) {
    if (mana >= 0) {
        mana = mana;
    } else {
        mana = 0;
    }
}
void wizard::takeDamage(int damage) {
    int heal = 0;
    combatUnit::takeDamage(damage);
    if (mana > 0 && percentHP() < 50 && percentHP() > 0) {
        heal = mana / 10;
        mana -= heal;
        std::cout << getName() << " uses healing and restores HP by " << heal << "!\n";}
    else if (mana <= 0 && percentHP() > 0 && percentHP() < 50) {
        std::cout << getName() << " has no mana left to heal!\n";
    }
}
void wizard::attack(combatUnit& target) {
    int dmg = getAtk();
    int critChance = rand() % 2;
    if (target.getLvl() > getLvl()) {
    dmg = 1 + (rand() % (getAtk( )/ 2));
    } else {
    dmg = (getAtk() / 2) + (rand() % (getAtk()/2)) + 1;
    }
    if (critChance > 0) {
        dmg += (mana / 10);
        std::cout << getName() << " casts a spell at " << target.getName() << " using a special kind of magic!\n";
        std::cout << "Dealed " << dmg << " damage! Amazing power!\n";
        target.takeDamage(dmg);
        mana -= (mana / 10);
    } else {
        std::cout << getName() << " cast a spell at " << target.getName() << " by infusing mana!\n";
        std::cout << getName() << " lands the spell and deals " << dmg << " damage to " <<target.getName() << "!\n";
        target.takeDamage(dmg);
    }
}
int wizard::percentMana() const {
    return (mana * 100) / mana;
}
void wizard::printBarMana() const {
    int barSize = 50;
    int filledSize = (mana * barSize) / mana;
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
    std::cout << "Mana: " << mana << "\n";
    printBarMana();
    std::cout << "\n";
}