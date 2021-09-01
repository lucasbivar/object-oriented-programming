#include "Conta.h"

#include <string>
using std::string;

Conta::Conta(string nome, string numeroDaConta){
  this->nome = nome;
  this->numeroDaConta = numeroDaConta;
  this->saldo = 0;
}