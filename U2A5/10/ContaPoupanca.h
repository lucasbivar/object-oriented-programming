#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include <string>
using std::string;

#include "Conta.h"

class ContaPoupanca : public Conta {
public:
  ContaPoupanca(string="", string="", int=10);

  virtual bool deposito(double=0);
  virtual bool retirada(double=0);
  virtual void imprimirExtrato() const;
  
private:
  int diaDeAniversario; 
};

#endif
