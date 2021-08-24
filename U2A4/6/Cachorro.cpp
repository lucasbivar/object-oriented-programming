#include "Cachorro.h"

Cachorro::Cachorro() : Animal(){
  //
}

Cachorro::Cachorro(string nome) : Animal(nome){
  //
}

string Cachorro::late() const {
  return "O cachorro está latindo!";
}