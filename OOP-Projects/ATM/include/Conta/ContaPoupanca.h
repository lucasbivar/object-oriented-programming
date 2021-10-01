#ifndef CONTA_POUPANCA_H
#define CONTA_POUPANCA_H

#include <string>
using std::string;

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaPoupanca : public Conta {
public:
  ContaPoupanca(Pessoa* p, int=10);

  virtual void imprimirExtrato() const;
  
private:
  int diaDeAniversario; 
};

#endif
