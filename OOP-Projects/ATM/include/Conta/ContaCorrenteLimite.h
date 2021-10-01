#ifndef CONTA_CORRENTE_LIMITE_H
#define CONTA_CORRENTE_LIMITE_H

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaCorrenteLimite : public Conta {
public:
  ContaCorrenteLimite(Pessoa* p, double=200);

  virtual void imprimirExtrato() const;
protected:
  virtual void validarRetirada(double valor) const;
private:
  double limite;
};


#endif