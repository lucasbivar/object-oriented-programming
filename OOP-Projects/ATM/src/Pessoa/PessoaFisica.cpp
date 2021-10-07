#include "../../include/Pessoa/PessoaFisica.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

PessoaFisica::PessoaFisica(string nome, string email, string cpf, string dataDeNascimento, string estadoCivil)
  : Pessoa(nome, email){
    this->CPF = cpf;
    this->dataDeNascimento = dataDeNascimento;
    this->estadoCivil = estadoCivil;
}
    
void PessoaFisica::exibirPessoa() const {
  cout << "-----------------------------------------" << endl;
  cout << "Nome               - " << this->getNome() << endl;
  cout << "Email              - " << this->getEmail() << endl;
  cout << "CPF                - " << this->getCPF()  << endl;
  cout << "Data de Nascimento - " << this->getDataDeNascimento() << endl;
  cout << "Estado Civil       - " << this->getEstadoCivil() << endl;
  cout << "-----------------------------------------" << endl;
}

string PessoaFisica::getCPF() const {
  return CPF;
}

void PessoaFisica::setCPF(string CPF) {
  this->CPF = CPF;
}

string PessoaFisica::getDataDeNascimento() const {
  return dataDeNascimento;
}

void PessoaFisica::setDataDeNascimento(string dataDeNascimento) {
  this->dataDeNascimento = dataDeNascimento;
}

string PessoaFisica::getEstadoCivil() const {
  return estadoCivil;
}

void PessoaFisica::setEstadoCivil(string estadoCivil) {
  this->estadoCivil = estadoCivil;
}


