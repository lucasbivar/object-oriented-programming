#ifndef CONTA_CORRENTE_H
#define CONTA_CORRENTE_H

#include <string>
using std::string;

#include "Conta.h"

#include "../Pessoa/Pessoa.h"

class ContaCorrente : public Conta {
public:
  ContaCorrente(Pessoa* p);

  virtual void imprimirExtrato() const;
};

#endif
