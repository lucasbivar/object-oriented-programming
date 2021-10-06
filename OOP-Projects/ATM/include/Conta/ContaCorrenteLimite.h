#ifndef CONTA_CORRENTE_LIMITE_H
#define CONTA_CORRENTE_LIMITE_H

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaCorrenteLimite : public Conta {
public:
  ContaCorrenteLimite(Pessoa* p, string prefixoConta, string prefixoPessoa, double=200);

  virtual void imprimirExtrato() const;
  virtual void mostrarConta() const;

  void setLimite(double);

protected:
  virtual void validarRetirada(double valor) const;
private:
  double limite;
};


#endif