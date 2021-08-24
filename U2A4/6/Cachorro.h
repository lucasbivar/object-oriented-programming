#ifndef CACHORRO_H
#define CACHORRO_H

#include "Animal.h"

#include <string>
using std::string;

class Cachorro: public Animal {
public:
  Cachorro();
  Cachorro(string);

  string late() const;
};

#endif