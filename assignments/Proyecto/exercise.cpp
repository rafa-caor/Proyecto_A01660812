#include "Personaje.hpp"
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

  return 0;
}