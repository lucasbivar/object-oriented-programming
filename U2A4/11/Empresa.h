#ifndef EMPRESA_H
#define EMPRESA_G

#include "PessoaJuridica.h"
#include "Funcionario.h"
#include "Cliente.h"

class Empresa : public PessoaJuridica {
public:
  Empresa(string="", unsigned long long=0, string="");

  void addClient(const Cliente&);
  void addEmployee(const Funcionario&);

  void showClients() const;
  void showEmployees() const;

  double calculatePaymentSheet() const;
private:
  Cliente clients[10];
  unsigned int quantityOfClients;
  Funcionario employees[10];
  unsigned int quantityOfEmployees;
};

#endif