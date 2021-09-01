#include "PessoaFisica.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

PessoaFisica::PessoaFisica(string nome, string endereco, string email, 
  unsigned int telefone, string cpf, string dataDeNascimento, string estadoCivil)
  : Pessoa(nome, endereco, email, telefone){
    this->cpf = cpf;
    this->dataDeNascimento = dataDeNascimento;
    this->estadoCivil = estadoCivil;
}
    
void PessoaFisica::exibirPessoa() const {
  cout << "-----------------------------------------" << endl;
  cout << "Nome               - " << nome << endl;
  cout << "Endereco           - " << endereco << endl;
  cout << "Email              - " << email << endl;
  cout << "Telefone           - " << telefone << endl;
  cout << "CPF                - " << cpf  << endl;
  cout << "Data de Nascimento - " << dataDeNascimento << endl;
  cout << "Estado Civil       - " << estadoCivil << endl;
  cout << "-----------------------------------------" << endl;
}

string PessoaFisica::getNome() const {
  return nome;
}

string PessoaFisica::getCpfOrCnpj() const {
  return cpf;
}
