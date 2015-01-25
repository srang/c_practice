#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature
{
  public:
    //Player name
    std::string name;
    //Class eg Rogue, Fighter, Wizard
    std::string vocation;

    int health;          //Current Hit points (10-1000+)
    int maxHealth;       //Max possible Hit Points (10-1000+)
    int strength;        //Determines damage (1-100)
    int endurance;       //Determines max health (1-100)
    int dexterity;       //Determines speed in battle (1-100)
    double hitRate;      //Modifier to hit chance (1-150)
    //Level of creature determines amount of experience it
    //gives when defeated (1-50)
    unsigned int level;
    //Total current experience, affects level. See levelUp()
    //(1-1M)
    unsigned int exp;

    Creature() { }
    Creature(std::string name, int health,
        int str, int end, int dex,
        double hitR, unsigned int level=1,
        std::string vocation="")
    {
      this->name = name;
      this->health = health;
      this->maxHealth = health;
      this->strength = str;
      this->endurance = end;
      this->dexterity = dex;
      this->vocation = vocation;
      this->level = level;
      this->exp = 0;
    }

    unsigned int expToLevel(unsigned int level)
    {
      return 128 * level * level;
    }

    //Level up a creature if it has enough expericence to
    //do so. Returns true if level up and false otherwise
    bool levelUp()
    {
      if(this->exp >= expToLevel(this->level+1))
      {
        ++level;

        unsigned int hlthBoost,strBoost,
                     endBoost,dexBoost = 0;

        if(level % 3 == 0)
        {
          hlthBoost = 10 + (rand() % 4) + this->endurance / 4;
        }
        else
        {
          hlthBoost = this->endurance / 4;
        }
        //stat increase determined by class
        if(this->vocation == "Fighter")
        {
          strBoost=1;
          endBoost=1;
          if(rand() % 2 == 0) dexBoost = 1;
        }
        else if(this->vocation == "Rogue")
        {
          endBoost = 1;
          dexBoost = 1;
          if(rand() % 2 == 0) strBoost = 1;
        }
        this->maxHealth += hlthBoost;
        this->strength += strBoost;
        this->endurance += endBoost;
        this->dexterity += dexBoost;

        std::cout << this->name << " grew to level "
          << level << "!\n";
        std::cout << "Health +" << hlthBoost << " -> "
          << this->maxHealth << std::endl;
        std::cout << "Strength +" << strBoost << " -> "
          << this->strength << std::endl;
        std::cout << "Endurance +" << endBoost << " -> "
          << this->endurance << std::endl;
        std::cout << "Dexterity +" << dexBoost << " -> "
          << this->dexterity << std::endl;
        std::cout << "------------------\n";
        return true;
      }
      return false;
};
#endif /* CREATURE_HPP */
