//Genera la implementación de la clase base Personaje
#include "Personaje.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Constructores
int combatUnit::unitCounter = 0;

combatUnit::combatUnit()
    : name("Default Unit " + std::to_string(id = ++unitCounter)), maxHP(100), currentHP(100), atk(20), lvl(1) {}

combatUnit::combatUnit(std::string name, int maxHP, int atk, int lvl)
    : name(name), maxHP(maxHP), currentHP(maxHP), atk(atk), lvl(lvl) {}

// Getters y Setters
std::string combatUnit::getName() const {
    return name;
}
int combatUnit::getMaxHP() const {
    return maxHP;
}
int combatUnit::getCurrentHP() const {
    return currentHP;
}
int combatUnit::getAtk() const {
    return atk;
}
int combatUnit::getLvl() const {
    return lvl;
}
void combatUnit::setMaxHP(int maxHP) {
    if(maxHP > 0) {maxHP = maxHP;}
    if(currentHP > maxHP) {currentHP = maxHP;}
}
void combatUnit::setCurrentHP(int currentHP) {
    if(currentHP > 0 && currentHP <= maxHP) {currentHP = currentHP;}
    else if(currentHP <= 0) {currentHP = 0;}
    else {currentHP = maxHP;}
}
void combatUnit::setAtk(int atk) {
    if(atk > 0) {atk = atk;}
}
void combatUnit::setLvl(int lvl) {
    if(lvl > 0) {lvl = lvl;}
}

// Métodos
int combatUnit::percentHP() const {
    return (currentHP * 100) / maxHP;
}
void combatUnit::printBarHP() const {
    int barSize = 50; // Tamaño de la barra
    int filledSize = (currentHP * barSize) / maxHP;
    int emptySize = barSize - filledSize;
    std::cout << "[";
    for (int i = 0; i < filledSize; ++i) {
        std::cout << "=";
    }
    for (int i = 0; i < emptySize; ++i) {
        std::cout << "-";
    }
    std::cout << "] " << percentHP() << "% HP\n";
}
void combatUnit::takeDamage(int damage) {
    currentHP -= damage;
    if (currentHP < 0) {currentHP = 0;}
}
void combatUnit::attack(combatUnit& target) {
    int dmg;
    if (target.getLvl() > lvl) {
        dmg = 1 + (rand() % (atk / 2));
    } else {
        dmg = (atk / 2) + (rand() % (atk/2)) + 1;
    }
    target.takeDamage(dmg);
    std::cout << name << " dealed " << dmg << " damage to " << target.name << "\n";
}
void combatUnit::print() const {

    std::cout << "\n=== " << name << " ===\n";
    std::cout << "Level: " << lvl << "\n";
    std::cout << "Attack: " << atk << "\n";
    std::cout << "HP: " << currentHP << "/" << maxHP << "\n";
    printBarHP();
    std::cout << "\n";
}