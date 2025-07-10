#include "Arquero.hpp"
#include "Personaje.hpp"
#include <iostream>
#include <string>

int archer::archerCounter = 0;

archer::archer()
    : combatUnit("Default Archer " + std::to_string(archer::arcID = ++archerCounter), 80, 20, 1), crit(30) {
    type = "Archer";
}
archer::archer(std::string name, int maxHP, int atk, int lvl, int crit)
    : combatUnit(name, maxHP, atk, lvl), crit(crit) {
    type = "Archer";
}
int archer::getCrit() const{
    return crit;
}
void archer::setCrit(int crit) {
    if (crit >= 0) {
        crit = crit;
    } else {
        crit = 0;
    }
}
void archer::attack(combatUnit& target) {
    int dmg = getAtk();
    int critChance = rand() % 2;
    if (target.getLvl() > getLvl()) {
    dmg = 1 + (rand() % (getAtk( )/ 2));
    } else {
    dmg = (getAtk() / 2) + (rand() % (getAtk()/2)) + 1;
    }
    if (critChance > 0) {
        dmg += crit;
        std::cout << getName() << " aims at " << target.getName() << " steadily...\n";
        std::cout << "Dealed " << dmg << " damage! Bullseye!\n";
        target.takeDamage(dmg);
    } else {
        std::cout << getName() << " draws the bow and aims at " << target.getName() << " with furious eyes!\n";
        std::cout << getName() << " lands a shot and deals " << dmg << " damage to " <<target.getName() << "!\n";
        target.takeDamage(dmg);
    }
}
void archer::print() const {
    combatUnit::print();
    std::cout << "Class attributes: " << "\n";
    std::cout << "Critical attack: +" << crit << "\n";
    printBarHP();
    std::cout << "\n";
}