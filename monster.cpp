#include "monster.h"
#include <string>
#include <iostream>

monster::monster()
{
}

monster::monster(std::string name,int health)
{
  monstername = name;
  HP = health;
}

monster::~monster()
{
}

void monster::dealdamage(int damage)
{
  HP -=damage;
}


std::string monster::getname()
{
  return monstername;
}

int monster::gethp()
{
  return HP;
}

