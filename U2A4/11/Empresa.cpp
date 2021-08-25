#include "Empresa.h"
#include "Funcionario.h"
#include "Cliente.h"

#include <iostream>
using std::cout;
using std::endl;

Empresa::Empresa(string name, unsigned long long cnpj, string socialReason) : PessoaJuridica(name, cnpj, socialReason){
  this->quantityOfClients = 0;
  this->quantityOfEmployees = 0;
}

void Empresa::addClient(const Cliente& client) {
  if(quantityOfClients < 10){
    clients[quantityOfClients++] = client;
  }
}

void Empresa::addEmployee(const Funcionario& employee){
  if(quantityOfEmployees < 10){
    employees[quantityOfEmployees++] = employee;
  }
}

void Empresa::showClients() const {
  cout << endl << "-----------------------ALL CLIENTS----------------------" << endl;
  for(unsigned int i = 0; i < quantityOfClients; i++){
    cout << clients[i] << endl;
  }
  cout << "--------------------------------------------------------" << endl << endl;
}

void Empresa::showEmployees() const {
  cout << endl << "-----------------------ALL EMPLOYEES----------------------" << endl;
  for(unsigned int i = 0; i < quantityOfEmployees; i++){
    cout << employees[i] << endl;
  }
  cout << "----------------------------------------------------------" << endl << endl;
}

double Empresa::calculatePaymentSheet() const {
  double salarySum = 0;
  for(unsigned int i = 0; i < quantityOfEmployees; i++){
    salarySum += employees[i].calculateGrossSalary();
  }
  return salarySum;
}