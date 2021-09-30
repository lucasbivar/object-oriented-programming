#include "../../include/Pessoa/PessoaFisica.h"

#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

PessoaFisica::PessoaFisica(const char* nome, const char* email, const char* cpf, const char* dataDeNascimento, const char* estadoCivil)
  : Pessoa(nome, email){
    strcpy(this->CPF, cpf);
    strcpy(this->dataDeNascimento, dataDeNascimento);
    strcpy(this->estadoCivil, estadoCivil);
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

const char* PessoaFisica::getCPF() const {
  return CPF;
}

void PessoaFisica::setCPF(const char* CPF) {
  //TODO: VALIDAR CPF
  strcpy(this->CPF, CPF);
}

const char* PessoaFisica::getDataDeNascimento() const {
  return dataDeNascimento;
}

void PessoaFisica::setDataDeNascimento(const char* dataDeNascimento) {
  strcpy(this->dataDeNascimento, dataDeNascimento);
}

const char* PessoaFisica::getEstadoCivil() const {
  return estadoCivil;
}

void PessoaFisica::setEstadoCivil(const char* estadoCivil) {
  //TODO: VALIDAR ESTADO CIVIL (3 TIPOS)
  strcpy(this->estadoCivil, estadoCivil);
}


