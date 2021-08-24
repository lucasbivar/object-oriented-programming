#include "Gato.h"

Gato::Gato() : Animal(){
  //
}

Gato::Gato(string nome) : Animal(nome){
  //
}

string Gato::mia() const {
  return "O gato está miando!";
}