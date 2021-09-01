#ifndef CONTA_CORRENTE_LIMITE_H
#define CONTA_CORRENTE_LIMITE_H

#include "Conta.h"

class ContaCorrenteLimite : public Conta {
public:
  ContaCorrenteLimite(string="", string="", double=200);

  virtual bool deposito(double=0);
  virtual bool retirada(double=0);
  virtual void imprimirExtrato() const;

private:
  double limite;
};


#endif