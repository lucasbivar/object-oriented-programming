#ifndef CONTA_H
#define CONTA_H

#include <string>
using std::string;

#include "Transacao.h"

#include <list>
using std::list;

class Conta {
public:

  Conta(string="", string="");

  virtual bool deposito(double=0) = 0;
  virtual bool retirada(double=0) = 0;
  virtual void imprimirExtrato() const = 0;

protected:
  string numeroDaConta, nome;
  double saldo;
  list<Transacao> listaDeTransacoes;
};

#endif