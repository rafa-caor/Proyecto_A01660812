// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <iostream>
#include <string>

class combatUnit {
private:
    int maxHP;
    int currentHP;
    int atk;
    int lvl;
    static int unitCounter;
    int id;
    std::string name;

public:
    combatUnit();
    combatUnit(std::string name, int maxHP, int atk, int lvl);

    std::string type;
    
    std::string getName() const;
    std::string getType() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    int getAtk() const;
    int getLvl() const;
    void setMaxHP(int maxHP);
    void setCurrentHP(int currentHP);
    void setAtk(int atk);
    void setLvl(int lvl);
    
    int percentHP() const;
    void printBarHP() const;
    void takeDamage(int damage);
    void attack(combatUnit& target);
    void print() const;
};