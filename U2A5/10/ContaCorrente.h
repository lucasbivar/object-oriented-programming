#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include <string>
using std::string;

#include "Conta.h"

class ContaCorrente : public Conta {
public:
  ContaCorrente(string="", string="");

  virtual bool deposito(double=0);
  virtual bool retirada(double=0);
  virtual void imprimirExtrato() const;
};

#endif
