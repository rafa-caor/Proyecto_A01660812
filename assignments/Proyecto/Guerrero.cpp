#include "Guerrero.hpp"
#include "Personaje.hpp"
#include <iostream>
#include <string>

int warrior::warriorCounter = 0;

warrior::warrior()
    : combatUnit("Default Warrior " + std::to_string(warrior::warID = ++warriorCounter), 120, 25, 1), rage(10) {
    type = "Warrior";
}
warrior::warrior(std::string name, int maxHP, int atk, int lvl, int rage)
    : combatUnit(name, maxHP, atk, lvl), rage(rage) {
    type = "Warrior";
}
int warrior::getRage() const {
    return rage;
}
void warrior::setRage(int rage) {
    if (rage >= 0) {
        this -> rage = rage;
    } else {
        this -> rage = 0;
    }
}
void warrior::takeDamage(int damage) {
    combatUnit::takeDamage(damage);
    int rageGenerated = damage / 3;
    if (rageGenerated > 0) {
        rage += rageGenerated;
        std::cout << getName() << " gains " << rageGenerated << " rage from the damage taken!\n";
    }
    if(!isAlive()) {
        std::cout << getName() << " has fallen in battle!\n";
    } else {
        std::cout << getName() << " is still standing strong with " << getCurrentHP() << " HP left!\n";
    }
}
void warrior::attack(combatUnit& target) {
    int dmg = getAtk();
    if (target.getLvl() > getLvl()) {
    dmg = 1 + (rand() % (getAtk( )/ 2));
    } else {
    dmg = (getAtk() / 2) + (rand() % (getAtk()/2)) + 1;
    }
    if (rage > 0) {
        dmg += (rage / 2);
        std::cout << getName() << " attacks " << target.getName() << " with an enraged strike!\n";
        std::cout << "Dealed " << dmg << " damage!\n";
        target.takeDamage(dmg);
        rage -= 3;
    } else {
        std::cout << getName() << " is too exhausted... his damage is halved!\n";
        int dmg = getAtk() / 2;
        std::cout << getName() << " attacks " << target.getName() << " with a weak strike!\n";
        std::cout << "Dealed " << dmg << " damage!\n";
        target.takeDamage(dmg);
    }
}
bool warrior::isAlive() {
    return getCurrentHP() > 0;
}
void warrior::print() const {
    combatUnit::print();
    std::cout << "Class attributes: " << "\n";
    std::cout << "Rage: " << rage << "\n";
    printBarHP();
    std::cout << "\n";
}