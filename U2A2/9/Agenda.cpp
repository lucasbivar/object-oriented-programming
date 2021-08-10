#include "Pessoa.h"
#include "Agenda.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

Agenda::Agenda(){
  quantidadePessoas = 0;
}

void Agenda::armazenaPessoa(string nome, int idade, float altura){
  armazenaPessoa(Pessoa(nome, idade, altura));
}

void Agenda::armazenaPessoa(const Pessoa &p){
  if (quantidadePessoas < 10){
    pessoas[quantidadePessoas++] = p;
  }else{
    cout << "Agenda Lotada!" << endl;
  }
}

void Agenda::removePessoa(string nome){
  int posicaoPessoa = buscaPessoa(nome);

  if(posicaoPessoa != -1){
    for(int i = posicaoPessoa; i < quantidadePessoas; i++){
      pessoas[i-1] = pessoas[i];
    }
    quantidadePessoas--;
  }else{
    cout << "Pessoa não encontrada." << endl;
  }
}

int Agenda::buscaPessoa(string nome) const {
  for(int i = 0; i < quantidadePessoas; i++){
    if(pessoas[i].getName() == nome) return i+1;
  }
  return -1;
} 

void Agenda::imprimePovo() const {
  for(int i = 0; i < quantidadePessoas; i++){
    pessoas[i].showPerson();
  }
}

void Agenda::imprimePessoa(int i) const {
  if(i > 0 && i < 11){
    pessoas[i-1].showPerson();
  }
}