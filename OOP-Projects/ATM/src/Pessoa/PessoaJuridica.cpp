#include "../../include/Pessoa/PessoaJuridica.h"

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;


PessoaJuridica::PessoaJuridica(const char* nome, const char* email, 
  const char* cnpj, const char* inscricaoEstadual, const char* razaoSocial)
  : Pessoa(nome, email){
    this->setCNPJ(cnpj);
    this->setInscricaoEstadual(inscricaoEstadual);
    this->setRazaoSocial(razaoSocial);
}
    
void PessoaJuridica::exibirPessoa() const {
  cout << "-----------------------------------------" << endl;
  cout << "Nome               - " << this->getNome() << endl;
  cout << "Email              - " << this->getEmail() << endl;
  cout << "CNPJ               - " << this->getCNPJ()  << endl;
  cout << "Inscrição Estadual - " << this->getInscricaoEstadual() << endl;
  cout << "Razão Social       - " << this->getRazaoSocial() << endl;
  cout << "-----------------------------------------" << endl;
}

const char* PessoaJuridica::getCNPJ() const {
  return CNPJ;
}

void PessoaJuridica::setCNPJ(const char* CNPJ) {
  strcpy(this->CNPJ, CNPJ);
}

const char* PessoaJuridica::getInscricaoEstadual() const {
  return inscricaoEstadual;
}

void PessoaJuridica::setInscricaoEstadual(const char* inscricaoEstadual) {
  strcpy(this->inscricaoEstadual, inscricaoEstadual);
}

const char* PessoaJuridica::getRazaoSocial() const {
  return razaoSocial;
}

void PessoaJuridica::setRazaoSocial(const char* razaoSocial) {
  strcpy(this->razaoSocial, razaoSocial);
}
