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
        this -> crit = crit;
    } else {
        this -> crit = 0;
    }
}
void archer::takeDamage(int damage) {
    if ((rand() % 100) < 15) {
        std::cout << getName() << " dodges the attack and avoids taking damage!\n";
    } else {
        combatUnit::takeDamage(damage);
        if (percentHP() < 20) {
            int critBoost = 5 + (50 - percentHP()) / 10;
            crit += critBoost;
            std::cout << getName() << " is in danger! Critical chance increased by "
                      << critBoost << "%!\n";
        }
    }
    if (!isAlive()) {
        std::cout << getName() << " has fallen in battle!\n";
    } else {
        std::cout << getName() << " is still standing strong with " << getCurrentHP() << " HP left!\n";
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
bool archer::isAlive() {
    return getCurrentHP() > 0;
}
void archer::print() const {
    combatUnit::print();
    std::cout << "Class attributes: " << "\n";
    std::cout << "Critical attack: +" << crit << "\n";
    printBarHP();
    std::cout << "\n";
}