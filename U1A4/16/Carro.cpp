#include <iostream>
using std::cout;
using std::endl;

#include "Carro.h"


Carro::Carro(string nome, int anoDoCarro){ 
  setMarca(nome);
  setAno(anoDoCarro);
}

void Carro::setMarca(string nome){
  if (nome == "")
    marca = "\"Sem Marca\"";
  else if (nome.length() > 10)
    marca = nome.substr(0,10);
  else
    marca = nome;
}

string Carro::getMarca(){
  return marca;
}

void Carro::setAno(int anoDoCarro){
  ano = anoDoCarro;
}

int Carro::getAno(){
  return ano;
}

void Carro::displayMessage(){
  cout << "Olá, eu sou um carro da marca " << getMarca() 
  << " e sou do ano de " << getAno() << endl;
}
