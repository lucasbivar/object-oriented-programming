#ifndef CONTA_CORRENTE_LIMITE_H
#define CONTA_CORRENTE_LIMITE_H

#include "Conta.h"

#include "../Pessoa/Pessoa.h"


#include <string>
using std::string;

class ContaCorrenteLimite : public Conta {
public:
  ContaCorrenteLimite(Pessoa* p=nullptr, string prefixoConta="", string prefixoPessoa="", 
                      double limite=200, double saldo=0, string numeroDaConta="",
                      list<Transacao> transacoes=list<Transacao>());


  virtual void imprimirExtrato() const;
  virtual void mostrarConta() const;

  void setLimite(double);
  double getLimite() const;

protected:
  virtual void validarRetirada(double valor) const;
private:
  double limite;
};


#endif