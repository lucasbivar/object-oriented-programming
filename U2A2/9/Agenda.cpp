#include "Pessoa.h"
#include "Agenda.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

Agenda::Agenda(){
  qtdePessoas = 0;
}

void Agenda::armazenaPessoa(string nome, int idade, float altura){
  armazenaPessoa(Pessoa(nome, idade, altura));
}

void Agenda::armazenaPessoa(const Pessoa &p){
  if (qtdePessoas < 10){
    pessoas[qtdePessoas++] = p;
  }else{
    cout << "Agenda Lotada!" << endl;
  }
}

void Agenda::removePessoa(string nome){
  int posicaoPessoa = buscaPessoa(nome);

  if(posicaoPessoa != -1){
    for(int i = posicaoPessoa; i < qtdePessoas; i++){
      pessoas[i-1] = pessoas[i];
    }
    qtdePessoas--;
  }else{
    cout << "Pessoa não encontrada." << endl;
  }
}

int Agenda::buscaPessoa(string nome) const {
  for(int i = 0; i < qtdePessoas; i++){
    if(pessoas[i].getName() == nome) return i+1;
  }
  return -1;
} 

void Agenda::imprimePovo() const {
  for(int i = 0; i < qtdePessoas; i++){
    pessoas[i].showPerson();
  }
}

void Agenda::imprimePessoa(int i) const {
  if(i > 0 && i < 11){
    pessoas[i-1].showPerson();
  }
}