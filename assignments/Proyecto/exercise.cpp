#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>

void loadArmy(std::vector<std::unique_ptr<combatUnit>>& army, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error while trying to open file: " + filename);
    }
    std::string type, name;
    int maxHP, atk, lvl, special;

    while (file >> type >> name >> maxHP >> atk >> lvl >> special) {
        if (type == "warrior") {
            army.push_back(std::make_unique<warrior>(name, maxHP, atk, lvl, special));
        } else if (type == "archer") {
            army.push_back(std::make_unique<archer>(name, maxHP, atk, lvl, special));
        } else if (type == "wizard") {
            army.push_back(std::make_unique<wizard>(name, maxHP, atk, lvl, special));
        } else {
            throw std::runtime_error("Unknown unit type: " + type);
        }
    }
    if (army.size() < 5) {
        throw std::runtime_error("The army should have at least 5 units.");
    }
}

void displayArmy(const std::vector<std::unique_ptr<combatUnit>>& army, const std::string& armyName) {
    std::cout << "=== " << armyName << " ===" << std::endl;
    for (const auto& unit : army) {
        unit -> print();
    }
}

void singleCombat(std::unique_ptr<combatUnit>& unit1, std::unique_ptr<combatUnit>& unit2) {
    std::cout << "\n=== DEATHMATCH! ===\n";
    std::cout << unit1 -> getName() << " (Lvl " << unit1 -> getLvl() << ") vs " 
              << unit2 -> getName() << " (Lvl " << unit2 -> getLvl() << ")\n";

    while (unit1 -> isAlive() && unit2 -> isAlive()) {
        unit1 -> attack(*unit2);
        if (!unit2 -> isAlive()) break;
        unit2 -> attack(*unit1);
    }
    if (unit1 -> isAlive()) {
        std::cout << unit1 -> getName() << " has won the match!\n";
    } else {
        std::cout << unit2 -> getName() << " has won the match!\n";
    }
}

void simWar(std::vector<std::unique_ptr<combatUnit>>& army1, std::vector<std::unique_ptr<combatUnit>>& army2) {
    
    int round = 1;

    while (!army1.empty() && !army2.empty()) {
        std::cout << "\n=== ROUND " << round++ << " ===\n";
        
        // Seleccionar un combatiente aleatorio de cada ejercito
        int index1 = rand() % army1.size();
        int index2 = rand() % army2.size();
        
        auto& fighter1 = army1[index1];
        auto& fighter2 = army2[index2];
        
        while (fighter1 -> isAlive() && fighter2 -> isAlive()) {
            singleCombat(fighter1, fighter2);
        }
        if (!fighter1 -> isAlive()) {
            std::cout << fighter1 -> getName() << " has fallen in combat.\n";
            army1.erase(army1.begin() + index1);
        }
        if (!fighter2 -> isAlive()) {
            std::cout << fighter2 -> getName() << " has fallen in combat.\n";
            army2.erase(army2.begin() + index2);
        }
        std::cout << "\n=== State of armies ===\n";
        displayArmy(army1, "Army 1");
        displayArmy(army2, "Army 2");

        round++;
    }
    std::cout << "\n=== Battle ended ===\n";
    if (army1.empty() && army2.empty()) {
        std::cout << "Both armies have been slaughtered!\n";
    } else if (army1.empty()) {
        std::cout << "Army 2 has won the war!\n";
        for (const auto& unit : army2) {
            std::cout << "- " << unit -> getName() << " (" << unit -> getType() << ")\n";
        }
    } else {
        std::cout << "Army 1 has won the war!\n";
        for (const auto& unit : army1) {
            std::cout << "- " << unit -> getName() << " (" << unit -> getType() << ")\n";
        }
    }
}

int main() {
    std::srand(std::time(0));
    
    std::vector<std::unique_ptr<combatUnit>> army1;
    std::vector<std::unique_ptr<combatUnit>> army2;

    try {
        loadArmy(army1, "army1.txt");
        loadArmy(army2, "army2.txt");

        displayArmy(army1, "Army 1");
        displayArmy(army2, "Army 2");

        simWar(army1, army2);

    } catch (const std::runtime_error& e) {
        std::cerr << "Error while loading army: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;

}