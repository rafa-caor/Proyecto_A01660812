#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main(){
  std::srand(std::time(0));

  combatUnit hero("Hero", 150, 30, 5);
  combatUnit monster("Monster", 120, 25, 3);

  hero.print();
  monster.print();

  std::cout << "Fight!\n";

  hero.attack(monster);
  monster.attack(hero);

  hero.print();
  monster.print();

  combatUnit default1;
  combatUnit default2;;

  default1.print();
  default2.print();

  std::cout << "Fight!\n";

  default1.attack(default2);
  default2.attack(default1);

  default1.print();
  default2.print();

  std::cout << "########## PRUEBA DE HERENCIA ##########\n";

  warrior war1("Red Warrior", 200, 40, 6, 20);
  warrior defWarrior;
  archer arc1("Green Archer", 180, 35, 5, 50);
  archer defArcher;
  wizard wiz1("Blue Wizard", 160, 30, 4, 100);
  wizard defWizard;

  war1.print();
  defWarrior.print();
  arc1.print();
  defArcher.print();
  wiz1.print();
  defWizard.print();

  std::cout << "Las peleas serán entres ambos personajes de cada clase.\n";

  war1.attack(defWarrior);
  defWarrior.attack(war1);

  arc1.attack(defArcher);
  defArcher.attack(arc1);

  wiz1.attack(defWizard);
  defWizard.attack(wiz1);

  war1.print();
  defWarrior.print();
  arc1.print();
  defArcher.print();
  wiz1.print();
  defWizard.print();

  return 0;
}