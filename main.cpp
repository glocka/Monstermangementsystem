#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "monster.h"


int main()
{
  std::vector<monster> Monstersdb;
  while(true)
  {
    std::vector<std::string> parameters;
    std::string input;
    std::string part;


    std::cout << "Monster> ";
    getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> part)
    {
      parameters.push_back(part);
    }

    if (parameters.size() != 0)
    {
      if (parameters[0] == "quit")
      {
       return 0;
      }

      if (parameters[0] == "spawn")
      {
        if(parameters.size() == 3)
        {
          monster acc(parameters[1],std::stoi(parameters[2]));
          Monstersdb.push_back(acc);
        }
      }


      if (parameters[0] == "list")
      {
        if(parameters.size() == 1 && Monstersdb.size()!=0)
        {
          for(unsigned int i = 0; i< Monstersdb.size();i++)
          {
            std::cout<<Monstersdb[i].getname()<<":"<<Monstersdb[i].gethp()<<std::endl;
          }
        }
      }

      if (parameters[0] == "damage")
      {
        if(parameters.size() == 2 && Monstersdb.size()!=0)
        {
          for (unsigned int i = 0; i < Monstersdb.size();i++)
          {
            Monstersdb[i].dealdamage(std::stoi(parameters[1]));

            if (Monstersdb[i].gethp() <= 0)
            {
              std::cout << Monstersdb[i].getname()<<" is removed!"<<std::endl;
              Monstersdb.erase((Monstersdb.begin()+i));
              i--;
            }
          }
        }
      }
    }
  }
  return 0;
}

