#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class monster
{
private:
  std::string monstername;
  int HP;


public:
  monster();
  monster(std::string name,int health);
  ~monster();

  void dealdamage(int damage);

  std::string getname();
  int gethp();
};

#endif // MONSTER_H
