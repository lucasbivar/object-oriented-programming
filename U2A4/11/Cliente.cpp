#include "Cliente.h"

#include <iostream>
using std::cout;
using std::ostream;
using std::endl;

ostream& operator<<(ostream& out, const Cliente& client){
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Nome: " << client.getName() << endl;
  cout << "CPF: " << client.getCpf() << endl;
  cout << "Endereco: " << client.getAddress() << endl;
  cout << "Telefone: " << client.getPhone() << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  
  return out;
}

Cliente::Cliente(string name, unsigned long long cpf, string address, unsigned int phone)
 : PessoaFisica(name, cpf){
   setAddress(address);
   setCpf(cpf);
}

void Cliente::setAddress(string address){
  this->address = address;
}

string Cliente::getAddress() const {
  return address;
}

void Cliente::setPhone(unsigned int phone){
  this->phone = phone;
}

unsigned int Cliente::getPhone() const {
  return phone;
}