#ifndef GATO_H
#define GATO_H

#include <string>
using std::string;

#include "Animal.h"

class Gato : public Animal {
public:
  Gato();
  Gato(string);
  string mia() const;
};

#endif