#include "Animal.h"

Animal::Animal(){

}

Animal::Animal(string nome): nome(nome){
  //
}

string Animal::caminha() const {
  return nome + " está caminhando!";
}