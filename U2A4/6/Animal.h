#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using std::string;

class Animal {
public:
  Animal();
  Animal(string);

  string caminha() const;

private:
  string nome, raca;
};




#endif