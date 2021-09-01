#include "Pessoa.h"

#include<string>
using std::string;

Pessoa::Pessoa(string nome, string endereco, string email, unsigned int telefone){
  this->nome = nome;
  this->endereco = endereco;
  this->email = email;
  this->telefone = telefone;
}

string Pessoa::getNome() const {
  return nome;
}