#include "Pessoa.h"

#include <iostream>
using std::cout;
using std::endl;

ostream& operator<<(ostream& out, const Pessoa& person) {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Nome: " << person.getName() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  
  return out;
}


Pessoa::Pessoa(string name){
  setName(name);
}

string Pessoa::getName() const {
  return name;
}

void Pessoa::setName(string name){
  this->name = name;
}