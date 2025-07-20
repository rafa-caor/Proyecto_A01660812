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

int main() {
    std::srand(std::time(0));
    
    std::vector<std::unique_ptr<combatUnit>> unidades;
    
    unidades.push_back(std::make_unique<warrior>("Red Warrior", 200, 40, 6, 20));
    unidades.push_back(std::make_unique<archer>("Green Archer", 180, 35, 5, 50));
    unidades.push_back(std::make_unique<wizard>("Blue Wizard", 160, 30, 4, 100));
    
    // Imprimir todos los personajes
    std::cout << "=== Personajes iniciales ===" << std::endl;
    for (const auto& unidad : unidades) {
        std::cout << *unidad << std::endl;
    }
    
    std::cout << "\n=== Batalla ===" << std::endl;
    
    unidades[0]->attack(*unidades[1]);
    std::cout << *unidades[1] << std::endl;
    
    unidades[1]->attack(*unidades[2]);
    std::cout << *unidades[2] << std::endl;
    
    unidades[2]->attack(*unidades[0]);
    std::cout << *unidades[0] << std::endl;
    
    std::cout << "\n=== Estado final ===" << std::endl;
    for (const auto& unidad : unidades) {
        std::cout << unidad->getName() << " esta " 
                  << (unidad->isAlive() ? "VIVO" : "MUERTO") << std::endl;
    }
    
    std::cout << "\n=== Mostrando Guerrero con operador sobrecargado ===" << std::endl;
    std::cout << *unidades[0] << std::endl;
    
    return 0;
}