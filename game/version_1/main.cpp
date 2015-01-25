#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "dialogue.hpp"
#include "creature.hpp"

//New character menu
Creature dialogue_newchar();

int main(void)
{
  Creature player;
  return 0;
}

Creature dialogue_newchar()
{
  //ask for name and class
  std::cout << "Choose your name" << std::endl;
  std::string name;
  std::cin >> name;
  int result = Dialogue (
      "Choose your class", 
      {"Fighter", "Rogue"}).activate();
  switch(result)
  {
    case 1:
      return Creature(name, 35, 20, 10, 5, 10.0, 1, "Fighter");
    case 2:
      return Creature(name, 30, 5, 10, 20, 15.0, 1, "Rogue");
    default:
      return Creature(name, 30, 10, 10, 10, 10.0, 1, "Adventurer");
  }
}
