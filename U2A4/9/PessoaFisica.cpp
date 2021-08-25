#include "PessoaFisica.h"

PessoaFisica::PessoaFisica(string name, unsigned long long cpf) : Pessoa(name) {
  setCpf(cpf);
} 

void PessoaFisica::setCpf(unsigned long long cpf){
  this->cpf = cpf;
}

unsigned long long PessoaFisica::getCpf() const {
  return cpf;
}
