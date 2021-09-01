#include "PessoaJuridica.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;


PessoaJuridica::PessoaJuridica(string nome, string endereco, string email, 
  unsigned int telefone, string cnpj, string inscricaoEstadual, string razaoSocial)
  : Pessoa(nome, endereco, email, telefone){
    this->cnpj = cnpj;
    this->inscricaoEstadual = inscricaoEstadual;
    this->razaoSocial = razaoSocial;
}
    
void PessoaJuridica::exibirPessoa() const {
  cout << "-----------------------------------------" << endl;
  cout << "Nome               - " << nome << endl;
  cout << "Endereco           - " << endereco << endl;
  cout << "Email              - " << email << endl;
  cout << "Telefone           - " << telefone << endl;
  cout << "CNPJ               - " << cnpj  << endl;
  cout << "Inscrição Estadual - " << inscricaoEstadual << endl;
  cout << "Razão Social       - " << razaoSocial << endl;
  cout << "-----------------------------------------" << endl;
}


string PessoaJuridica::getNome() const {
  return nome;
}

string PessoaJuridica::getCpfOrCnpj() const {
  return cnpj;
}