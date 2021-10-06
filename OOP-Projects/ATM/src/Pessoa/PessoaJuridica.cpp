#include "../../include/Pessoa/PessoaJuridica.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


PessoaJuridica::PessoaJuridica(string nome, string email, 
  string cnpj, string inscricaoEstadual, string razaoSocial)
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

string PessoaJuridica::getCNPJ() const {
  return CNPJ;
}

void PessoaJuridica::setCNPJ(string CNPJ) {
  this->CNPJ = CNPJ;
}

string PessoaJuridica::getInscricaoEstadual() const {
  return inscricaoEstadual;
}

void PessoaJuridica::setInscricaoEstadual(string inscricaoEstadual) {
  this->inscricaoEstadual = inscricaoEstadual;
}

string PessoaJuridica::getRazaoSocial() const {
  return razaoSocial;
}

void PessoaJuridica::setRazaoSocial(string razaoSocial) {
  this->razaoSocial = razaoSocial;
}
